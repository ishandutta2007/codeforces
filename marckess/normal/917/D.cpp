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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105, mod = 1000000007;
int n, sz[MX];
ll dp[MX][MX][MX], aux[MX][MX], fac[MX], inv[MX], res[MX];
vi adj[MX];

ll pot (ll b, int p) {
	if (p < 0) return pot(pot(b, -p), mod - 2);

	ll res = 1;
	while (p) {
		if (p & 1) (res *= b) %= mod;
		(b *= b) %= mod;
		p /= 2;
	}
	return res;
}

ll comb (int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void dfs (int u, int p = -1) {
	dp[u][0][1] = 1;
	sz[u] = 1;

	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);

		forn (i, sz[u] + sz[v]) forn (j, sz[u] + sz[v] + 1) aux[i][j] = 0;

		forn (i, sz[u]) forn (j, sz[u] + 1) forn (x, sz[v]) forn (y, sz[v] + 1) {
			ll c = dp[u][i][j] * dp[v][x][y] % mod;
			(aux[i + x + 1][j + y] += c) %= mod;
			(aux[i + x][j] += c * y) %= mod;
		}

		forn (i, sz[u] + sz[v]) forn (j, sz[u] + sz[v] + 1) dp[u][i][j] = aux[i][j];
		sz[u] += sz[v];
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i < MX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = pot(fac[i], mod - 2);
	}

	cin >> n;
	forn (i, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 1; j <= n; j++)
			(res[i] += dp[1][i][j] * j) %= mod;
		(res[i] *= pot(n, n - i - 2)) %= mod;

		for (int j = n - 1; j > i; j--)
			(res[i] -= res[j] * comb(j, i)) %= mod;
	}

	forn (i, n)
		cout << MOD(res[i], mod) << " ";
	cout << endl;

	return 0;
}