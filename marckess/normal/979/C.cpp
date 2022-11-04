#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 300005;
vi adj[MX];
int n, u, v, x, y, sz[MX];
bitset<MX> vis;

bool dfs (int u, int v) {
	if (v == u)
		return 1;

	bool f = 0;
	sz[u] = 1;
	vis[u] = 1;
	for (int w : adj[u]) {
		if (vis[w])
			continue;

		if (dfs(w, v)) {
			f = 1;
			continue;
		}

		sz[u] += sz[w];
	}

	return f;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> x >> y;
    for (int i = 1; i < n; i++) {
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    if (n == 1) {
    	cout << 0 << endl;
    	return 0;
    } else if (n == 2) {
    	cout << 1 << endl;
    	return 0;
    }

    dfs(x, y);
    ll d = sz[x];
    vis.reset();
    dfs(y, x);
    ll e = sz[y];

    cout << ll(n) * (n - 1) - d * e << endl;

    return 0;
}