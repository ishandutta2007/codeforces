#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,ps,lst,fa[N],dfn[N],dep[N],sz[N],vl[N],ord[N];
int cntZ,r1[N],r2[N];struct Edge {int u,v;}z[N];vector<int> e[N];
void dfs(int u,int f)
{
	fa[u]=f;sz[u]=1;ord[dfn[u]=++dfn[0]]=u;dep[u]=dep[f]+1;
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i];if(v==f) continue;
		if(dfn[v]) {if(dep[u]>dep[v]) ++vl[u],--vl[v];}
		else dfs(v,u),vl[u]+=vl[v],sz[u]+=sz[v];
	}if(vl[u]>1) ps=u;
}
void get(int u,int v,int a[])
{
	a[0]=0;for(int i=dep[v];i>=dep[u];--i) a[++a[0]]=v,v=fa[v];
	for(int i=1;i<=a[0]/2;++i) swap(a[i],a[a[0]-i+1]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;++i) if(!dfn[i]) dfs(i,0);
	if(!ps) {puts("NO");return 0;}puts("YES");
	for(int i=0,u;i<sz[ps];++i)
	{
		u=ord[dfn[ps]+i];
		for(int j=0,v;j<e[u].size();++j)
		{
			if(cntZ>1) break;v=e[u][j];
			if(v!=fa[u] && dep[v]<dep[ps]) z[++cntZ]=(Edge) {u,v};
		}
	}if(dep[z[1].v]<dep[z[2].v]) swap(z[1],z[2]);
	get(z[1].v,z[1].u,r1);get(z[1].v,z[2].u,r2);
	for(int i=1;i<=min(r1[0],r2[0]);++i) if(r1[i]==r2[i]) lst=i;else break;
	printf("%d ",lst);for(int i=1;i<=lst;++i) printf("%d ",r1[i]);
	printf("\n%d ",r1[0]-lst+2);
	printf("%d ",z[1].v);for(int i=r1[0];i>=lst;--i) printf("%d ",r1[i]);
	get(z[2].v,z[1].v,r1);printf("\n%d ",r1[0]+r2[0]-lst+1);
	for(int i=r1[0];i>=1;--i) printf("%d ",r1[i]);
	for(int i=r2[0];i>=lst;--i) printf("%d ",r2[i]);return 0;
}