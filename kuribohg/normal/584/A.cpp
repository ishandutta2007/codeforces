#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,t;
int main()
{
	scanf("%d%d",&n,&t);
	if(n==1&&t==10) puts("-1");
	else if(t==10)
	{
		for(int i=1;i<n;i++) putchar('1');
		puts("0");
	}
	else
	{
		for(int i=1;i<=n;i++)
			printf("%d",t);
		puts("");
	}
	return 0;
}