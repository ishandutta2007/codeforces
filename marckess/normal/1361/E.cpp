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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, x[MX], y[MX], lvl[MX], q[MX], vis[MX], res[MX], anc[MX], cn;
vi adj[MX];

void clear () {
	for (int i = 1; i <= n; i++)
		adj[i].clear();

	iota(q, q + n, 1);
	shuffle(q, q + n, rng);
}

void add (int u, int k) {
	if (x[u] > k) {
		y[u] = x[u];
		x[u] = k;
	} else if (y[u] > k) {
		y[u] = k;
	}
}

bool dfs (int u) {
	cn++;
	vis[u] = 1;
	x[u] = y[u] = MX;

	for (int v : adj[u]) {
		if (vis[v] == 2) return 0;

		if (vis[v]) {
			add(u, lvl[v]);
			continue;
		}

		lvl[v] = lvl[u] + 1;
		if (!dfs(v)) return 0;

		add(u, x[v]);
		add(u, y[v]);
	}

	if (x[u] == lvl[u]) x[u] = MX;
	if (y[u] == lvl[u]) y[u] = MX;

	if (y[u] < MX) res[u] = 0;

	vis[u] = 2;
	return 1;
}

void dfs2 (int u) {
	vis[u] = 1;
	anc[lvl[u]] = u;

	if (res[u] == -1 && lvl[u]) {
		if (x[u] < MX) res[u] = res[anc[x[u]]];
		else res[u] = 0;
	}

	for (int v : adj[u])
		if (!vis[v])
			dfs2(v);
}

void solve () {
	cin >> n >> m;
	clear();

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	forn (i, min(n, 80)) {
		forn (j, n) vis[j + 1] = 0, res[j + 1] = -1;
		lvl[q[i]] = 0; 
		cn = 0;
		
		if (!dfs(q[i]) || cn < n) continue;

		res[q[i]] = 1;
		forn (j, n) vis[j + 1] = 0;
		dfs2(q[i]);

		vi r;
		for (int j = 1; j <= n; j++)
			if (res[j] == 1)
				r.pb(j);

		if (5 * r.size() < n) cout << -1 << endl;
		else {
			for (int x : r)
				cout << x << " ";
			cout << endl;
		}

		return;
	}

	cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}