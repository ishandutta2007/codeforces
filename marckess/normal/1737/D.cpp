#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, m;
ll dis[MX][MX], mn[MX], to[MX];
vii adj[MX];
vvi ed;

void get_plain_dis (int s, ll dis[]) {
	forr (i, 1, n)
		dis[i] = -1;
	dis[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		for (ii &v : adj[u])
			if (dis[v.fi] == -1) {
				dis[v.fi] = dis[u] + 1;
				q.push(v.fi);
			}
	}
}

void main_() {
	cin >> n >> m;
	
	forn (i, MX)
		adj[i].clear();
	ed.clear();
	
	forn (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		ed.pb({u, v, w});
	}
	
	forr (u, 1, n) {
		get_plain_dis(u, dis[u]);
		
		mn[u] = 1e18;
		for (auto &[v, w] : adj[u])
			mn[u] = min(mn[u], w);
	}
	
	forr (u, 1, n) {
		to[u] = 1e18;
		forr (v, 1, n)
			to[u] = min(to[u], (dis[u][v] + 1) * mn[v]);
	}
	
	ll res = 1e18;
	for (vi &e : ed) {
		int u = e[0];
		int v = e[1];
		int w = e[2];
		
		res = min({
			res,
			w * min({
				dis[1][u] + dis[v][n] + 1,
				dis[1][v] + dis[u][n] + 1,
			}),
		});
		
		forr (k, 1, n)
			res = min({
				res,
				w * min({
					dis[1][k] + dis[k][u] + dis[k][n] + 2,
					dis[1][k] + dis[k][v] + dis[k][n] + 2,
				}),
			});
	}
		
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}