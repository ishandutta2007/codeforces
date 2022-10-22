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
int a1[100005],cnt1;
int a2[100005],cnt2;
int tx[100005],ty[100005];
signed main()
{
	int t,n,x,y,maxn,now;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		cnt1=0;
		cnt2=0;
		for(int i=1;i<=n;i++)
		{
			tx[i]=read();
		}
		for(int i=1;i<=n;i++)
		{
			ty[i]=read();
			if(tx[i]==0)a1[++cnt1]=ty[i];
			else a2[++cnt2]=ty[i];
		}
		sort(a1+1,a1+cnt1+1);
		sort(a2+1,a2+cnt2+1);
		maxn=0;
		now=0;
		x=min(cnt2,cnt1-1);
		for(int i=1;i<=x;i++)now+=a1[cnt1-i+1];
		y=min(cnt2,cnt1);
		for(int i=1;i<=y;i++)now+=a2[cnt2-i+1];
		maxn=max(maxn,now);
		now=0;
		x=min(cnt2,cnt1);
		for(int i=1;i<=x;i++)now+=a1[cnt1-i+1];
		y=min(cnt2-1,cnt1);
		for(int i=1;i<=y;i++)now+=a2[cnt2-i+1];
		maxn=max(maxn,now);
		//printf("%lld\n",maxn);
		for(int i=1;i<=cnt1;i++)maxn+=a1[i];
		for(int i=1;i<=cnt2;i++)maxn+=a2[i];
		printf("%lld\n",maxn);
	}
	return 0;
}