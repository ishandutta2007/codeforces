#include<iostream>
#include<cstdio>
#define mod 998244353
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
int sl[65];
int main()
{
	int t,n,l,r,x,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		for(int i=0;i<=20;i++)sl[i]=0;
		l=read();
		r=read();
		for(int i=1;i<=r-l+1;i++)
		{
			x=read();
			for(int j=0;j<=20;j++)
			{
				if(x&(1<<j))sl[j]++;
			}
		}
		ans=0;
		for(int i=0;i<=20;i++)if(sl[i]>r-l+1-sl[i])
		{
			ans|=(1<<i);
		}
		printf("%d\n",ans);
	}
}