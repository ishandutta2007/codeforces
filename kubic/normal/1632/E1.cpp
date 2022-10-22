#include <bits/stdc++.h>
using namespace std;
#define N 300005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int T,n,mx,ord[N],dep[N],z[N],ans[N],fa[N][19];vector<int> e[N],vc[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
bool cmp(int x,int y) {return dep[x]>dep[y];}
void dfs(int u,int f)
{
	fa[u][0]=f;if(f) dep[u]=dep[f]+1;vc[dep[u]].pb(u);mx=max(mx,dep[u]);
	for(int i=1;i<=18;++i) fa[u][i]=fa[fa[u][i-1]][i-1];for(auto v:e[u]) if(v!=f) dfs(v,u);
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=18;i>=0;--i) if(dep[fa[u][i]]>=dep[v]) u=fa[u][i];if(u==v) return u;
	for(int i=18;i>=0;--i) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];return fa[u][0];
}
int dst(int u,int v) {return dep[u]+dep[v]-dep[LCA(u,v)]*2;}
void slv()
{
	n=rd();mx=0;for(int i=0;i<=n;++i) vc[i].clear(),e[i].clear();
	for(int i=1,u,v;i<n;++i) u=rd(),v=rd(),e[u].pb(v),e[v].pb(u);dfs(1,0);
	for(int i=n,u=0,v=0,w=0,t1,t2;i>=0;--i)
	{
		for(auto j:vc[i]) if(u)
		{t1=dst(u,j);t2=dst(v,j);if(w>t1 && w>t2) continue;if(t1<t2) u=j,w=t2;else v=j,w=t1;}
		else u=v=j;z[i]=w;
	}for(int i=1,t=0;i<=n;++i) {while(t<mx && i>t-(z[t+1]+1)/2) ++t;printf("%d ",t);}puts("");
}
int main() {T=rd();while(T--) slv();return 0;}