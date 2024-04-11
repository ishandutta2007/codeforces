#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define pb push_back
int n,dg[N],sz[N],L[N],R[N];vector<int> e[N];
void dfs1(int u,int f)
{
	sz[u]=1;
	for(auto v:e[u]) if(v!=f)
		dfs1(v,u),++dg[u],sz[u]+=sz[v];
}
void dfs2(int u,int f,int x)
{
	int nw1=0,nw2=0;L[u]=x;R[u]=x+dg[u]+1;
	for(auto v:e[u]) if(v!=f)
	{
		dfs2(v,u,R[u]-nw1+nw2*2);
		L[v]=x+dg[u]-nw1;++nw1;nw2+=sz[v];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs1(1,0);dfs2(1,0,1);
	for(int i=1;i<=n;++i) printf("%d %d\n",L[i],R[i]);
	return 0;
}