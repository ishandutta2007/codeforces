#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m;
ll dis[52 * MX];
vii adj[MX];

void dij (int s) {
	priority_queue<ii, vii, greater<ii>> pq;
	pq.emplace(0, s);
	dis[s] = 0;
	
	while (pq.size()) {
		int u = pq.top().se / 51;
		int t = pq.top().se % 51;
		ll d = pq.top().fi;
		pq.pop();
		
		if (d > dis[u * 51 + t]) continue;
		
		for (ii &v : adj[u]) {
			int to;
			ll w;
			
			if (t) {
				w = d + (t + v.se) * (t + v.se);
				to = 51 * v.fi;
			} else {
				w = d;
				to = 51 * v.fi + v.se;
			}
			
			if (dis[to] == -1 || dis[to] > w)
				pq.emplace(dis[to] = w, to);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	memset(dis, -1, sizeof(dis));
	dij(51);
	
	for (int i = 1; i <= n; i++)
		cout << dis[51 * i] << " ";
	cout << endl;
	
	return 0;
}