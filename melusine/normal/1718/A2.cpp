#include<iostream>
#include<cstdio>
#include<map>
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
int yh[100005],maxn[100005];
int a[100005];
map<int,int>ma;
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),yh[i]=(a[i]^yh[i-1]);
		ma.clear();
		ma[0]=0;
		maxn[0]=0;
		for(int i=1;i<=n;i++)maxn[i]=0;
		for(int i=1;i<=n;i++)
		{
			maxn[i]=max(maxn[i],maxn[i-1]);
			if(ma.count(yh[i]))maxn[i]=max(maxn[i],maxn[ma[yh[i]]]+1);
			ma[yh[i]]=i;
		}
		printf("%d\n",n-maxn[n]);
	}
}