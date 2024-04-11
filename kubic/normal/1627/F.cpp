#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define M 505
#define pb push_back
int T,n,m,cntP,fa[N],dst[N],q[N],a1[M][M],a2[M][M];vector<int> e[N];
int f(int x,int y) {return (x-1)*(m+1)+y;}
int findRt(int u) {return u==fa[u]?u:fa[u]=findRt(fa[u]);}
void merge(int u,int v) {u=findRt(u);v=findRt(v);if(u!=v) fa[u]=v;}
void addE(int u,int v,int w)
{
	u=findRt(u);v=findRt(v);
	for(int i=1;i<w;++i) ++cntP,e[u].pb(cntP),e[cntP].pb(u),u=cntP;
	e[u].pb(v);e[v].pb(u);
}
void bfs(int S)
{
	for(int i=1;i<=cntP;++i) dst[i]=-1;q[0]=2;q[1]=1;dst[S]=0;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(auto v:e[u]) if(dst[v]==-1) dst[v]=dst[u]+1,q[++q[1]]=v;
	}
}
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=cntP;++i) e[i].clear();cntP=(m+1)*(m+1);
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) a1[i][j]=a2[i][j]=0;
	for(int i=1,x1,y1,x2,y2;i<=n;++i)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2) {if(y1>y2) swap(y1,y2);++a1[x1][y2];}
		else {if(x1>x2) swap(x1,x2);++a2[x2][y1];}
		x1=m-x1+1;y1=m-y1+1;x2=m-x2+1;y2=m-y2+1;
		if(x1==x2) {if(y1>y2) swap(y1,y2);++a1[x1][y2];}
		else {if(x1>x2) swap(x1,x2);++a2[x2][y1];}
	}for(int i=1;i<=cntP;++i) fa[i]=i;
	for(int i=1;i<=m+1;++i) for(int j=1;j<=m+1;++j)
	{
		if(i<=m && !a1[i][j]) merge(f(i,j),f(i+1,j));
		if(j<=m && !a2[i][j]) merge(f(i,j),f(i,j+1));
	}
	for(int i=1;i<=m+1;++i) for(int j=1;j<=m+1;++j)
	{
		if(i<=m && a1[i][j]) addE(f(i,j),f(i+1,j),a1[i][j]);
		if(j<=m && a2[i][j]) addE(f(i,j),f(i,j+1),a2[i][j]);
	}bfs(findRt(f(1,1)));printf("%d\n",n-dst[findRt(f(m/2+1,m/2+1))]);
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}