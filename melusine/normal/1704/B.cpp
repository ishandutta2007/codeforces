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
int a[200005];
int main()
{
	int ttt,n,x,minn,maxn,ans;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		x=read();
		for(int i=1;i<=n;i++)a[i]=read();
		minn=1000000000;
		maxn=-1000000000;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			minn=min(minn,a[i]);
			maxn=max(maxn,a[i]);
			if(maxn-minn>2*x)
			{
				maxn=a[i];
				minn=a[i];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}