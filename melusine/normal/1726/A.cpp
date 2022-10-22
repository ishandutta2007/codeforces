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
	int t,n,ans,minn,maxn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=a[n]-a[1];
		for(int i=1;i<=n-1;i++)ans=max(ans,a[i]-a[i+1]);
		minn=maxn=a[1];
		for(int i=2;i<=n;i++)
		{
			minn=min(minn,a[i]);
			maxn=max(maxn,a[i]);
		}
		ans=max(max(ans,maxn-a[1]),a[n]-minn);
		printf("%d\n",ans);
	}
	return 0;
}