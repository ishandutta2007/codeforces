#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
ll n,m,s,ans,tot;
int pn[65],pm[65],ps[65],pri[65];
ll xp[65];
int vis[1000005];
void solve(int *cnt,int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(!vis[i]) vis[i]=++tot,pri[tot]=i;
			while(x%i==0) x/=i,cnt[vis[i]]++;
		}
	}
	if(x>1)
	{
		if(!vis[x]) vis[x]=++tot,pri[tot]=x;
		cnt[vis[x]]++;
	}
}
void dfs1(int x,ll now)
{
	if(now>n )return;
	if(x>tot)
	{
		ans++;
		return;
	}
	dfs1(x+1,now);
	for(int i=1;i<=ps[x];i++) dfs1(x+1,now*=pri[x]);
}
void dfs2(int x,ll now,int flag)
{
	if(now>m) return;
	if(x>tot)
	{
		ans+=flag*(m/now);
		return;
	}
	dfs2(x+1,now,flag);
	if(pn[x]>ps[x]) dfs2(x+1,now*xp[x]*pri[x],-flag);
}
void init()
{
	memset(pn,0,sizeof(pn));
	memset(pm,0,sizeof(pm));
	memset(ps,0,sizeof(ps));
	for(int i=1;i<=tot;i++) vis[pri[i]]=0;
}
void work()
{
	int t;
	n=m=s=1;ans=tot=0;
	
	t=read();solve(pn,t);n*=t;t=read();solve(pn,t);n*=t;t=read();solve(pn,t);n*=t;
	t=read();solve(pm,t);m*=t;t=read();solve(pm,t);m*=t;t=read();solve(pm,t);m*=t;
	t=read();solve(ps,t);s*=t;t=read();solve(ps,t);s*=t;t=read();solve(ps,t);s*=t;
	solve(ps,2);s<<=1;
	dfs1(1,1);
	for(int i=1,j;i<=tot;i++)
	{
		for(j=xp[i]=1;j<=ps[i];j++)
		{
			xp[i]*=pri[i];
		}
	}
	dfs2(1,1,1);
	printf("%lld\n",ans);
	init();
}
int main()
{
	int T=read();//cout<<"ok";
	while(T--)
	{
		work();
	}
}