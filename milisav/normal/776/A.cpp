#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[20],b[20],c[20],d[20];
int n;
int main()
{
	scanf("%s %s",a,b);
	printf("%s %s\n",a,b);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s",c,d);
		if(strcmp(a,c)==0)
		{
			for(int i=0;i<11;i++) a[i]=d[i];
		}
		else
		{
			for(int i=0;i<11;i++) b[i]=d[i];
		}
		printf("%s %s\n",a,b);
	}
	return 0;
}