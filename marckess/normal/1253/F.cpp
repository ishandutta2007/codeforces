#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

struct Edge {
	int u, v;
	ll w;
	bool operator < (const Edge &ot) const {
		return w < ot.w;
	}
};

const int MX = 100005;
int n, m, k, q, from[MX], p[MX], rk[MX];
ll d[MX], w[MX];
vector<Edge> e;
vii adj[MX];

int parent (int u) {
	return u == p[u] ? u : parent(p[u]);
}

void join (int u, int v, ll d) {
	u = parent(u), v = parent(v);
	if (u == v) return;
	if (rk[u] < rk[v]) swap(u, v);
	p[v] = u, w[v] = d;
	if (rk[u] == rk[v]) rk[u]++; 
}

ll query (int u, int v) {
	ll res = 0;
	while (u != v) {
		if (rk[u] > rk[v]) swap(u, v);
		res = max(res, w[u]);
		u = p[u];
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p, p+MX, 0);
	memset(d, -1, sizeof(d));
		
	cin >> n >> m >> k >> q;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u <= k && v <= k)
			e.pb({u, v, w});
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	priority_queue<ii, vii, greater<ii>> pq;
 	for (int i = 1; i <= k; i++) {
 		pq.emplace(0, i);
 		d[i] = 0;
 		from[i] = i;
 	}

 	while (pq.size()) {
 		ll w = pq.top().fi;
 		int u = pq.top().se;
 		pq.pop();

 		if (w > d[u]) continue;

 		for (ii &v : adj[u]) {
 			if (d[v.fi] == -1 || d[v.fi] > w + v.se) {
 				d[v.fi] = w + v.se;
 				from[v.fi] = from[u];
 				pq.emplace(d[v.fi], v.fi);
 			}
 		}
 	}

 	for (int u = 1; u <= n; u++)
 		for (ii &v : adj[u])
 			if (from[u] != from[v.fi])
 				e.pb({from[u], from[v.fi], d[u] + d[v.fi] + v.se});

 	sort(all(e));

 	for (auto &x : e)
 		join(x.u, x.v, x.w);

 	while (q--) {
 		int u, v;
 		cin >> u >> v;
 		cout << query(u, v) << endl;
 	}

	return 0;
}