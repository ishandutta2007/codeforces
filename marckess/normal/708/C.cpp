#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 400005;

int n, u, v, sz[MX], res[MX];
vi adj[MX];

void dfs (int u, int p) {
	sz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			dfs(v, u);
			sz[u] += sz[v];
		}
}

int findCentroid (int u) {
	while (1) {
		int ind = -1;

		for (int v : adj[u])
			if (2 * sz[v] > n)
				ind = v;

		if (ind == -1) break;

		sz[u] = n - sz[ind];
		u = ind;
	}
	
	return u;
}

void obtRes (int u, int p, int mx) {
	int temp = sz[u];
	
	if (p == -1 || 2 * sz[p] <= n || 2 * (sz[p] - mx) <= n)
		res[u] = 1;

	vi a;
	for (int v : adj[u])
		if (2 * sz[v] <= n)
			a.push_back(sz[v]);

	sort(ALL(a));

	for (int v : adj[u])
		if (v != p) {
			sz[u] = n - sz[v];
			obtRes(v, u, max( {
					mx,
					2 * sz[u] <= n ? sz[u] : 0,
					a.size() ? (a.back() != sz[v] ? a.back() : (a.size() > 1 ? a[a.size()-2] : 0 )) : 0
				}));
		}

	sz[u] = temp;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	if (n == 2) {
		cout << "1 1" << endl;
		return 0;
	}

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);
	obtRes(findCentroid(1), -1, 0);

	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}