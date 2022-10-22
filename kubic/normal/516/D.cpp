#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ll long long
int n,m,ans,ps[N],ord[N],fa[N],sz[N];bool vs[N];
ll dp1[N],dp2[N],dp3[N],vl[N];
struct Edge {int v,w;};vector<Edge> e[N];
bool cmp(int x,int y) {return vl[x]>vl[y];}
int findRt(int x) {return x==fa[x]?x:fa[x]=findRt(fa[x]);}
void merge(int x,int y)
{
	x=findRt(x);y=findRt(y);
	if(x!=y) fa[x]=y,sz[y]+=sz[x],ans=max(ans,sz[y]);
}
void dfs1(int u,int f)
{
	for(int i=0,v,w;i<e[u].size();++i)
	{
		v=e[u][i].v;w=e[u][i].w;if(v==f) continue;dfs1(v,u);
		if(dp1[v]+w>dp1[u]) dp2[u]=dp1[u],dp1[u]=dp1[v]+w,ps[u]=v;
		else if(dp1[v]+w>dp2[u]) dp2[u]=dp1[v]+w;
	}
}
void dfs2(int u,int f)
{
	for(int i=0,v,w;i<e[u].size();++i)
	{
		v=e[u][i].v;w=e[u][i].w;if(v==f) continue;
		if(ps[u]==v) dp3[v]=max(dp2[u],dp3[u])+w;
		else dp3[v]=max(dp1[u],dp3[u])+w;dfs2(v,u);
	}vl[u]=max(dp1[u],dp3[u]);
}
void ins(int u)
{
	for(int i=0,v;i<e[u].size();++i)
	{v=e[u][i].v;if(vs[v]) merge(u,v);}vs[u]=1;
}
void dlt(int u) {vs[u]=0;--sz[findRt(u)];}
void slv(ll x)
{
	ans=1;for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1,vs[i]=0;
	for(int i=1,t=1;i<=n;++i)
	{while(t<=n && vl[ord[i]]-vl[ord[t]]<=x) ins(ord[t++]);dlt(ord[i]);}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back((Edge) {v,w});e[v].push_back((Edge) {u,w});
	}dfs1(1,0);dfs2(1,0);for(int i=1;i<=n;++i) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);scanf("%d",&m);
	for(int i=1;i<=m;++i) {ll x;scanf("%lld",&x);slv(x);}return 0;	
}