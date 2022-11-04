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

const int MX = 300005;
int n, q, p[MX], c[MX], sz[MX], u, v;
vi adj[MX];

void obtSZ (int u) {
	sz[u] = 1;
	for (int v : adj[u]) {
		obtSZ(v);
		sz[u] += sz[v];
	}
}

void dfs (int u) {
	for (int v : adj[u]) dfs(v);

	int ind = -1;
	for (int v : adj[u])
		if (2 * sz[v] > sz[u])
			ind = v;

	if (ind == -1) {
		c[u] = u;
		return;
	}

	c[u] = c[ind];

	while (2 * (sz[u] - sz[c[u]]) > sz[u])
		c[u] = p[c[u]];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}

	obtSZ(1);
	dfs(1);

	while (q--) {
		cin >> u;
		cout << c[u] << endl;
	}

	return 0;
}