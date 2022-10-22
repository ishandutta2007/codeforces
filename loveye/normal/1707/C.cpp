#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5,M=2e5+5;
int n,m;
vector<int> G[N],T[N];
int U[M],V[M],tot;
int du[N];
int f[N]; int getf(int x) {return x==f[x]?x:f[x]=getf(f[x]);}
int ans[N];

int bz[N][17],dep[N],dfn[N],dfc,siz[N];
void dfs(int u,int fa) {
	dfn[u]=++dfc;
	dep[u]=dep[fa]+1;
	bz[u][0]=fa;
	fr(i,1,16) bz[u][i]=bz[bz[u][i-1]][i-1];
	siz[u]=1;
	//cerr<<u<<' '<<fa<<endl;
	for(auto v:T[u]) if(v!=fa) dfs(v,u),siz[u]+=siz[v];
}
int d[N];
int LCA(int u,int v) {
	if(dep[u]<dep[v]) swap(u,v);
	rf(i,16,0) if(dep[u]-dep[v]>>i&1) u=bz[u][i];
	if(u==v) return u;
	rf(i,16,0) if(bz[u][i]^bz[v][i]) u=bz[u][i],v=bz[v][i];
	return bz[u][0];
}
int main() {
	cin>>n>>m;
	fr(i,1,n) f[i]=i;
	for(int i=1,u,v;i<=m;++i) {
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		if(getf(u)^getf(v)) {
			f[getf(u)]=getf(v);
			T[u].push_back(v);
			T[v].push_back(u);
		} else {
			++tot; U[tot]=u; V[tot]=v;
		}
	}
	dfs(1,0);
	fr(i,1,tot) {
		int u=U[i],v=V[i];
		if(dep[u]<dep[v]) swap(u,v);
		int lca=LCA(u,v);
		if(lca==v) {
			++d[dfn[u]]; --d[dfn[u]+siz[u]];
			rf(i,16,0) if(dep[u]-dep[v]-1>>i&1) u=bz[u][i];
			++d[1]; --d[dfn[u]]; ++d[dfn[u]+siz[u]];
		} else {
			++d[dfn[u]]; --d[dfn[u]+siz[u]];
			++d[dfn[v]]; --d[dfn[v]+siz[v]];
		}
	}
	fr(i,1,n) d[i]+=d[i-1];
	fr(i,1,n) putchar('0'|(d[dfn[i]]==tot));
	puts("");
	return 0;
}