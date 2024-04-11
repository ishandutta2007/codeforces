#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define set(a,v) memset(a,v,sizeof(a))
int n,m,dep[N],fa[N][25];
int cntE,hd[N];struct Edge {int v,nxt;}e[N<<1];
void addE(int u,int v) {e[++cntE]=(Edge) {v,hd[u]};hd[u]=cntE;}
void dfs(int u,int f)
{
	fa[u][0]=f;dep[u]=dep[f]+1;
	for(int i=hd[u],v;~i;i=e[i].nxt) {v=e[i].v;if(v!=f) dfs(v,u);}
}
void init()
{
	for(int i=1;i<=20;++i) for(int j=1;j<=n;++j)
		fa[j][i]=fa[fa[j][i-1]][i-1];
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) u^=v^=u^=v;
	for(int i=20;i>=0;--i) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if(u==v) return u;
	for(int i=20;i>=0;--i) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dst(int u,int v) {return dep[u]+dep[v]-(dep[LCA(u,v)]<<1);}
bool chk(int x,int y) {return x<=y && !(y-x&1);}
int main()
{
	set(hd,-1);scanf("%d",&n);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),addE(u,v),addE(v,u);
	dfs(1,0);init();scanf("%d",&m);
	for(int i=1,x,y,a,b,c,t;i<=m;++i)
	{
		scanf("%d %d %d %d %d",&x,&y,&a,&b,&c);
		t=dst(a,b);if(chk(t,c)) {puts("YES");continue;}
		t=dst(a,x)+1+dst(y,b);if(chk(t,c)) {puts("YES");continue;}
		t=dst(a,y)+1+dst(x,b);if(chk(t,c)) {puts("YES");continue;}
		puts("NO");
	}return 0;
}