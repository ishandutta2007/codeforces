#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s1[200000];
char s2[200000];
int a,b;
int main()
{
	scanf("%s",s1);
	a=strlen(s1);
	scanf("%s",s2);
	b=strlen(s2);
	if(a>b)
	{
		printf("%d",a);
		return 0;
	}
	if(b>a)
	{
		printf("%d",b);
		return 0;
	}
	for(int i=0;i<a;i++)
	{
		if(s1[i]!=s2[i])
		{
			printf("%d",a);
			return 0;
		}
	}
	printf("-1");
	return 0;
}