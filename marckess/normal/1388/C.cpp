#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m;
ll p[MX], h[MX], sz[MX];
ii d[MX];
vi adj[MX];

ii dfs (int u, int par) {
	sz[u] = p[u];

	for (int v : adj[u]) if (v != par) {
		if (dfs(v, u).fi == -1) return {-1, -1};
		sz[u] += sz[v];
	}

	if (sz[u] % 2 != abs(h[u]) % 2 || abs(h[u]) > sz[u]) return {-1, -1};

	if (h[u] > 0) {
		d[u].fi = h[u];
		d[u].fi += (sz[u] - h[u]) / 2;
		d[u].se = (sz[u] - h[u]) / 2;
	} else {
		d[u].se = abs(h[u]);
		d[u].fi = (sz[u] - abs(h[u])) / 2;
		d[u].se += (sz[u] - abs(h[u])) / 2;
	}

	ii f = d[u];

	for (int v : adj[u]) if (v != par) {
		f.fi -= d[v].fi;
		f.se -= d[v].se;
	}

	if (f.fi < 0) return {-1, -1};

	return d[u];
}

void solve () {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		adj[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (dfs(1, 1).fi == -1) cout << "NO" << endl;
	else cout << "YES" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}