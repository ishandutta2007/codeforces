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

const int MX = 50005;
int n, k, cn[MX], sz[MX], ex[MX];
vi adj[MX];
ll res;

void dfs (int u, int p = -1) {
	sz[u] = ex[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
}

void go (int u, int op, int lvl, int p = -1) {
	if (op == 1) cn[lvl]++;
	else if (op == -1) cn[lvl]--;
	else if (k > lvl) res += cn[k - lvl];

	for (int v : adj[u])
		if (ex[v] && v != p)
			go(v, op, lvl + 1, u);
}

void dec (int u) {
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

	go(u, 1, 0);
	res += cn[k];
	cn[0]--;

	for (int v : adj[u])
		if (ex[v]) {
			go(v, -1, 1, u);
			go(v, 0, 1, u);
		}

	ex[u] = 0;

	for (int v : adj[u])
		if (ex[v])
			dec(v);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	dec(1);

	cout << res << endl;

	return 0;
}