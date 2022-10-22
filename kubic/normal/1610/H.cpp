//???
#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define pb push_back
int n,m,tp,ans,fa[N],dep[N],L[N],R[N],st[N],nxt[N],vl[N];
bool vs[N];vector<int> e[N],vc[N],vc1[N];
struct Node {int u,v;}st1[N]; 
void upd(int x) {for(;x<=n;x+=x&-x) ++vl[x];}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
void dfs1(int u,int f)
{
	fa[u]=f;dep[u]=dep[f]+1;L[u]=++L[0];
	for(auto v:e[u]) if(v!=f) dfs1(v,u);R[u]=L[0];
}
void dfs2(int u,int f)
{
	nxt[st[st[0]]]=u;st[++st[0]]=u;
	for(auto v:vc1[u]) if(nxt[v]) vc[nxt[v]].pb(u);
		else st1[++tp]=(Node) {u,v};
	for(auto v:e[u]) if(v!=f) dfs2(v,u);--st[0];nxt[st[st[0]]]=0;
}
void dfs3(int u,int f)
{
	for(auto v:e[u]) if(v!=f) dfs3(v,u);
	for(auto v:vc[u])
		if(qSm(L[u]-1)==qSm(L[v]-1) && qSm(R[u])==qSm(R[v]))
		{++ans;upd(L[u]);break;}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=2,f;i<=n;++i)
		scanf("%d",&f),e[i].pb(f),e[f].pb(i);dfs1(1,0);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d %d",&u,&v);if(dep[u]>dep[v]) swap(u,v);
		if(u==fa[v]) {puts("-1");return 0;}vc1[v].pb(u);
	}dfs2(1,0);dfs3(1,0);
	for(int i=1,u,v;i<=tp;++i)
	{
		u=st1[i].u;v=st1[i].v;
		if(qSm(R[u])-qSm(L[u]-1)+qSm(R[v])-qSm(L[v]-1)==ans)
		{++ans;break;}
	}printf("%d\n",ans);return 0;
}