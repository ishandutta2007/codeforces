#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int maxn=300000;
const int maxm=20;
const int root=1;
struct edge
{
	int to,c;	
};
int n,q,a[maxn+5];
vector<edge> g[maxn+5];
int dep[maxn+5],f[maxm+5][maxn+5],p2[maxm+5];
int dp1[maxn+5],dp2[maxn+5],dp3[maxn+5],dis[maxn+5],cnt[maxn+5];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1;
	f[0][u]=fa;
	for(int i=1;p2[i]<=dep[u];i++) f[i][u]=f[i-1][f[i-1][u]];
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
	return;
}
void dfs1(int u,int fa)
{
	dp1[u]=0;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(v==fa) continue;
		dfs1(v,u);
		if(a[v]+dp1[v]-2*w<=0) continue;
		dp1[u]+=a[v]+dp1[v]-2*w;
	}
	return;
}
void dfs2(int u,int fa,int cost)
{
	dp2[u]=dp1[fa];
	if(a[u]+dp1[u]-2*cost>0) dp2[u]-=a[u]+dp1[u]-2*cost;
	if(u==root) dp2[u]=0;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(v==fa) continue;
		dfs2(v,u,w);
	}
	return;
}
void dfs3(int u,int fa,int cost)
{
	dp3[u]=a[fa];
	dp3[u]-=2*cost;
	if(dp2[u]>0) dp3[u]+=dp2[u];
	if(dp3[fa]>0) dp3[u]+=dp3[fa];
	if(dp3[u]<0) dp3[u]=0;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(v==fa) continue;
		dfs3(v,u,w);
	}
	return;
	
}
void dfs4(int u,int fa,int cost)
{
	dp2[u]+=dp2[fa];
	dis[u]=dis[fa]+cost;
	cnt[u]=cnt[fa]+a[u];
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].to;
		int w=g[u][i].c;
		if(v==fa) continue;
		dfs4(v,u,w);
	}
	return;
}
void add(int u,int v,int w)
{
	g[u].pb((edge){v,w});
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int det=dep[u]-dep[v];
	for(int i=maxm;i>=0;i--) if(det>=p2[i]) det-=p2[i],u=f[i][u];
	if(u==v) return u;
	for(int i=maxm;i>=0;i--) if(f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
	return f[0][u];
}
int Find(int u,int v)
{
	for(int i=maxm;i>=0;i--) if(dep[f[i][u]]>dep[v]) u=f[i][u];
	return u;
}
int Query(int u,int v)
{
	int lca=LCA(u,v),uu=Find(u,lca),vv=Find(v,lca);
	int sum=0,temp=0;
	if(v==lca) swap(u,v);
	sum+=cnt[v]+cnt[u]-cnt[f[0][lca]]-cnt[lca];
	sum-=dis[v]+dis[u]-2*dis[lca];	
	if(u==v)
	{
		sum+=dp1[u];
		sum+=dp3[u];
	}
	else if(u==lca)
	{
		sum+=dp1[v];
		sum+=dp3[u];
		sum+=dp2[v]-dp2[u];
	}
	else
	{
		sum+=dp1[u]+dp1[v];
		sum+=dp3[lca];
		sum+=dp2[u]+dp2[v]-dp2[lca]*2;
		sum-=dp2[vv]-dp2[lca];
		if(dp1[vv]-2*(dis[vv]-dis[lca])+a[vv]>0) sum-=dp1[vv]-2*(dis[vv]-dis[lca])+a[vv];
		
	}
	return sum;
}
signed main()
{
	p2[0]=1;
	for(int i=1;i<=maxm;i++) p2[i]=p2[i-1]*2;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int u,v,w;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,0,0);
	dfs3(1,0,0);
	dfs4(1,0,0);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&u,&v);
		printf("%lld\n",Query(u,v));
	}
	return 0;
}