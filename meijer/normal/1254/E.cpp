#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=5e5+1e4, MOD=1e9+7;
int n, begNode, endNode, cntSwaps=0, x, y, p[MX], depth[MX], a[MX], nxt[MX], prv[MX];
vi adj[MX], chl[MX];
vii edgeP[MX];
bitset<MX> visited;
ll fact[MX];

void stop(int type) {
	//cout<<type<<endl;
	cout<<0<<endl;
	exit(0);
}
void dfsChl(int u=1, int parent=0, int d=0) {
	p[u] = parent;
	depth[u] = d;
	for(int v:adj[u])
		if(v != parent)
			dfsChl(v,u,d+1), chl[u].pb(v);
}
void go(int u, int v) {
	if(u == v) stop(0);
	vi begU, begV;
	begU.pb(begNode);
	begV.pb(endNode);
	while(depth[u] > depth[v])
		begU.pb(u), u=p[u];
	while(depth[v] > depth[u])
		begV.pb(v), v=p[v];
	while(u != v)
		begU.pb(u), begV.pb(v), u=p[u], v=p[v];
	begU.pb(u);
	begU.insert(begU.end(), begV.rbegin(), begV.rend());
	REP(i,1,begU.size()-1) {
		edgeP[begU[i]].pb({begU[i-1], begU[i+1]});
	}
	cntSwaps += begU.size()-3;
	if(cntSwaps > 2*n - 2) stop(4);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; begNode = n+1, endNode = n+2;
    RE(i,n-1) cin>>x>>y, adj[x].pb(y), adj[y].pb(x);
    RE1(i,n) cin>>a[i];
    fact[0] = 1;
    REP(i,1,MX) fact[i] = (fact[i-1]*ll(i))%MOD;

    if(n == 1) {
    	cout<<1<<endl;
    	return 0;
    }

    dfsChl();
    RE1(i,n) adj[i].pb(begNode), adj[i].pb(endNode);

    RE1(i,n) if(a[i] != 0) go(i, a[i]);

    RE1(i,n+2) nxt[i]=prv[i]=0;
    visited.reset();
    ll ans = 1;
    RE1(i,n) {
    	//incoming / outcoming edges
    	for(ii p : edgeP[i]) {
    		int u=p.fi, v=p.se;
    		if(nxt[u] && nxt[u] != v) stop(1);
    		if(prv[v] && prv[v] != u) stop(1);
    		nxt[u] = v;
    		prv[v] = u;
    	}

    	//cycles
    	for(int u:adj[i]) if(!visited[u]) {
    		visited[u] = 1;
    		int v = nxt[u];
    		while(v) {
    			if(v == u) stop(2);
    			if(visited[v]) break;
    			visited[v] = 1;
    			v = nxt[v];
    		}
    	}

    	//path beg - end
    	if(nxt[begNode]) {
    		int u=begNode, cnt=1;
    		while(u) {
    			if(u == endNode) break;
    			u = nxt[u];
    			cnt++;
    		}
    		if(u == endNode && cnt < adj[i].size()) stop(3);
    	}

    	//count cycles
    	int cnt=0;
    	for(int u:adj[i]) if(!prv[u] && u <= n) cnt++;
    	if(prv[endNode]) cnt--;
    	if(cnt > 1) ans = (ans*fact[cnt])%MOD;

    	//reset variables
    	for(int u:adj[i]) prv[u]=nxt[u]=visited[u]=0;
    }

	cout<<ans<<endl;
}