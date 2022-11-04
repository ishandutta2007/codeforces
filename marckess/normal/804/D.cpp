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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, q, in[MX], x[MX], y[MX], dis[MX], diam[MX];
ll sz[MX];
vi adj[MX], c[MX];
vector<ld> acu[MX];
map<ii, ld> mem;

void add (int u, int k) {
	if (k > x[u]) {
		y[u] = x[u];
		x[u] = k;
	} else if (k > y[u]) {
		y[u] = k;
	}
}

void dfs1 (int u, int p) {
	sz[in[u]]++;

	for (int v : adj[u])
		if (v != p) {
			in[v] = in[u];
			dfs1(v, u);
			add(u, x[v] + 1);
		}

	
	if (adj[u].size() < 2) add(u, 0);
	dis[u] = x[u];
	diam[in[u]] = max(diam[in[u]], x[u] + y[u]);
}

void dfs2 (int u, int p, int w) {
	dis[u] = max(dis[u], w);
	c[in[u]][dis[u]]++;

	for (int v : adj[u])
		if (v != p) {
			if (x[v] + 1 == x[u]) dfs2(v, u, max(w, y[u]) + 1);
			else dfs2(v, u, max(w, x[u]) + 1);
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(8);

	cin >> n >> m >> q;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++)
		if (!in[i]) {
			in[i] = i;
			dfs1(i, i);
			
			c[i].resize(diam[i] + 1);
			acu[i].resize(diam[i] + 1);

			dfs2(i, i, 0);

			ll sum = 0, act = 0;
			for (int j = diam[i]; j >= 0; j--) {
				act += c[i][j];
				sum += act;
				acu[i][j] = sum;
			}
		}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a = in[a], b = in[b];

		if (a == b) {
			cout << -1 << endl;
			continue;
		}

		if (diam[a] > diam[b]) swap(a, b);

		if (!mem.count(ii(a, b))) {
			ld res = sz[a] * sz[b] * diam[b];
			for (int k = 0, j = diam[b]; k <= diam[a]; k++, j--)
				res += c[a][k] * acu[b][j];
			res /= sz[a] * sz[b];
			
			mem[ii(a, b)] = res;
		}

		cout << mem[ii(a, b)] << endl;
	}

	return 0;
}