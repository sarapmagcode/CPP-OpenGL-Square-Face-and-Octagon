#define GLEW_STATIC

#include<GL/glew.h>
#include<GL/glut.h>
#include <GL/freeglut_ext.h>
#include<iostream>

using namespace std;

void display();
void head();
void body();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display);
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glutMainLoop();
	} else {
		cout << "Error in initializing GLEW extension library...";
	}
	return 0;
}

void head() {
	GLfloat headVertices[] = {
		-0.4f, 0.0f, 0.0f, // structure of the head
		-0.4f, 0.8f, 0.0f,
		0.4f, 0.8f, 0.0f,
		0.4f, 0.0f, 0.0f,
		
		-0.15, 0.3f, 0.0f, // nose
		0.0f, 0.55f, 0.0f,
		0.15f, 0.3f, 0.0f,
		
		-0.2f, 0.18f, 0.0f, // mouth
		0.2f, 0.18f, 0.0f,
		
		-0.20f, 0.65, 0.0f, // eyes
		0.22f, 0.65, 0.0f,
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, headVertices);
	
	// whole head
	glColor3ub(19, 148, 135);
	glDrawArrays(GL_QUADS, 0, 4);
	
	// triangle nose
	glColor3ub(247, 124, 90);
	glDrawArrays(GL_TRIANGLES, 4, 3);
	
	// horizontal mouth
	glLineWidth(2.0);
	glColor3ub(255, 241, 206);
	glDrawArrays(GL_LINES, 7, 2);
	
	// two eyes
	glPointSize(30.0);
	glDrawArrays(GL_POINTS, 9, 2);
	
	glDisableClientState(GL_VERTEX_ARRAY);
}

void body() {
	GLfloat bodyVertices[] = {
		-0.2f, -0.8f, 0.0f,
		-0.4f, -0.55f, 0.0f,
		-0.4f, -0.25f, 0.0f,
		-0.2f, 0.0f, 0.0f,
		0.2f, 0.0f, 0.0f,
		0.4f, -0.25f, 0.0f,
		0.4f, -0.55f, 0.0f,
		0.2f, -0.8f, 0.0f
	};
	
	GLuint VBOid;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 24, bodyVertices, GL_STATIC_DRAW);
	
	// bind body
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	
	// draw octagon
	glDrawArrays(GL_POLYGON, 0, 8);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	head();
	glColor3ub(210, 157, 43);
	body();
	glFlush();
}
