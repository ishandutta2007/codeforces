#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef pair<int,int> PII;
// head

const int N=301000;
int bcp[N],n,m,u,v,R,q,_n,_m;
VI vE[N],r;
vector<PII> E;
set<int> hs;
map<int,int> hs2;
namespace biconnect {
int vis[N],dep[N],f[N],p[N],bcp[N],v2[N],m;
VI e[N];
void dfs(int u) {
	vis[u]=1; dep[u]=dep[p[u]]+1;
	for (auto v:e[u]) if (!vis[v]) p[v]=u,dfs(v);
}
int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
void solve(int n,vector<PII> E) {
	rep(i,1,n+1) e[i].clear(),vis[i]=v2[i]=0,f[i]=i,p[i]=0;
	for (auto p:E) e[p.fi].pb(p.se),e[p.se].pb(p.fi);
	rep(i,1,n+1) if (!vis[i]) dfs(i);
	for (auto r:E) {
		int u=r.fi,v=r.se;
		if (p[u]==v) swap(u,v);
		if (p[v]==u&&!v2[v]) {
			v2[v]=1; 
			continue;
		}
		u=find(u); v=find(v);
		while (u!=v) {
			if (dep[u]>dep[v]) swap(u,v);
			v=find(v); f[v]=find(p[v]);
			v=find(v);
		}
	}
	m=0;
	rep(i,1,n+1) if (find(i)==i) bcp[i]=++m;
	rep(i,1,n+1) bcp[i]=bcp[find(i)];
}
void build() {
	rep(i,1,n+1) if (find(i)==i&&p[i]!=0) {
		int u=bcp[i],v=bcp[find(p[i])];
		vE[u].pb(v);
		vE[v].pb(u);
	}
}
};

#define LOGN 18
namespace compact {
int l[N],r[N],tot,dep[N],p[N][20],vis[N],n;
map<int,int> cv;
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
void dfs(int u,int f) {
	l[u]=++tot; dep[u]=dep[f]+1; p[u][0]=f; vis[u]=1;
	for (auto v:vE[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
	r[u]=tot;
}
void build(int _n) {
	n=_n;
	rep(i,1,n+1) if (!vis[i]) dfs(i,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
}

bool cmp(int u,int v) { return l[u]<l[v]; }
void compact(VI v) {
	int m=SZ(v);
	sort(all(v),cmp);
	rep(i,0,m-1) {
		int w=lca(v[i],v[i+1]);
		v.pb(w); hs.insert(w);
	}
	v.pb(0);
	sort(all(v),cmp); 
	v.erase(unique(all(v)),v.end());
	cv.clear();
	per(i,1,SZ(v)) {
		int u=v[i];
		while (1) {
			auto it=cv.lower_bound(l[u]);
			if (it==cv.end()||it->fi>r[u]) break;
			E.pb(mp(u,v[it->se]));
			cv.erase(it);
		}
		cv[l[u]]=i;
	}
}
};
void rot(int &u) {
	u=(u+R+n-1)%n+1;
	u=bcp[u];
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		E.pb(mp(u,v));
	}
	biconnect::solve(n,E);
	rep(i,1,n+1) bcp[i]=biconnect::bcp[i];
	biconnect::build();
	compact::build(biconnect::m);
	rep(i,0,q) {
		scanf("%d%d",&_n,&_m);
		E.clear();
		hs.clear();
		r.clear();
		rep(j,0,_n) {
			scanf("%d",&u); rot(u); r.pb(u);
			hs.insert(u);
		}
		rep(j,0,_m) {
			scanf("%d%d",&u,&v);
			rot(u); rot(v);
			E.pb(mp(u,v));
			hs.insert(u); hs.insert(v);
		}
		compact::compact(VI(all(hs)));
		hs2.clear();
		int id=0;
		for (auto p:hs) hs2[p]=++id;
		rep(j,0,SZ(E)) E[j].fi=hs2[E[j].fi],E[j].se=hs2[E[j].se];
		biconnect::solve(id,E);
		bool val=1;
		rep(i,0,SZ(r)) r[i]=hs2[r[i]];
		rep(i,1,SZ(r)) if (biconnect::bcp[r[i]]!=biconnect::bcp[r[0]]) val=0;
		puts(val?"YES":"NO");
		if (val) R=(R+i+1)%n;
	}
}