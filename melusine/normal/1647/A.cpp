#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n%3==0)
		{
			for(int i=1;i<=n/3;i++)printf("21");
			printf("\n");
			continue;
		}
		if(n%3==1)
		{
			printf("1");
			for(int i=1;i<=n/3;i++)printf("21");
			printf("\n");
			continue;
		}
		printf("2");
		for(int i=1;i<=n/3;i++)printf("12");
		printf("\n");
	}
	return 0;
}