#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef std::vector<PII> VPII;
const int N=201000;
VPII e[N];
ll dis[N];
int vis[N];
set<pair<ll,int> > hs;
int ord[N],sz[N],dep[N];
const ll inf=1ll<<60;
void dijkstra(int S,int n) {
	rep(i,1,n+1) dis[i]=inf,vis[i]=0;
	dis[S]=0;
	rep(i,1,n+1) hs.insert(mp(dis[i],i));
	rep(i,0,n) {
		int u=hs.begin()->se; hs.erase(hs.begin());
		vis[u]=1; ord[i]=u;
		rep(j,0,SZ(e[u])) {
			int v=e[u][j].fi;
			if (dis[v]>dis[u]+e[u][j].se) {
				hs.erase(mp(dis[v],v));
				dis[v]=dis[u]+e[u][j].se;
				hs.insert(mp(dis[v],v));
			}
		}
	}
}

int n,m,s,u,v,w,p[N][22];

#define LOGN 20
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

int main() {
	scanf("%d%d%d",&n,&m,&s);
	rep(i,0,m) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	dijkstra(s,n);
	p[s][0]=0; dep[s]=1;
	rep(i,1,n) {
		int d=-1; u=ord[i];
		for (auto p:e[u]) {
			if (dis[p.fi]+p.se==dis[u]) {
				if (d==-1) d=p.fi;
				else d=lca(d,p.fi);
			}
		}
		if (dis[u]>(1ll<<50)) assert(d==-1);
		p[u][0]=d; dep[u]=dep[d]+1;
		rep(j,1,21) p[u][j]=p[p[u][j-1]][j-1];
	}
	rep(i,1,n+1) sz[i]=1;
	int ret=0;
	per(i,1,n) {
		u=ord[i];
		sz[p[u][0]]+=sz[u];
		if (dis[u]<=(1ll<<50)) ret=max(ret,sz[u]);
	}
	printf("%d\n",ret);
}