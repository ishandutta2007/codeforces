#include <cstdio>
char s[1<<18],p[1<<18];
int i,l;
main(){
	gets(s);
	for (; s[i]; i++)
		!l|s[i]-p[l-1] ? p[l++]=s[i] : p[--l]=0;
	puts(p);
}