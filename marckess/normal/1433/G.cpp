#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, k, dis[MX][MX], a[MX], b[MX];
vii adj[MX];

void dij (int s, int dis[MX]) {
	priority_queue<ii, vii, greater<ii>> pq;
	forn (i, MX) dis[i] = 2e9;
	dis[s] = 0;
	pq.emplace(0, s);
	
	while (pq.size()) {
		int u = pq.top().se;
		int w = pq.top().fi;
		pq.pop();
		
		if (dis[u] < w) continue;
		
		for (ii &v : adj[u])
			if (w + v.se < dis[v.fi]) {
				dis[v.fi] = w + v.se;
				pq.emplace(dis[v.fi], v.fi);
			}
	} 
}

void solve () {
	cin >> n >> m >> k;
	
	forn (i, m) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb(ii(y, w));
		adj[y].pb(ii(x, w));
	}
	
	forn (i, k) cin >> a[i] >> b[i];
	
	for (int i = 1; i <= n; i++)
		dij(i, dis[i]);
	
	ll res = 1e18;
	
	for (int u = 1; u <= n; u++)
		for (ii vv : adj[u]) {
			int v = vv.fi;
			ll p = 0;
			
			forn (i, k) {
				p += min({
					dis[a[i]][b[i]],
					dis[a[i]][u] + dis[v][b[i]],
					dis[a[i]][v] + dis[u][b[i]]
				}); 
			}
			
			res = min(res, p);
		}
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
	
	return 0;
}