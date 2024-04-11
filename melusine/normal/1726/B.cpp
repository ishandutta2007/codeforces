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
int a[100005];
int main()
{
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		if(m<n)
		{
			printf("No\n");
			continue;
		}
		if(n%2==1)
		{
			printf("Yes\n");
			for(int i=1;i<=n-1;i++)printf("1 ");
			printf("%d ",m-n+1);
			printf("\n");
			continue;
		}
		if(m%2!=0)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
		for(int i=1;i<=m%n;i++)printf("%d ",m/n+1);
		for(int i=1;i<=n-m%n;i++)printf("%d ",m/n);
		printf("\n");
	}
	return 0;
}