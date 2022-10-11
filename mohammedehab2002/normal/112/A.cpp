#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
int main()
{
	int i;
	char s1[101],s2[101];
	gets(s1);
	gets(s2);
	for (i=0;i<strlen(s1);i++)
	{
		if (isupper(s1[i]))
		s1[i]=tolower(s1[i]);
		if (isupper(s2[i]))
		s2[i]=tolower(s2[i]);
	}
	if (strcmp(s1,s2)<0)
	cout << -1;
	else if (strcmp(s1,s2)==0)
	cout << 0;
	else
	cout << 1;
}