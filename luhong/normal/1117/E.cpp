#include <cstdio>
#include <cstring>
#include <iostream>

char c[10100], s[10100];
int p[10100];

int main()
{
	scanf("%s", c);
	int n = strlen(c);
	
	printf("? ");
	for(int i = 0; i < n; i++) printf("%c", i / 26 / 26 + 'a');
	puts("");
	fflush(stdout);
	scanf("%s", s);
	for(int i = 0; i < n; i++) p[i] = s[i] - 'a';
	
	printf("? ");
	for(int i = 0; i < n; i++) printf("%c", i / 26 % 26 + 'a');
	puts("");
	fflush(stdout);
	scanf("%s", s);
	for(int i = 0; i < n; i++) p[i] = p[i] * 26 + s[i] - 'a';
	
	printf("? ");
	for(int i = 0; i < n; i++) printf("%c", i % 26 + 'a');
	puts("");
	fflush(stdout);
	scanf("%s", s);
	for(int i = 0; i < n; i++) p[i] = p[i] * 26 + s[i] - 'a';
	
	for(int i = 0; i < n; i++) s[p[i]] = c[i];
	printf("! %s", s); 
	fflush(stdout);
	return 0;
}
//1 2 3 4 5 6 ... 
//26 ^ 3 >= 10000
/*
a b c ... a b ... 
a a a ... b b ...
a a a ... a a ... 
*/