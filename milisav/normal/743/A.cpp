#include <iostream>
#include <cstdio>
char d[1000000];
int n;
int a,b;
int main()
{
	scanf("%d",&n);
	scanf("%d %d",&a,&b);
	a--;
	b--;
	scanf("%s",d);
	if(d[a]==d[b]) printf("0");
	else printf("1");
	return 0;
}