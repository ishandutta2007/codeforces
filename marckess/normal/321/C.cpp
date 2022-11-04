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
int n, sz[MX], ex[MX], res[MX];
vi adj[MX];

void dfs (int u, int p = -1) {
	sz[u] = ex[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
}

void cd (int u, int lvl) {
	while (1) {
		int ind = -1;

		for (int v : adj[u])
			if (ex[v] && 2 * sz[v] > sz[u])
				ind = v;

		if (ind == -1) break;

		swap(sz[u], sz[ind]);
		sz[u] = sz[ind] - sz[u];
		u = ind;
	}

	res[u] = lvl;
	ex[u] = 0;

	for (int v : adj[u])
		if (ex[v])
			cd(v, lvl + 1);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	cd(1, 0);

	for (int i = 1; i <= n; i++)
		cout << char(res[i] + 'A') << " ";
	cout << endl;

	return 0;
}