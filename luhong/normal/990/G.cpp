#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int root,sum,n;
bool used[201000];
long long ans[201000];
int siz[201000],f[200100];
int cnt[201000],val[201000];
int h[201000],nxt[401000],to[401000],K=0;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
void ins(int u,int v){nxt[++K]=h[u];h[u]=K;to[K]=v;}
void get_root(int x,int fa)
{
	siz[x]=1;f[x]=0;
	for(int i=h[x];i;i=nxt[i])
	{
		if(!used[to[i]]&&to[i]!=fa)
		{
			get_root(to[i],x);
			siz[x]+=siz[to[i]];
			f[x]=max(f[x],siz[to[i]]);
		}
	}
	f[x]=max(f[x],sum-siz[x]);
	if(f[x]<f[root])root=x;
}
bool U[201000];int a[201000],o=0;
void solve(int x,int fa,int v)
{
	v=gcd(v,val[x]);cnt[v]++;
	if(!U[v])U[v]=1,a[++o]=v;
	for(int i=h[x];i;i=nxt[i])
	{
		if(!used[to[i]]&&to[i]!=fa)
		{
			solve(to[i],x,v);
		}
	}
}
void calc(int x,int v,int ty)
{
	o=0;
	solve(x,0,v);
	for(int i=1;i<=o;i++)
	{
		for(int j=i+1;j<=o;j++)
		{
			ans[gcd(a[i],a[j])]+=ty*1ll*cnt[a[i]]*cnt[a[j]];
		}
	}
	for(int i=1;i<=o;i++)ans[a[i]]+=ty*(1ll*cnt[a[i]]*(cnt[a[i]]-1)/2);
	for(int i=1;i<=o;i++)U[a[i]]=0,cnt[a[i]]=0;
}
void dfs(int x)
{
	used[x]=1;calc(x,val[x],1);
	for(int i=h[x];i;i=nxt[i])
	{
		if(!used[to[i]])
		{
			sum=siz[to[i]];root=0;
			get_root(to[i],0);
			calc(to[i],val[x],-1);dfs(root);
		}
	}
}
int main()
{
	f[0]=1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]),ans[val[i]]++;
	for(int i=1;i<n;i++)
	{
		int u,v;scanf("%d%d",&u,&v);
		ins(u,v);ins(v,u);
	}
	sum=n;root=0;get_root(1,0);
	dfs(root);
	for(int i=1;i<=200000;i++)if(ans[i])printf("%d %lld\n",i,ans[i]);
	return 0; 
}