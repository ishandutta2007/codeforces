#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, u, v, sz[MX];
bitset<MX> bs;
vi adj[MX];
ll res = 0;

void dfs (int u, int p) {
	sz[u] = bs[u];

	for (int v : adj[u]) {
		if (p != v) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}

	for (int v : adj[u])
		if (v != p)
			res += min(sz[v], 2 * k - sz[v]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < 2*k; i++) {
		cin >> u;
		bs[u] = 1;
	}

	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(u, u);
	cout << res << endl;

	return 0;
}