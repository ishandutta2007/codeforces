#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define MP make_pair
#define UNDEF -1
#define INF 99999999999LL
using namespace std;
typedef long long ll;
typedef long double ld;
ll dist[408];
vector<ll> g[408];
bool adj[408][408];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m;
	cin >> n; cin >> m;
	for (ll x = 1; x <= n; x++) {
		for (ll y = 1; y <= n; y++) {
			adj[x][y] = false;
		}
	}
	for (ll i = 0; i < m; i++) {
		ll u,v; cin >> u; cin >> v;
		g[u].PB(v);
		g[v].PB(u);
		adj[u][v] = true;
		adj[v][u] = true;
	}
	if (adj[1][n]) {
		for (ll x = 1; x <= n; x++) {
			g[x].clear();
		}
		for (ll x = 1; x <= n; x++) {
			for (ll y = 1; y <= n; y++) {
				if (x == y) continue;
				if (!adj[x][y]) {
					g[x].PB(y);
					g[y].PB(x);
					adj[x][y] = true;
					adj[y][x] = true;
				}
			}
		}
	}
	for (ll x = 1; x <= n; x++) {
		dist[x] = INF;
	}
	queue<ll> q;
	dist[1] = 0;
	q.push(1);
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (auto& a: g[x]) {
			if (dist[a] == INF) {
				dist[a] = dist[x]+1;
				q.push(a);
			}
		}
	}
	if (dist[n] == INF) {
		cout << -1 << endl;
	}
	else {
		cout << dist[n] << endl;
	}
}