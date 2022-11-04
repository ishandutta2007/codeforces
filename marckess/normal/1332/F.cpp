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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005, mod = 998244353;
int n;
vi cn[MX], adj[MX];

void dfs (int u, int p = -1) {
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);

	// Si
	vi y = {1, 0, 1, 0};

	for (int v : adj[u])
		if (v != p) {
			(y[1] = y[0] * cn[v][3] % mod
				  + y[1] * cn[v][0] % mod
				  + y[1] * cn[v][3] % mod
			) %= mod;

			(y[0] = y[0] * cn[v][0] % mod
			) %= mod;

			(y[2] = y[2] * cn[v][0] % mod
				  + y[2] * cn[v][3] % mod
			) %= mod;
		}

	cn[u] = {y[1], 0, y[2], 0};

	// No
	y = {1, 0, 1, 1};

	for (int v : adj[u])
		if (v != p) {
			(y[1] = y[0] * cn[v][2] % mod
				  + y[1] * cn[v][0] % mod
				  + y[1] * cn[v][2] % mod
			) %= mod;

			(y[0] = y[0] * cn[v][0] % mod
			) %= mod;

			(y[2] = y[2] * cn[v][0] % mod
				  + y[2] * cn[v][2] % mod
			) %= mod;

			(y[3] = y[3] * cn[v][0] % mod
				  + y[3] * cn[v][2] % mod
			) %= mod;
		}

	cn[u] = {cn[u][0] + y[0] + y[1], 0, cn[u][2] + y[2], y[3]};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1);
	cout << MOD(cn[1][0] - 1, mod) << endl;

	return 0;
}