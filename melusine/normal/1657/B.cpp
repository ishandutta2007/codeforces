#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
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
signed main()
{
	int t,n,b,x,y,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		b=read();
		x=read();
		y=read();
		a[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i-1]+x<=b)a[i]=a[i-1]+x;
			else a[i]=a[i-1]-y; 
		}
		ans=0;
		for(int i=1;i<=n;i++)ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}