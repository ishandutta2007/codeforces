#include<iostream>
#include<cstdio>
#include<algorithm>
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
int het[200005];
signed main()
{
	int ttt,n,m,x,now;
	int maxn,mpos,minn;
	ttt=read();
	for(int greg=1;greg<=ttt;greg++)
	{
		n=read();
		m=read();
		maxn=0;
		minn=1000000000000000000LL;
		for(int i=1;i<=n;i++)
		{
			now=0;
			for(int j=1;j<=m;j++)
			{
				x=read();
				now=now+j*x;
			}
			minn=min(minn,now);
			if(now>maxn)
			{
				maxn=now;
				mpos=i;
			}
		}
		printf("%lld %lld\n",mpos,maxn-minn);
	}
}