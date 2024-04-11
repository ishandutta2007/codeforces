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

const int MX = 3005, mod = 1'000'000'007;
int dp[MX][MX], comb[MX][MX];
ll res = 0, f[MX];
int n, d, p;
vi adj[MX];

ll pot (ll b, int p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % mod;
		b = b * b % mod;
		p /= 2;
	}
	return res;
}

int c (int n, int k) {
	if (k < 0 || n < 0 || n < k) return 0;
	if (k == 0 || k == n) return 1;

	if (comb[n][k] == -1)
		comb[n][k] = (c(n-1, k) + c(n-1, k-1)) % mod;
	return comb[n][k];
}

void dfs (int u) {
	for (int v : adj[u])
		dfs(v);

	for (int i = 1; i <= n; i++) {
		ll acu = 1;
		for (int v : adj[u])
			acu = acu * dp[v][i] % mod;
		dp[u][i] = (dp[u][i-1] + acu) % mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			comb[i][j] = -1;

	cin >> n >> d;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
	}

	dfs(1);

	ll fac = 1;
	for (int i = 1; i <= min(n, d); i++) {
		f[i] = dp[1][i];
		for (int j = 1; j < i; j++) {
			f[i] -= f[j] * c(i, j) % mod;
			f[i] %= mod;
		}
		fac *= (d - i + 1) * pot(i, mod-2) % mod;
		fac %= mod;
		res += f[i] * fac % mod;
		res %= mod;
	}

	if (res < 0) res += mod;
	cout << res << endl;

	return 0;
}