#include <cstdio>
char s[1010];
int main()
{
	gets(s);
	int c = 0;
	for (int i = 0; s[i]; i ++)
    	if (s[i] != '/' || (s[i + 1] != '/' && s[i + 1]))  putchar(s[i]),c ++;
  	if (!c) putchar('/');
}