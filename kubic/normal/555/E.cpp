#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,c,fa1[N],vl1[N],vl2[N],dep[N],fa[N][18];
bool ans=1,vs[N];vector<int> e1[N];
int cntE=1,hd[N];struct Edge {int v,nxt;}e[N*2];
int BCC,dfn[N],low[N],st[N],bl[N];
int findRt(int x) {return x==fa1[x]?x:fa1[x]=findRt(fa1[x]);}
void merge(int x,int y) {x=findRt(x);y=findRt(y);if(x!=y) fa1[x]=y;}
void addE(int u,int v) {e[++cntE]=(Edge) {v,hd[u]};hd[u]=cntE;}
void Tarjan(int u,int fe)
{
	dfn[u]=low[u]=++dfn[0];st[++st[0]]=u;
	for(int i=hd[u],v;i;i=e[i].nxt)
	{
		v=e[i].v;if(i==(fe^1)) continue;
		if(!dfn[v]) Tarjan(v,i),low[u]=min(low[u],low[v]);
		else if(!bl[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		bl[u]=++BCC;
		while(st[st[0]]!=u) bl[st[st[0]--]]=BCC;--st[0];
	}
}
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1;fa[u][0]=f;
	for(int i=1;i<=17;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0,v;i<e1[u].size();++i) {v=e1[u][i];if(v!=f) dfs1(v,u);}
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=17;i>=0;--i) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=17;i>=0;--i) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs2(int u,int f)
{
	for(int i=0,v;i<e1[u].size();++i)
	{
		v=e1[u][i];
		if(v!=f) dfs2(v,u),vl1[u]+=vl1[v],vl2[u]+=vl2[v];
	}if(vl1[u] && vl2[u]) ans=0;vs[u]=1;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);for(int i=1;i<=n;++i) fa1[i]=i;
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),merge(u,v),addE(u,v),addE(v,u);
	for(int i=1;i<=n;++i) if(!dfn[i]) Tarjan(i,0);
	for(int i=1,u,v;i<=n;++i) for(int j=hd[i];j;j=e[j].nxt)
	{u=bl[i];v=bl[e[j].v];if(u!=v) e1[u].push_back(v);}
	for(int i=1;i<=BCC;++i) if(!dep[i]) dfs1(i,0);
	for(int i=1,u,v,t;i<=c;++i)
	{
		scanf("%d %d",&u,&v);
		if(findRt(u)!=findRt(v)) {puts("No");return 0;}
		u=bl[u];v=bl[v];t=LCA(u,v);++vl1[u];--vl1[t];++vl2[v];--vl2[t];
	}for(int i=1;i<=BCC;++i) if(!vs[i] && ans) dfs2(i,0);
	puts(ans?"Yes":"No");return 0;
}