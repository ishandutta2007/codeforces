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

const ll inf=1ll<<60;
const int N=10100;
vector<PII> e[N];
ll dis[N];
int vis[N];
set<pair<ll,int> > hs;
int u[N],v[N],w[N],n,m,L,s,t;
VI eg;
void dijkstra(int S,int n) {
	rep(i,0,n) dis[i]=inf,vis[i]=0;
	dis[S]=0;
	rep(i,0,n) hs.insert(mp(dis[i],i));
	rep(i,0,n) {
		int u=hs.begin()->se; hs.erase(hs.begin());
		vis[u]=1;
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

ll check(ll x) {
	rep(i,0,SZ(eg)) {
		w[eg[i]]=1+min(x,1000000000ll);
		x-=w[eg[i]]-1;
	}
	rep(i,0,n) e[i].clear();
	rep(i,0,m) {
		e[u[i]].pb(mp(v[i],w[i]));
		e[v[i]].pb(mp(u[i],w[i]));
	}
	dijkstra(s,n);
	return dis[t];
}
int main() {
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);
	rep(i,0,m) {
		scanf("%d%d%d",u+i,v+i,w+i);
		if (w[i]==0) eg.pb(i);
	}
	ll l=-1,r=1000000000ll*SZ(eg);
	if (check(0)>L||check(r)<L) {
		puts("NO");
		return 0;
	}
	puts("YES");
	while (l+1<r) {
		ll md=(l+r)>>1;
		if (check(md)>=L) r=md; else l=md;
	}
	check(r);
	rep(i,0,m) {
		printf("%d %d %d\n",u[i],v[i],w[i]);
	}
}