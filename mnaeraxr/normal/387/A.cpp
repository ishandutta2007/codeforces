// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int h1,h2,m1,m2,h,m;
	scanf_s("%d:%d",&h1,&m1);
	scanf_s("%d:%d",&h2,&m2);
	
	if (m1 >= m2)
	{
		m = m1 - m2;
	}
	else
	{
		m = 60 + m1 - m2;
		h2++;
	}
	if (h1 >= h2)
	{
		h = h1 - h2;
	}
	else
	{
		h = 24 + h1 - h2;
	}
	if (h < 10)
		printf("0%d:",h);
	else
		printf("%d:",h);
	if (m < 10)
		printf("0%d\n",m);
	else
		printf("%d\n",m);
}