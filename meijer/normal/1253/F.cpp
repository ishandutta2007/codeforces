#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
ll n, m, k, q;
ll P[MX];
viii edges;
vii adjList[MX];
set<int> qr[MX];
ll r[MX], p[MX];
ll ans[MX];
ll curAns=0;

void dijkstra() {
    priority_queue<ii, vii, greater<ii>> pq;
    RE(i,n)
    	P[i] = INF;
    RE(i,k)
    	pq.push({0,i}), P[i] = 0;
    while(!pq.empty()) {
    	ii p = pq.top(); pq.pop();
    	ll u = p.se, w = p.fi;
    	if(P[u] != w) continue;
    	for(ii v : adjList[u])
    		if(w+v.se < P[v.fi])
    			pq.push({w+v.se, v.fi}), P[v.fi] = w+v.se;
    }
}

void buildDSU() {RE(i,n) r[i] = 0, p[i] = i;}
int getSet(int i) {return i==p[i] ? i : p[i] = getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i) == getSet(j);}
void unionSet(int i, int j) {
	if(!isSameSet(i, j)) {
		i = getSet(i), j = getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
			for(ll u : qr[j]) {
				if(qr[i].count(u)) {
					qr[i].erase(u);
					ans[u] = curAns;
				} else {
					qr[i].insert(u);
				}
			}
		} else {
			p[i] = j;
			for(ll u : qr[i]) {
				if(qr[j].count(u)) {
					qr[j].erase(u);
					ans[u] = curAns;
				} else {
					qr[j].insert(u);
				}
			}
			if(r[i] == r[j]) r[j]++;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k>>q;
    RE(i,m) {
    	int u, v, w; 
    	cin>>u>>v>>w;
    	u--; v--;
    	adjList[u].pb({v,w});
    	adjList[v].pb({u,w});
    	edges.pb({u,v,w});
    }


    dijkstra();
    buildDSU();
    RE(Q,q) {
    	int a, b;
    	cin>>a>>b; a--; b--;
    	qr[a].insert(Q);
    	qr[b].insert(Q);
    }

    priority_queue<iii, viii, greater<iii>> pq;
    RE(i,m) {
    	ll u, v, w;
    	tie(u,v,w) = edges[i];
    	pq.push({w+P[u]+P[v],u,v});
    }
    while(!pq.empty()) {
    	ll u, v, w;
    	tie(w,u,v) = pq.top(); pq.pop();
    	if(!isSameSet(u,v)) {
    		curAns = w;
    		unionSet(u,v);
    	}
    }

    RE(i,q) cout<<ans[i]<<endl;
}