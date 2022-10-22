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
int a[105],maxn[105];
int main()
{
	int t,n,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		y=read();
		if(x>y)swap(x,y);
		if(x>0)
		{
			printf("-1\n");
			continue;
		}
		if(y==0)
		{
			printf("-1\n");
			continue;
		}
		if(n%y!=1%y)
		{
			printf("-1\n");
			continue;
		}
		int las=1;
		for(int i=1;i<=n-1;i++)
		{
			if(i!=1&&(i-1)%y==0)las=i+1;
			printf("%d ",las);
		}
		printf("\n");
	}
	return 0;
}