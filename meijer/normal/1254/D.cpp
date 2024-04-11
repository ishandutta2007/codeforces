#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=2e5, MOD=998244353;
int n, q, a, b;
vi adjList[MX], children[MX];
ll sz[MX], parent[MX], nodeID[MX], nodes=0;
vector<pair<int, ii>> updates[MX];
ll ft[MX];

ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}

ll dfs(ll u=0, ll p=-1) {
	parent[u] = p;
	sz[u] = 1;
	for(ll v:adjList[u])
		if(v != p)
			sz[u]+=dfs(v, u), children[u].pb(v);
	sort(children[u].begin(), children[u].end(), [](ll i, ll j) {
		return sz[i] < sz[j];
	});
	return sz[u];
}
void dfsPre(ll u=0) {
	nodeID[u] = nodes++;
	for(ll v:children[u])
		dfsPre(v);
}
ll get(int x) {
	ll ans=0;
	for(x++; x >= 1; x-=x&-x)
		ans += ft[x];
	return ans%MOD;
}
void add(int x, ll v) {
	for(x++; x<=n; x+=x&-x)
		ft[x] += v;
}
void add(int x, int y, ll v) {
	add(x, v);
	add(y+1, -v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d%d", &n, &q);
    RE(i,n-1) scanf("%d%d", &a, &b), a--, b--, adjList[a].pb(b), adjList[b].pb(a);
    dfs();
    dfsPre();
    RE(i,n) {
    	if(children[i].size() == 0) continue;
    	ll curSz=-1, curB, curE;
    	for(ll v:children[i]) {
    		if(curSz == -1) {
    			curSz = sz[v];
    			curB  = nodeID[v];
    			curE  = curB+curSz-1;
    		} else if(curSz != sz[v]) {
    			updates[i].pb({ll(n-curSz),{curB,curE}});
    			curSz = sz[v];
    			curB  = nodeID[v];
    			curE  = curB+curSz-1;
    		} else {
    			curE += curSz;
    		}
    	}
    	updates[i].pb({ll(n-curSz),{curB,curE}});
    }
    ll INV=inv(n);
   	RE(Q,q) {
   		int t, v;
   		scanf("%d", &t);
   		if(t == 1) {
   			ll d;
   			scanf("%d%lld", &v, &d);
   			v--;
   			add(nodeID[v], nodeID[v], d*ll(n));
   			RE(i,updates[v].size())
   				add(updates[v][i].se.fi, updates[v][i].se.se, d*updates[v][i].fi);
   			add(0, d*sz[v]);
   			add(nodeID[v], nodeID[v]+sz[v]-1, -d*sz[v]);
   		}
   		if(t == 2) {
   			scanf("%d", &v); v--;
   			printf("%lld\n", (get(nodeID[v])*INV)%MOD);
   		}
   	}
}