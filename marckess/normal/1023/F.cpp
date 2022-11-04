#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, k, m, x[MX], y[MX], w[MX], u, v;
vii adj[MX];
int ds[MX], p[MX], lvl[MX], t[MX];
ll res = 0;

int find (int a) { return a == ds[a] ? a : ds[a] = find(ds[a]); }
int parent (int a) { return p[find(a)]; }
int type (int a) { return t[find(a)]; }
bool same (int a, int b) { return find(a) == find(b); }

bool joint (int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	if (lvl[p[a]] > lvl[p[b]]) p[a] = p[b], t[a] = t[b];
	ds[b] = a;
	return 1;
}

void dfs (int u) {
	for (ii &v : adj[u])
		if (v.fi != p[u]) {
			p[v.fi] = u;
			lvl[v.fi] = lvl[u]+1;
			t[v.fi] = v.se;
			dfs(v.fi);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> m;
	iota(ds, ds+MX, 0);
	while (k--) {
		cin >> u >> v;
		joint(u, v);
		adj[u].emplace_back(v, 1);
		adj[v].emplace_back(u, 1);
	}

	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		if (joint(x[i], y[i])) {
			adj[x[i]].emplace_back(y[i], 0);
			adj[y[i]].emplace_back(x[i], 0);
		}
	}

	p[1] = 0, lvl[1] = 1, t[1] = 0;
	dfs(1);

	iota(ds, ds+MX, 0);

	for (int i = 0; i < m; i++) {
		u = find(x[i]), v = find(y[i]);

		while (!same(u, v)) {
			if (lvl[parent(u)] < lvl[parent(v)]) swap(u, v);
			if (type(u)) res += w[i];
			joint(u, parent(u));
		}
	}

	for (int i = 2; i <= n; i++)
		if (!same(1, i)) {
			cout << -1 << endl;
			return 0;
		}

	cout << res << endl;

	return 0;
}