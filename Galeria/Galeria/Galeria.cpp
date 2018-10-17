#include <windows.h>
#include <stdio.h>
#include <SOIL.h>
#include <GL/GLUT.h>
#include <GL/GLU.h>  
#include <stdlib.h>
#include <math.h>


float xrot=0;
float yrot=0;
float xpos=0;
float zpos=-2;
float forgoszog=0;
float forgospd=0;
bool nappal=true;
bool help=false;
float ambientvalue=1.0f;
GLfloat light_position[] = {0.0f, 0.5f, 0.0f, 1.0f };
GLfloat cut[]= {70.0f};
GLfloat spotdir[]= {0.0f,-1.0f,0.0f};
GLfloat light_ambient[]={0.8f,0.8f,0.8f,1.0f};
GLfloat light_diffuse[]={0.0f,0.0f,0.0f,1.0f};
GLfloat light_specular[]={0.0f,0.0f,0.0f,1.0f};
bool light=true;
GLuint texture[60];


bool LoadGLTextures()                                    // Load Bitmaps And Convert To Textures
{
    /* load an image file directly as a new OpenGL texture */
    texture[0] = SOIL_load_OGL_texture
        (
		"Data/padlora.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[0] == 0)
        return false;
 
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
	//-----------------------------------------------------------------
	
	texture[1] = SOIL_load_OGL_texture
        (
        "Data/tapeta.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[1] == 0)
        return false;
 
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[2] = SOIL_load_OGL_texture
        (
        "Data/plafon2.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[2] == 0)
        return false;
 
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[3] = SOIL_load_OGL_texture
        (
		"Data/wb.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[3] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[4] = SOIL_load_OGL_texture
        (
        "Data/portre1_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[4] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[5] = SOIL_load_OGL_texture
        (
        "Data/tegla.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[5] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[6] = SOIL_load_OGL_texture
        (
        "Data/alaprajz.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[6] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[7] = SOIL_load_OGL_texture
        (
        "Data/help2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[7] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[8] = SOIL_load_OGL_texture
        (
        "Data/elsoajto.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[8] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[8]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[9] = SOIL_load_OGL_texture
        (
        "Data/exit.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[9] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[9]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[10] = SOIL_load_OGL_texture
        (
        "Data/vault-door.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[10] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	
	//-----------------------------------------------------------------

	texture[11] = SOIL_load_OGL_texture
        (
        "Data/monal.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[11] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[11]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[12] = SOIL_load_OGL_texture
        (
        "Data/kepkeretszin.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[12] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[12]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[13] = SOIL_load_OGL_texture
        (
        "Data/vangogh.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[13] == 0)
        return false;

    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[13]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	texture[14] = SOIL_load_OGL_texture
        (
        "Data/help2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );

	if(texture[14] == 0)
      return false;

    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[14]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	// load an image file directly as a new OpenGL texture 
    texture[15] = SOIL_load_OGL_texture
        (
        "Data/kepkeretszin2.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[15] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[15]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 
	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[16] = SOIL_load_OGL_texture
        (
        "Data/1.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[16] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[16]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
	 //return true; 

	 //-----------------------------------------------------------------

	 /* load an image file directly as a new OpenGL texture */
    texture[17] = SOIL_load_OGL_texture
        (
        "Data/2.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[17] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[17]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
	 //return true; 

	//-----------------------------------------------------------------

	 /* load an image file directly as a new OpenGL texture */
    texture[18] = SOIL_load_OGL_texture
        (
        "Data/3.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[18] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[18]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[19] = SOIL_load_OGL_texture
        (
        "Data/4.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[19] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[19]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
	 //return true; 

	//-----------------------------------------------------------------

	 /* load an image file directly as a new OpenGL texture */
    texture[20] = SOIL_load_OGL_texture
        (
        "Data/alulra.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[20] == 0)
        return false;
 
    // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[20]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
   
	 //return true; 

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[21] = SOIL_load_OGL_texture
        (
        "Data/fem.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[21] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[21]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[22] = SOIL_load_OGL_texture
        (
        "Data/asztal.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[22] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[22]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[23] = SOIL_load_OGL_texture
        (
        "Data/utolsó_vacsora.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[23] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[23]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[24] = SOIL_load_OGL_texture
        (
        "Data/vacsora_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[24] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[24]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[25] = SOIL_load_OGL_texture
        (
        "Data/maid.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[25] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[25]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[26] = SOIL_load_OGL_texture
        (
        "Data/maid_keret_szin.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[26] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[26]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[27] = SOIL_load_OGL_texture
        (
        "Data/tajkep1.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[27] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[27]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[28] = SOIL_load_OGL_texture
        (
        "Data/tajkep1_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[28] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[28]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[29] = SOIL_load_OGL_texture
        (
        "Data/tajkep2_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[29] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[29]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[30] = SOIL_load_OGL_texture
        (
        "Data/tajkep2.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[30] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[30]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[31] = SOIL_load_OGL_texture
        (
        "Data/tajkep3.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[31] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[31]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[32] = SOIL_load_OGL_texture
        (
        "Data/tajkep4_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[32] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[32]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[33] = SOIL_load_OGL_texture
        (
        "Data/tajkep4.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[33] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[33]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[34] = SOIL_load_OGL_texture
        (
        "Data/sikoly_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[34] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[34]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[35] = SOIL_load_OGL_texture
        (
        "Data/sikoly.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[35] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[35]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[36] = SOIL_load_OGL_texture
        (
        "Data/tajkep5_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[36] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[36]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[37] = SOIL_load_OGL_texture
        (
        "Data/tajkep5.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[37] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[37]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[38] = SOIL_load_OGL_texture
        (
        "Data/tajkep6_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[38] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[38]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[39] = SOIL_load_OGL_texture
        (
        "Data/tajkep6.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[39] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[39]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[40] = SOIL_load_OGL_texture
        (
        "Data/portre1.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[40] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[40]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[41] = SOIL_load_OGL_texture
        (
        "Data/utca1.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[41] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[41]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[42] = SOIL_load_OGL_texture
        (
        "Data/utca2_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[42] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[42]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[43] = SOIL_load_OGL_texture
        (
        "Data/utca2.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[43] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[43]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[44] = SOIL_load_OGL_texture
        (
        "Data/tajkep7_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[44] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[44]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[45] = SOIL_load_OGL_texture
        (
        "Data/tajkep7.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[45] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[45]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[46] = SOIL_load_OGL_texture
        (
        "Data/tajkep4_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[46] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[46]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[47] = SOIL_load_OGL_texture
        (
        "Data/tajkep8.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[47] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[47]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[48] = SOIL_load_OGL_texture
        (
        "Data/tajkep9.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[48] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[48]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[49] = SOIL_load_OGL_texture
        (
        "Data/festmeny1_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[49] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[49]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[50] = SOIL_load_OGL_texture
        (
        "Data/festmeny1.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[50] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[50]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[51] = SOIL_load_OGL_texture
        (
        "Data/festmeny2_keret.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[51] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[51]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[52] = SOIL_load_OGL_texture
        (
        "Data/festmeny2.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[52] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[52]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	//-----------------------------------------------------------------

	/* load an image file directly as a new OpenGL texture */
    texture[53] = SOIL_load_OGL_texture
        (
        "Data/festmeny_hatulja.bmp",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MULTIPLY_ALPHA
        );
    
    if(texture[53] == 0)
        return false;

	// Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture[53]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);

	 
}

void kocka()
{
	// elölrõl
	glBindTexture(GL_TEXTURE_2D,texture[16]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.8f,-54.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.8f,-54.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,2.5f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,2.5f,-54.0f);
	glEnd();

	// hátulról
	glBindTexture(GL_TEXTURE_2D,texture[18]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,2.5f,-56.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,2.5f,-56.0f);
	glEnd();

	// jobbról
	glBindTexture(GL_TEXTURE_2D,texture[17]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.8f, -54.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,2.5f,-56.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,2.5f, -54.0f);
	glEnd();

	// balról
	glBindTexture(GL_TEXTURE_2D,texture[19]);
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.8f,-54.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,2.5f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,2.5f,-56.0f);
	glEnd();

	// alulról
	glBindTexture(GL_TEXTURE_2D,texture[20]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.8f,-56.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,0.8f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,0.8f,-54.0f);
	glEnd();
}

static void display(void)
{
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	float sceneroty = 360.0f - yrot;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	forgoszog+=0.5f;

    glLoadIdentity() ;
	glEnable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_2D);
	
    glRotatef(sceneroty,0.0f,1.0f,0.0f);
	
	glTranslatef ( xpos, 0.0, zpos);

	//-----------------------------------------------------------------

	// Forgó kocka
	glPushMatrix();
	glTranslatef (0.0f, 0.0f, -55.0f);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glRotatef(forgoszog,0.0f,1.0f,0.0f);
	glTranslatef (0.0f, 0.0f, 55.0f);
	kocka();
	glPopMatrix();
	glPopMatrix();

	//-----------------------------------------------------------------

	glPushMatrix();
	glTranslatef(8.0f, 3.0f, 0.0f);
	glLightfv(GL_LIGHT0, GL_POSITION,  light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR,  light_specular);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);
	
	//-----------------------------------------------------------------
	
	// padló
	glColor4f(1.0f,1.0f,1.0f,1.0f);
	glBindTexture(GL_TEXTURE_2D,texture[0]);

	glBegin(GL_QUADS);
    glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,-1.0f,10.0f);
	glTexCoord2f(50.0f,0.0f);glVertex3f(18.0f,-1.0f,10.0f);
	glTexCoord2f(50.0f,50.0f);glVertex3f(18.0f,-1.0f,-75.0f);
	glTexCoord2f(0.0f,50.0f);glVertex3f(-18.0f,-1.0f,-75.0f);
	glEnd();

	//-----------------------------------------------------------------

	// plafon
	glBindTexture(GL_TEXTURE_2D,texture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,4.5f,-75.0f);
	glTexCoord2f(26.0f,0.0f);glVertex3f(18.0f,4.5f,-75.0f);
	glTexCoord2f(26.0f,26.0f);glVertex3f(18.0f,4.5f,10.0f);
	glTexCoord2f(0.f,26.0f);glVertex3f(-18.0f,4.5f,10.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Szoba fala
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[3]);

	// bal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,-1.0f,10.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(-18.0f,-1.0f,-75.0f);
	glTexCoord2f(5.0f,2.0f);glVertex3f(-18.0f,4.5f,-75.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-18.0f,4.5f,10.0f);
	glEnd();

	// jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(18.0f,-1.0f,-75.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(18.0f,-1.0f,10.0f);
	glTexCoord2f(5.0f,2.0f);glVertex3f(18.0f,4.5f,10.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(18.0f,4.5f,-75.0f);
	glEnd();

	// Elsõ - bal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(18.0f,-1.0f,10.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(2.0f,-1.0f,10.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(2.0f,4.5f,10.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(18.0f,4.5f,10.0f);
	glEnd();

	// Elsõ - közép - belül (ezen van az ajtó)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(2.0f,-1.0f,10.5f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-2.0f,-1.0f,10.5f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-2.0f,4.5f,10.5f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(2.0f,4.5f,10.5f);
	glEnd();

	// Elsõ - közép - felül (ezen van az exit felirat)
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(2.0f,2.5f,10.0f);
	glTexCoord2f(0.7f,0.0f);glVertex3f(-2.0f,2.5f,10.0f);
	glTexCoord2f(0.7f,0.7f);glVertex3f(-2.0f,4.5f,10.0f);
	glTexCoord2f(0.0f,0.7f);glVertex3f(2.0f,4.5f,10.0f);
	glEnd();

	// Elsõ - közép - bal keret
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(2.0f,-1.0f,10.0f);
	glTexCoord2f(1.5f,0.0f);glVertex3f(2.0f,-1.0f,10.5f);
	glTexCoord2f(1.5f,1.5f);glVertex3f(2.0f,4.5f,10.5f);
	glTexCoord2f(0.0f,1.5f);glVertex3f(2.0f,4.5f,10.0f);
	glEnd();

	// Elsõ - közép - jobb keret
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.0f,-1.0f,10.5f);
	glTexCoord2f(1.5f,0.0f);glVertex3f(-2.0f,-1.0f,10.0f);
	glTexCoord2f(1.5f,1.5f);glVertex3f(-2.0f,4.5f,10.0f);
	glTexCoord2f(0.0f,1.5f);glVertex3f(-2.0f,4.5f,10.5f);
	glEnd();

	// Elsõ - közép - alsó keret
	glBindTexture(GL_TEXTURE_2D,texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.0f,-1.0f,10.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(2.0f,-1.0f,10.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(2.0f,-1.0f,10.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-2.0f,-1.0f,10.0f);
	glEnd();

	// Elsõ - közép - felsõ keret
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.0f,2.5f,10.0f);
	glTexCoord2f(0.5f,0.0f);glVertex3f(2.0f,2.5f,10.0f);
	glTexCoord2f(0.5f,0.5f);glVertex3f(2.0f,2.5f,10.5f);
	glTexCoord2f(0.0f,0.5f);glVertex3f(-2.0f,2.5f,10.5f);
	glEnd();

	// Elsõ - jobb
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.0f,-1.0f,10.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-18.0f,-1.0f,10.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-18.0f,4.5f,10.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-2.0f,4.5f,10.0f);
	glEnd();

	// hátsó - bal
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,-1.0f,-75.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-2.5f,-1.0f,-75.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-2.5f,4.5f,-75.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-18.0f,4.5f,-75.0f);
	glEnd();

	// hátsó - közép (ezen van az ajtó)
	glBindTexture(GL_TEXTURE_2D,texture[10]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,-1.0f,-74.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(3.0f,-1.0f,-74.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(3.0f,2.5f,-74.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-2.5f,2.5f,-74.5f);
	glEnd();

	// hátsó - közép felül
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,2.5f,-75.0f);
	glTexCoord2f(0.7f,0.0f);glVertex3f(3.0f,2.5f,-75.0f);
	glTexCoord2f(0.7f,0.7f);glVertex3f(3.0f,4.5f,-75.0f);
	glTexCoord2f(0.0f,0.7f);glVertex3f(-2.5f,4.5f,-75.0f);
	glEnd();

	// hátsó - bal keret
	glBindTexture(GL_TEXTURE_2D,texture[21]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-2.5f,-1.0f,-75.0f);
	glTexCoord2f(0.7f,0.0f);glVertex3f(-2.5f,-1.0f,-74.5f);
	glTexCoord2f(0.7f,0.7f);glVertex3f(-2.5f,2.5f,-74.5f);
	glTexCoord2f(0.0f,0.7f);glVertex3f(-2.5f,2.5f,-75.0f);
	glEnd();

	// hátsó - jobb keret
	glBindTexture(GL_TEXTURE_2D,texture[21]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(3.0f,-1.0f,-74.5f);
	glTexCoord2f(0.7f,0.0f);glVertex3f(3.0f,-1.0f,-75.0f);
	glTexCoord2f(0.7f,0.7f);glVertex3f(3.0f,2.5f,-75.0f);
	glTexCoord2f(0.0f,0.7f);glVertex3f(3.0f,2.5f,-74.5f);
	glEnd();

	// hátsó - jobb
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(3.0f,-1.0f,-75.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(18.0f,-1.0f,-75.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(18.0f,4.5f,-75.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(3.0f,4.5f,-75.0f);
	glEnd();


	//-----------------------------------------------------------------

	// Elválasztó fal
	//glColor4f(1.f,1.f,1.f,1.0f);
	glBindTexture(GL_TEXTURE_2D,texture[3]);
	//glColor4f(1.0f,1.0f,1.0f,1.0f);
	
	// elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f,-35.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(14.8f,-1.0f,-35.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(14.8f,4.5f,-35.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-15.0f,4.5f,-35.0f);
	glEnd();

	// hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-15.0f,4.5f,-40.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(14.8f,4.5f,-40.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(14.8f,-1.0f,-40.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f,-40.0f);
	glEnd();

	// bal oldala
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-15.0f, 4.5f,-35.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-15.0f, 4.5f,-40.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-15.0f,-1.0f,-40.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f,-35.0f);
	glEnd();

	// jobb oldala
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(14.8f,-1.0f,-35.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(14.8f,-1.0f,-40.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(14.8f, 4.5f,-40.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(14.8f, 4.5f,-35.0f);
	glEnd();

	// bal oldali átjáró - szembõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,2.0f,-35.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-15.0f,2.0f,-35.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-15.0f, 4.5f,-35.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-18.0f, 4.5f,-35.0f);
	glEnd();

	// bal oldali átjáró - alulról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-18.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-15.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-15.0f, 2.0f,-35.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-18.0f, 2.0f,-35.0f);
	glEnd();

	// bal oldali átjáró - hátulról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-18.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-18.0f, 4.5f,-40.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-15.0f, 4.5f,-40.0f);
	glEnd();

	// jobb oldali átjáró - szembõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(14.8f,2.0f,-35.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(18.0f,2.0f,-35.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(18.0f, 4.5f,-35.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(14.8f, 4.5f,-35.0f);
	glEnd();

	// jobb oldali átjáró - alulról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(14.8f,2.0f,-40.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(18.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(18.0f, 2.0f,-35.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(14.8f, 2.0f,-35.0f);
	glEnd();

	// jobb oldali átjáró - hátulról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(18.0f,2.0f,-40.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(14.8f,2.0f,-40.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(14.8f, 4.5f,-40.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(18.0f, 4.5f,-40.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Elsõ fal
	glBindTexture(GL_TEXTURE_2D,texture[1]);
	// hátulja
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-15.0f,3.5f,-30.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(14.8f,3.5f,-30.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(14.8f,-1.0f,-30.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f,-30.0f);
	glEnd();

	// eleje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-1.0f,-25.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(9.8f,-1.0f,-25.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(9.8f,3.5f,-25.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-10.0f,3.5f,-25.0f);
	glEnd();

	// bal oldal kívülrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-15.0f, 3.5f, 5.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(-15.0f, 3.5f,-30.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(-15.0f,-1.0f,-30.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f, 5.0f);
	glEnd();

	// jobb oldal kívülrõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(14.8f,-1.0f, 5.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(14.8f,-1.0f,-30.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(14.8f, 3.5f,-30.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(14.8f, 3.5f, 5.0f);
	glEnd();

	// bal oldal belülrõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-1.0f, 5.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(-10.0f,-1.0f,-25.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(-10.0f, 3.5f,-25.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-10.0f, 3.5f, 5.0f);
	glEnd();

	// jobb oldal belülrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(9.8f, 3.5f, 5.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(9.8f, 3.5f,-25.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(9.8f,-1.0f,-25.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,-1.0f, 5.0f);
	glEnd();

	// bal eleje szembõl 
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f, 5.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-10.0f,-1.0f, 5.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-10.0f,3.5f, 5.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-15.0f,3.5f, 5.0f);
	glEnd();

	// jobb eleje szembõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,-1.0f, 5.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(14.8f,-1.0f, 5.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(14.8f,3.5f, 5.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(9.8f,3.5f, 5.0f);
	glEnd();

	//-----------------------------------------------------------------

	// második fal
	// hátulja
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-15.0f,3.5f,-70.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(14.8f,3.5f,-70.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(14.8f,-1.0f,-70.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f,-70.0f);
	glEnd();

	// eleje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-1.0f,-65.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(9.8f,-1.0f,-65.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(9.8f,3.5f,-65.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-10.0f,3.5f,-65.0f);
	glEnd();

	// bal oldal kívülrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-15.0f, 3.5f, -45.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(-15.0f, 3.5f,-70.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(-15.0f,-1.0f,-70.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f, -45.0f);
	glEnd();

	// jobb oldal kívülrõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(14.8f,-1.0f, -45.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(14.8f,-1.0f,-70.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(14.8f, 3.5f,-70.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(14.8f, 3.5f, -45.0f);
	glEnd();

	// bal oldal belülrõl
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-1.0f, -45.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(-10.0f,-1.0f,-65.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(-10.0f, 3.5f,-65.0f);
	glTexCoord2f(0.0f,5.0f);glVertex3f(-10.0f, 3.5f, -45.0f);
	glEnd();

	// jobb oldal belülrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,5.0f);glVertex3f(9.8f, 3.5f, -45.0f);
	glTexCoord2f(5.0f,5.0f);glVertex3f(9.8f, 3.5f,-65.0f);
	glTexCoord2f(5.0f,0.0f);glVertex3f(9.8f,-1.0f,-65.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,-1.0f, -45.0f);
	glEnd();

	// bal eleje szembõl 
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-15.0f,-1.0f, -45.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-10.0f,-1.0f, -45.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-10.0f,3.5f, -45.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-15.0f,3.5f, -45.0f);
	glEnd();

	// jobb eleje szembõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,-1.0f, -45.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(14.8f,-1.0f, -45.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(14.8f,3.5f, -45.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(9.8f,3.5f, -45.0f);
	glEnd();

	//-----------------------------------------------------------------

	// elsõ oszlop
	glBindTexture(GL_TEXTURE_2D,texture[5]);
	// elsõ oszlop - elölrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,-5.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-5.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f,2.5f,-5.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f,2.5f,-5.0f);
	glEnd();

	// elsõ oszlop - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f,2.5f,-7.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f,2.5f,-7.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-7.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,-7.0f);
	glEnd();

	// elsõ oszlop - balról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f, 2.5f, -5.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-1.0f, 2.5f,-7.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-1.0f,-1.0f,-7.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f, -5.0f);
	glEnd();

	// elsõ oszlop - jobbról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f, -5.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-7.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f, 2.5f,-7.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(1.0f, 2.5f, -5.0f);
	glEnd();

	//-----------------------------------------------------------------

	// második oszlop
	glBindTexture(GL_TEXTURE_2D,texture[5]);
	// második oszlop - elölrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,-54.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-54.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f,0.5f,-54.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f,0.5f,-54.0f);
	glEnd();

	// második oszlop - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f,0.5f,-56.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f,0.5f,-56.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-56.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f,-56.0f);
	glEnd();

	// második oszlop - balról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,2.0f);glVertex3f(-1.0f,0.5f, -54.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(-1.0f,0.5f,-56.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(-1.0f,-1.0f,-56.0f);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,-1.0f, -54.0f);
	glEnd();

	// második oszlop - jobbról
	glBegin(GL_QUADS); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,-1.0f, -54.0f);
	glTexCoord2f(2.0f,0.0f);glVertex3f(1.0f,-1.0f,-56.0f);
	glTexCoord2f(2.0f,2.0f);glVertex3f(1.0f,0.5f,-56.0f);
	glTexCoord2f(0.0f,2.0f);glVertex3f(1.0f,0.5f, -54.0f);
	glEnd();

	//-----------------------------------------------------------------

	//alaprajz
	glBindTexture(GL_TEXTURE_2D,texture[6]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-0.7f,0.5f,-4.99f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(0.6f,0.5f,-4.99f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(0.6f,2.0f,-4.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-0.7f,2.0f,-4.99f);
	glEnd();

	//-----------------------------------------------------------------

	// Bejárati ajtó
	glBindTexture(GL_TEXTURE_2D,texture[8]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(2.0f,-1.0f,10.49f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-2.0f,-1.0f,10.49f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-2.0f,2.5f,10.49f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(2.0f,2.5f,10.49f);
	glEnd();

	//-----------------------------------------------------------------

	// Exit felirat
	glBindTexture(GL_TEXTURE_2D,texture[9]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,2.8f,9.99f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,2.8f,9.99f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,3.5f,9.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,3.5f,9.99f);
	glEnd();

	//-----------------------------------------------------------------

	// Mona Lisa
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[12]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.5f,-24.99f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,3.0f,-24.99f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.5f,-24.99f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,3.0f,-24.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,3.0f,-24.9f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,0.5f,-24.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,0.5f,-24.99f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[11]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,3.0f,-24.9f);
	glEnd();

	//-----------------------------------------------------------------

	// Portré1
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.0f,0.5f,-25.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.0f,3.0f,-25.0f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,0.5f,-25.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,3.0f,-25.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-5.0f,3.0f,-24.9f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.0f,0.5f,-25.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-5.0f,0.5f,-25.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[40]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.0f,3.0f,-24.9f);
	glEnd();

	//-----------------------------------------------------------------

	// Utca1
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(5.0f,0.5f,-25.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(5.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(5.0f,3.0f,-25.0f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(8.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(8.0f,0.5f,-25.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(8.0f,3.0f,-25.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(8.0f,3.0f,-24.9f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(8.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(5.0f,0.5f,-25.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(8.0f,0.5f,-25.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[41]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(5.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(8.0f,0.5f,-24.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(8.0f,3.0f,-24.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(5.0f,3.0f,-24.9f);
	glEnd();

	//-----------------------------------------------------------------

	// Utolsó vacsora
	// Hátsó szegély
	glBindTexture(GL_TEXTURE_2D,texture[24]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-15.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-15.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-15.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-15.0f);
	glEnd();

	// Elsõ szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-10.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-10.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-10.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-10.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-15.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-15.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-10.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-10.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[23]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-15.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-10.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-10.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-15.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Utca2
	// Hátsó szegély
	glBindTexture(GL_TEXTURE_2D,texture[42]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-22.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-22.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-22.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-22.0f);
	glEnd();

	// Elsõ szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-19.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-19.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-19.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-19.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-22.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-22.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-19.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-19.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[43]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-22.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-19.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-19.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-22.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Tajkep7
	// Hátsó szegély
	glBindTexture(GL_TEXTURE_2D,texture[44]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-6.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-6.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-6.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-6.0f);
	glEnd();

	// Elsõ szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-3.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-3.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-3.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-3.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-6.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-6.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-3.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-3.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[45]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-6.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-3.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-3.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-6.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Festeny1
	// Hátsó szegély
	glBindTexture(GL_TEXTURE_2D,texture[49]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,0.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,0.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,0.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,0.0f);
	glEnd();

	// Elsõ szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,2.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,2.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,0.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,0.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,2.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[50]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,0.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,0.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Van Gogh
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[15]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.5f,-64.99f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,3.0f,-64.99f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.5f,-64.99f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,3.0f,-64.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,3.0f,-64.9f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-1.0f,0.5f,-64.99f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(1.0f,0.5f,-64.99f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[13]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(1.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(1.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-1.0f,3.0f,-64.9f);
	glEnd();

	//-----------------------------------------------------------------

	// A Maid Asleep - Painting of Vermeer
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[26]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-54.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-54.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-54.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-56.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-56.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-56.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-56.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-54.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[25]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-56.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-54.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-56.0f);
	glEnd();

	//-----------------------------------------------------------------

	// tájkép1
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-60.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-60.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-60.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-60.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-62.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-62.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-62.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-62.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-62.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-62.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-60.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-60.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[27]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-62.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-60.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-60.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-62.0f);
	glEnd();

	//-----------------------------------------------------------------

	// tajkep2
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-48.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-48.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,3.0f,-48.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-48.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.8f,0.5f,-50.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-50.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-50.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.8f,3.0f,-50.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-50.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.8f,0.5f,-50.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.8f,0.5f,-48.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,0.5f,-48.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[30]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(9.7f,0.5f,-50.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(9.7f,0.5f,-48.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(9.7f,3.0f,-48.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(9.7f,3.0f,-50.0f);
	glEnd();

	//-----------------------------------------------------------------

	// tajkep3
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-48.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-48.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-48.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,-48.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-50.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,0.5f,-50.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-50.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-50.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-50.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-50.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,0.5f,-48.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,0.5f,-48.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[31]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-48.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-50.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-50.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-48.0f);
	glEnd();

	//-----------------------------------------------------------------

	// tajkep4
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[32]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-54.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-54.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,-54.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-57.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,0.5f,-57.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-57.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-57.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-57.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-57.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,0.5f,-54.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,0.5f,-54.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[33]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-54.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-57.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-57.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-54.0f);
	glEnd();

	//-----------------------------------------------------------------

	// sikoly
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[34]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-60.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-60.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-60.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,-60.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-62.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,0.5f,-62.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-62.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-62.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-62.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-62.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,0.5f,-60.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,0.5f,-60.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[35]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-60.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-62.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-62.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-60.0f);
	glEnd();

	//-----------------------------------------------------------------

	// tajkep5
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[36]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-8.0f,0.5f,-65.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-8.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-8.0f,3.0f,-65.0f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,0.5f,-65.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,3.0f,-65.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-5.0f,3.0f,-64.9);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-5.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-8.0f,0.5f,-65.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-5.0f,0.5f,-65.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[37]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-5.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-5.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-8.0f,3.0f,-64.9f);
	glEnd();

	//-----------------------------------------------------------------

	// tajkep6
	// Bal szegély
	glBindTexture(GL_TEXTURE_2D,texture[38]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(4.0f,0.5f,-65.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(4.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(4.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(4.0f,3.0f,-65.0f);
	glEnd();

	// Jobb szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(8.0f,0.5f,-65.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(8.0f,3.0f,-65.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(8.0f,3.0f,-64.9);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(4.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(4.0f,0.5f,-65.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(8.0f,0.5f,-65.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[39]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(4.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(8.0f,0.5f,-64.9f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(8.0f,3.0f,-64.9f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(4.0f,3.0f,-64.9f);
	glEnd();

	//-----------------------------------------------------------------

	// Tajkep8
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[46]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-17.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-17.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-17.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,-17.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-21.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,0.5f,-21.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-21.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-21.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-21.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-21.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,0.5f,-17.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,0.5f,-17.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[47]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-17.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-21.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-21.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-17.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Tajkep9
	// elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[32]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,2.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,2.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,-2.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,0.5f,-2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,-2.0f);
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,0.5f,-2.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,0.5f,2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,0.5f,2.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[48]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.9f,0.5f,2.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.9f,0.5f,-2.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.9f,3.0f,-2.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.9f,3.0f,2.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Festmeny2 (asztalon)
	// Elsõ szegély
	glBindTexture(GL_TEXTURE_2D,texture[51]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.0f,-0.1f,-7.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-8.85f,-0.05f,-7.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.85f,3.05f,-7.0f); 
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.0f,-7.0f);
	glEnd();

	// hátsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-8.85f,-0.05f,-9.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.0f,-0.1f,-9.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.0f,-9.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.85f,3.05f,-9.0f); 
	glEnd();

	// Alsó szegély
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.0f,-0.1f,-9.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-8.85f,-0.05f,-9.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-8.85f,-0.05f,-7.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.0f,-0.1f,-7.0f);
	glEnd();

	// Hátsó lap
	glBindTexture(GL_TEXTURE_2D,texture[53]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.0f,-0.1f,-9.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.0f,-0.1f,-7.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,3.1f,-7.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,3.1f,-9.0f);
	glEnd();

	// Kép
	glBindTexture(GL_TEXTURE_2D,texture[52]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-8.85f,-0.05f,-7.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-8.85f,-0.05f,-9.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.85f,3.05f,-9.0f); 
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.85f,3.05f,-7.0f); 
	glEnd();

	//-----------------------------------------------------------------

	// Asztal
	// Elsõ láb - bal
	glBindTexture(GL_TEXTURE_2D,texture[22]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.5f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.5f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.5f,-0.3f,-5.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.5f,-0.3f,-5.8f);
	glEnd();

	// Elsõ láb - jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.2f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.2f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.2f,-0.3f,-5.8f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.2f,-0.3f,-5.5f);
	glEnd();

	// Elsõ láb - elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.5f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.2f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.2f,-0.3f,-5.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.5f,-0.3f,-5.5f);
	glEnd();

	// Elsõ láb - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.2f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.5f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.5f,-0.3f,-5.8f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.2f,-0.3f,-5.8f);
	glEnd();

	// Második láb - bal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.8f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.8f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.8f,-0.3f,-5.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.8f,-0.3f,-5.8f);
	glEnd();

	// Második láb - jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.5f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.5f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.5f,-0.3f,-5.8f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.5f,-0.3f,-5.5f);
	glEnd();

	// Második láb - elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.8f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.5f,-1.0f,-5.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.5f,-0.3f,-5.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.8f,-0.3f,-5.5f);
	glEnd();

	// Második láb - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.5f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.8f,-1.0f,-5.8f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.8f,-0.3f,-5.8f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.5f,-0.3f,-5.8f);
	glEnd();

	// Harmadik láb - bal
	glBindTexture(GL_TEXTURE_2D,texture[22]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.5f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.5f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.5f,-0.3f,-11.2f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.5f,-0.3f,-11.5f);
	glEnd();

	// Harmadik láb - jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.2f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.2f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.2f,-0.3f,-11.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.2f,-0.3f,-11.2f);
	glEnd();

	// Harmadik láb - elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.5f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.2f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.2f,-0.3f,-11.2f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.5f,-0.3f,-11.2f);
	glEnd();

	// Harmadik láb - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-9.2f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-9.5f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-9.5f,-0.3f,-11.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-9.2f,-0.3f,-11.5f);
	glEnd();

	// Negyedik láb - bal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.8f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.8f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.8f,-0.3f,-11.2f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.8f,-0.3f,-11.5f);
	glEnd();

	// Negyedik láb - jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.5f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.5f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.5f,-0.3f,-11.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.5f,-0.3f,-11.2f);
	glEnd();

	// Negyedik láb - elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.8f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.5f,-1.0f,-11.2f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.5f,-0.3f,-11.2f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.8f,-0.3f,-11.2f);
	glEnd();

	// Negyedik láb - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.5f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.8f,-1.0f,-11.5f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.8f,-0.3f,-11.5f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.5f,-0.3f,-11.5f);
	glEnd();

	// Lap - felülrõl
	glBindTexture(GL_TEXTURE_2D,texture[22]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-0.1f,-4.998f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-6.998f,-0.1f,-4.998f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-6.998f,-0.1f,-12.002f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,-0.1f,-12.002f);
	glEnd();

	// Szegély - elõlrõl
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-10.0f,-0.3f,-5.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.0f,-0.3f,-5.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.0f,-0.1f,-5.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-10.0f,-0.1f,-5.0f);
	glEnd();

	// Szegély - jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.0f,-0.3f,-5.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-7.0f,-0.3f,-12.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-7.0f,-0.1f,-12.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.0f,-0.1f,-5.0f);
	glEnd();

	// Szegély - hátulról
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f);glVertex3f(-7.0f,-0.3f,-12.0f);
	glTexCoord2f(1.0f,0.0f);glVertex3f(-10.0f,-0.3f,-12.0f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-10.0f,-0.1f,-12.0f);
	glTexCoord2f(0.0f,1.0f);glVertex3f(-7.0f,-0.1f,-12.0f);
	glEnd();

	//-----------------------------------------------------------------

	// Help
    glDisable(GL_TEXTURE_2D);
	if(help){
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[7]);
	glBegin(GL_QUADS);
	glColor4f(1.0f,1.0f,1.0f,0.8f);

	glTexCoord2f(1.0f,0.0f);glVertex3f(-0.5f,-0.5f,-1.2f); 
	glTexCoord2f(0.0f,0.0f);glVertex3f(0.5f,-0.5f,-1.2f); 
	glTexCoord2f(0.0f,1.0f);glVertex3f(0.5f,0.5f,-1.2f);
	glTexCoord2f(1.0f,1.0f);glVertex3f(-0.5f,0.5f,-1.2f);
	glEnd();
	}
 
	glutSwapBuffers();

}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'w' :
			
            xpos+=(float)sin(yrot*3.14f/180.0f) * 0.2f;
			zpos+=(float)cos(yrot*3.14f/180.0f) * 0.2f;
			
			// Szoba fala
			// Jobb
			if(xpos<=-17.9f){
				xpos=(-17.8f);
			}

			// Bal
			if(xpos>=17.9f){
				xpos=17.8f;
			}
			
			// Eleje
			if(zpos<=-9.9){
				zpos=-9.8f;
			}

			// Hátulja
			if(zpos>=74.9f){
				zpos=74.8f;
			}

			//---------------------------------------------------------

	        // Elsõ oszlop
			// Eleje
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=4.9f) && (zpos<=5.1f)){
					zpos=4.8f;	
				}
			}

			// Hátulja
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=6.9f) && (zpos<=7.1f)){
					zpos=7.2f;	
				}
			}

			// Bal 
			if((zpos>=5.0f) && (zpos<=7.0f)){
				if((xpos<=1.1f) && (xpos>=0.9f)){
					xpos=1.2f;	
				}
			}

			// Jobb 
			if((zpos>=5.0f) && (zpos<=7.0f)){
				if((xpos>=-1.1f) && (xpos<=-0.9f)){
					xpos=-1.2f;	
				}
			}

			//---------------------------------------------------------

			// Elválasztó
			// Eleje
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=34.9f) && (zpos<=35.1f)){
					zpos=34.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=39.9f) && (zpos<=40.1f)){
					zpos=40.2f;	
				}
			}

			// Bal 
			if((zpos>=35.0f) && (zpos<=40.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=35.0f) && (zpos<=40.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}

			//---------------------------------------------------------

	        // Második oszlop
			// Eleje
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=53.9f) && (zpos<=54.1f)){
					zpos=53.8f;	
				}
			}

			// Hátulja
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=55.9f) && (zpos<=56.1f)){
					zpos=56.2f;	
				}
			}

			// Bal 
			if((zpos>=54.0f) && (zpos<=56.0f)){
				if((xpos<=1.1f) && (xpos>=0.9f)){
					xpos=1.2f;	
				}
			}

			// Jobb 
			if((zpos>=54.0f) && (zpos<=56.0f)){
				if((xpos>=-1.1f) && (xpos<=-0.9f)){
					xpos=-1.2f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - bal
			// Eleje
			if((xpos<=15.0f) && (xpos>=10.0f)){
				if((zpos>=-5.1f) && (zpos<=-4.9f)){
					zpos=-5.2f;	
				}
			}

			// Bal 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos>=9.9f) && (xpos<=10.1f)){
					xpos=9.8f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - közép
			// Eleje
			if((xpos<=15.0f) && (xpos>=-14.8f)){
				if((zpos>=24.9f) && (zpos<=25.1f)){
					zpos=24.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=29.9f) && (zpos<=30.1f)){
					zpos=30.2f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - jobb
			// Eleje
			if((xpos<=-9.8f) && (xpos>=-14.8f)){
				if((zpos>=-5.1f) && (zpos<=-4.9f)){
					zpos=-5.2f;	
				}
			}

			// Bal 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos<=-9.7f) && (xpos>=-9.9f)){
					xpos=-9.6f;	
				}
			}

			// Jobb 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - bal
			// Eleje
			if((xpos<=15.0f) && (xpos>=10.0f)){
				if((zpos>=44.9f) && (zpos<=45.1f)){
					zpos=44.8f;	
				}
			}

			// Bal 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos>=9.9f) && (xpos<=10.1f)){
					xpos=9.8f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - közép
			// Eleje
			if((xpos<=15.0f) && (xpos>=-14.8f)){
				if((zpos>=64.9f) && (zpos<=65.1f)){
					zpos=64.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=69.9f) && (zpos<=70.1f)){
					zpos=70.2f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - jobb
			// Eleje
			if((xpos<=-9.8f) && (xpos>=-14.8f)){
				if((zpos>=44.9f) && (zpos<=45.1f)){
					zpos=44.8f;	
				}
			}

			// Bal 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos<=-9.7f) && (xpos>=-9.9f)){
					xpos=-9.6f;	
				}
			}

			// Jobb 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}

			//---------------------------------------------------------

			// Asztal
			// Elõlrõl
			if((xpos<=10.0f) && (xpos>=7.0f)){
				if((zpos>=4.9f) && (zpos<=5.1f)){
					zpos=4.8f;	
				}
			}

			// Jobbról
			if((zpos>=5.0f) && (zpos<=12.0f)){
				if((xpos>=6.9f) && (xpos<=7.1f)){
					xpos=6.8f;	
				}
			}

			// Hátulról
			if((xpos<=10.0f) && (xpos>=7.0f)){
				if((zpos>=11.9f) && (zpos<=12.1f)){
					zpos=12.2f;	
				}
			}

			//---------------------------------------------------------

			// Hátsó ajtó
			// Bal
			if((zpos>=74.5f) && (zpos<=75.0f)){
				if((xpos<=2.6f) && (xpos>=2.4f)){
					xpos=2.7f;	
				}
			}

			// Jobb
			if((zpos<=75.0f) && (zpos>=74.5f)){
				if((xpos>=-3.1f) && (xpos<=-2.9f)){
					xpos=-3.2f;	
				}
			}

			// Eleje
			if((xpos<=2.5f) && (xpos>=-3.0f)){
				if((zpos>=74.4f) && (zpos<=74.6f)){
					zpos=74.3f;	
				}
			}

			//---------------------------------------------------------

            break;
		
        case 's' :
			
			xpos-=(float)sin(yrot*3.14f/180.0f) * 0.2f;
			zpos-=(float)cos(yrot*3.14f/180.0f) * 0.2f;
			
			// Szoba fala
			// Jobb
			if(xpos<=-17.9f){
				xpos=(-17.8f);
			}

			// Bal
			if(xpos>=17.9f){
				xpos=17.8f;
			}
			
			// Eleje
			if(zpos<=-9.9){
				zpos=-9.8f;
			}

			// Hátulja
			if(zpos>=74.9f){
				zpos=74.8f;
			}

			//---------------------------------------------------------

	        // Elsõ oszlop
			// Eleje
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=4.9f) && (zpos<=5.1f)){
					zpos=4.8f;	
				}
			}

			// Hátulja
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=6.9f) && (zpos<=7.1f)){
					zpos=7.2f;	
				}
			}

			// Bal 
			if((zpos>=5.0f) && (zpos<=7.0f)){
				if((xpos<=1.1f) && (xpos>=0.9f)){
					xpos=1.2f;	
				}
			}

			// Jobb 
			if((zpos>=5.0f) && (zpos<=7.0f)){
				if((xpos>=-1.1f) && (xpos<=-0.9f)){
					xpos=-1.2f;	
				}
			}

			//---------------------------------------------------------

			// Elválasztó
			// Eleje
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=34.9f) && (zpos<=35.1f)){
					zpos=34.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=39.9f) && (zpos<=40.1f)){
					zpos=40.2f;	
				}
			}

			// Bal 
			if((zpos>=35.0f) && (zpos<=40.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=35.0f) && (zpos<=40.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}

			//---------------------------------------------------------

	        // Második oszlop
			// Eleje
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=53.9f) && (zpos<=54.1f)){
					zpos=53.8f;	
				}
			}

			// Hátulja
			if((xpos<=1.0f) && (xpos>=-1.0f)){
				if((zpos>=55.9f) && (zpos<=56.1f)){
					zpos=56.2f;	
				}
			}

			// Bal 
			if((zpos>=54.0f) && (zpos<=56.0f)){
				if((xpos<=1.1f) && (xpos>=0.9f)){
					xpos=1.2f;	
				}
			}

			// Jobb 
			if((zpos>=54.0f) && (zpos<=56.0f)){
				if((xpos>=-1.1f) && (xpos<=-0.9f)){
					xpos=-1.2f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - bal
			// Eleje
			if((xpos<=15.0f) && (xpos>=10.0f)){
				if((zpos>=-5.1f) && (zpos<=-4.9f)){
					zpos=-5.2f;	
				}
			}

			// Bal 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos>=9.9f) && (xpos<=10.1f)){
					xpos=9.8f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - közép
			// Eleje
			if((xpos<=15.0f) && (xpos>=-14.8f)){
				if((zpos>=24.9f) && (zpos<=25.1f)){
					zpos=24.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=29.9f) && (zpos<=30.1f)){
					zpos=30.2f;	
				}
			}

			//---------------------------------------------------------

			// Elsõ fal - jobb
			// Eleje
			if((xpos<=-9.8f) && (xpos>=-14.8f)){
				if((zpos>=-5.1f) && (zpos<=-4.9f)){
					zpos=-5.2f;	
				}
			}

			// Bal 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos<=-9.7f) && (xpos>=-9.9f)){
					xpos=-9.6f;	
				}
			}

			// Jobb 
			if((zpos>=-5.0f) && (zpos<=30.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - bal
			// Eleje
			if((xpos<=15.0f) && (xpos>=10.0f)){
				if((zpos>=44.9f) && (zpos<=45.1f)){
					zpos=44.8f;	
				}
			}

			// Bal 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos<=15.1f) && (xpos>=14.9f)){
					xpos=15.2f;	
				}
			}

			// Jobb 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos>=9.9f) && (xpos<=10.1f)){
					xpos=9.8f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - közép
			// Eleje
			if((xpos<=15.0f) && (xpos>=-14.8f)){
				if((zpos>=64.9f) && (zpos<=65.1f)){
					zpos=64.8f;	
				}
			}

			// Hátulja
			if((xpos<=14.8f) && (xpos>=-15.0f)){
				if((zpos>=69.9f) && (zpos<=70.1f)){
					zpos=70.2f;	
				}
			}

			//---------------------------------------------------------

			// Második fal - jobb
			// Eleje
			if((xpos<=-9.8f) && (xpos>=-14.8f)){
				if((zpos>=44.9f) && (zpos<=45.1f)){
					zpos=44.8f;	
				}
			}

			// Bal 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos<=-9.7f) && (xpos>=-9.9f)){
					xpos=-9.6f;	
				}
			}

			// Jobb 
			if((zpos>=45.0f) && (zpos<=70.0f)){
				if((xpos>=-14.9f) && (xpos<=-14.7f)){
					xpos=-15.0f;	
				}
			}
			//---------------------------------------------------------

			// Asztal
			// Elõlrõl
			if((xpos<=10.0f) && (xpos>=7.0f)){
				if((zpos>=4.9f) && (zpos<=5.1f)){
					zpos=4.8f;	
				}
			}

			// Jobbról
			if((zpos>=5.0f) && (zpos<=12.0f)){
				if((xpos>=6.9f) && (xpos<=7.1f)){
					xpos=6.8f;	
				}
			}

			// Hátulról
			if((xpos<=10.0f) && (xpos>=7.0f)){
				if((zpos>=11.9f) && (zpos<=12.1f)){
					zpos=12.2f;	
				}
			}

			//---------------------------------------------------------

			// Hátsó ajtó
			// Bal
			if((zpos>=74.5f) && (zpos<=75.0f)){
				if((xpos<=2.6f) && (xpos>=2.4f)){
					xpos=2.7f;	
				}
			}

			// Jobb
			if((zpos<=75.0f) && (zpos>=74.5f)){
				if((xpos>=-3.1f) && (xpos<=-2.9f)){
					xpos=-3.2f;	
				}
			}

			// Eleje
			if((xpos<=2.5f) && (xpos>=-3.0f)){
				if((zpos>=74.4f) && (zpos<=74.6f)){
					zpos=74.3f;	
				}
			}

			//---------------------------------------------------------

            break;

        case 'a' :
            yrot+=3.0f;
            break;

        case 'd' :
            yrot-=3.0f;
            break;
		
		case 'f' :
				 if(light_ambient[0]<0.8f){
				 for(int i=0;i<3;i++){
					light_ambient[i]+=0.1f;
				 }
				 }
            break;

	    case 'l' :
             if(light_ambient[0]>0){
				 for(int i=0;i<3;i++){
					light_ambient[i]-=0.1f;
				 }
				 }
            break;

		case 27 :    // escape
			exit(0);
            break;
			 
    }

    glutPostRedisplay();
}

static void spec(int key, int x, int y){
	switch (key){
	case  GLUT_KEY_F1 :
			help=!help;
			break;

	case  GLUT_KEY_F11 :
			glutFullScreen();   // making the window full screen
			break;

	case  GLUT_KEY_F10 :
			glutReshapeWindow(800, 600);
			break;
	}

	glutPostRedisplay();
}

/*static void idle(void)
{
    glutPostRedisplay();
	
}*/

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/50, timer, 0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

    glutCreateWindow("Galéria");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
	glutSpecialFunc(spec);
    //glutIdleFunc(timer);
	glutTimerFunc(0,timer,0);

    glClearColor(0.0,0.0,0.0,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);  
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LESS);
	glShadeModel(GL_SMOOTH);	// Flat Shading

	


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT,light_ambient);
	GLfloat material[]={0.5,0.5,0.5,1};
	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,material);


	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    
	LoadGLTextures();
	
    
    glutMainLoop();

    return 0;
}