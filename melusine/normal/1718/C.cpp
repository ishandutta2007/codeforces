#include<iostream>
#include<cstdio>
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
int ch[4000004][2],cnt;
int maxn[4000004];
int a[200004],qz[200004];
void build(int& o,int l,int r)
{
	if(o==0)o=++cnt;
	if(l==r)
	{
		maxn[o]=qz[l];
		return;
	}
	int mid=((l+r)>>1);
	build(ch[o][0],l,mid);
	build(ch[o][1],mid+1,r);
	maxn[o]=max(maxn[ch[o][0]],maxn[ch[o][1]]);
}
void change(int o,int l,int r,int x,int y)
{
	if(l==r)
	{
		maxn[o]+=y;
		return;
	}
	int mid=((l+r)>>1);
	if(x<=mid)change(ch[o][0],l,mid,x,y);
	else change(ch[o][1],mid+1,r,x,y);
	maxn[o]=max(maxn[ch[o][0]],maxn[ch[o][1]]);
}
int pri[105],ttt;
int rt[105];
signed main()
{
	int t,n,nn,q,ans,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=cnt;i++)
		{
			ch[i][0]=ch[i][1]=0;
			maxn[i]=0;
		}
		cnt=0;
		nn=n;
		ttt=0;
		for(int i=2;i*i<=nn;i++)
		{
			if(nn%i!=0)continue;
			pri[++ttt]=i;
			rt[ttt]=0;
			while(nn%i==0)nn/=i; 
		}
		if(nn>1)
		{
			pri[++ttt]=nn;
			rt[ttt]=0;
		}
		for(int i=1;i<=ttt;i++)pri[i]=n/pri[i];
		for(int i=1;i<=ttt;i++)
		{
			for(int j=1;j<=pri[i];j++)qz[j]=0;
			for(int j=1;j<=n;j++)qz[(j-1)%pri[i]+1]+=a[j];
			build(rt[i],1,pri[i]);
		}
		ans=0;
		for(int j=1;j<=ttt;j++)
		{
			ans=max(ans,maxn[rt[j]]*pri[j]);
		}
		printf("%lld\n",ans);
		for(int i=1;i<=q;i++)
		{
			x=read();
			y=read()-a[x];
			a[x]+=y;
			for(int j=1;j<=ttt;j++)
			{
				change(rt[j],1,pri[j],(x-1)%pri[j]+1,y);
			}
			ans=0;
			for(int j=1;j<=ttt;j++)
			{
				ans=max(ans,maxn[rt[j]]*pri[j]);
			}
			printf("%lld\n",ans);
		}
	}
}