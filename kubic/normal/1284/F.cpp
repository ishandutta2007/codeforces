#include <bits/stdc++.h>
using namespace std;
#define N 250005
#define pb push_back
int n,L[N],R[N],fe[N],dep[N],fa1[N],ans[N],fa[N][18];
struct Edge {int u,v,w;}a1[N],a2[N];vector<Edge> e1[N],e2[N];
int findRt(int u) {return u==fa1[u]?u:fa1[u]=findRt(fa1[u]);}
void merge(int u,int v) {u=findRt(u);v=findRt(v);if(u!=v) fa1[u]=v;}
void dfs1(int u,int f)
{
	fa[u][0]=f;dep[u]=dep[f]+1;L[u]=++L[0];
	for(int i=1;i<=17;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto i:e1[u]) if(i.v!=f) dfs1(i.v,u),fe[i.v]=i.w;R[u]=L[0];
}
void slv(int u,int v,int w)
{
	u=findRt(u);
	if(L[v]>=L[u] && L[v]<=R[u])
	{
		for(int i=17;i>=0;--i) if(dep[fa[v][i]]>=dep[u])
			if(findRt(fa[v][i])!=u) v=fa[v][i]; 
	}else v=u;printf("%d %d ",a1[fe[v]].u,a1[fe[v]].v);
	printf("%d %d\n",a2[w].u,a2[w].v);merge(v,fa[v][0]);
}
void dfs2(int u,int f)
{for(auto i:e2[u]) if(i.v!=f) dfs2(i.v,u),slv(i.v,u,i.w);}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) fa1[i]=i;
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);a1[i]=(Edge) {u,v,i};
		e1[u].pb(a1[i]);e1[v].pb((Edge) {v,u,i});
	}
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d %d",&u,&v);a2[i]=(Edge) {u,v,i};
		e2[u].pb(a2[i]);e2[v].pb((Edge) {v,u,i});
	}dfs1(1,0);printf("%d\n",n-1);dfs2(1,0);return 0;
}