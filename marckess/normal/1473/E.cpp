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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m;
ll dis[4][MX];
vii adj[MX];

typedef pair<ll, ii> iii; 
priority_queue<iii, vector<iii>, greater<iii>> pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	forn (i, 4)
		fill(dis[i], dis[i] + MX, 1e18);
	
	dis[0][1] = 0;
	pq.emplace(0, ii(0, 1));
	
	while (pq.size()) {
		ll d = pq.top().fi;
		ii u = pq.top().se;
		pq.pop();
		
		if (d > dis[u.fi][u.se]) continue;
		
		for (ii &v : adj[u.se]) {
			ll w = d + v.se;
			
			if (dis[u.fi][v.fi] > w) {
				dis[u.fi][v.fi] = w;
				pq.emplace(w, ii(u.fi, v.fi));
			}
		}
		
		if (~u.fi & 1) {
			for (ii &v : adj[u.se]) {
				ll w = d + 2 * v.se;
				
				if (dis[u.fi | 1][v.fi] > w) {
					dis[u.fi | 1][v.fi] = w;
					pq.emplace(w, ii(u.fi | 1, v.fi));
				}
			}
		}
		
		if (~u.fi & 2) {
			for (ii &v : adj[u.se]) {
				ll w = d;
				
				if (dis[u.fi | 2][v.fi] > w) {
					dis[u.fi | 2][v.fi] = w;
					pq.emplace(w, ii(u.fi | 2, v.fi));
				}
			}
		}
		
		if (!u.fi) {
			for (ii &v : adj[u.se]) {
				ll w = d + v.se;
				
				if (dis[u.fi | 3][v.fi] > w) {
					dis[u.fi | 3][v.fi] = w;
					pq.emplace(w, ii(u.fi | 3, v.fi));
				}
			}
		}
	}
	
	for (int i = 2; i <= n; i++)
		cout << dis[3][i] << " ";
	cout << endl;

	return 0;
}