#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}
ll modPow(ll a, ll b) {
	if (b & 1) return (a * modPow(a, b ^ 1)) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 200;
vector<int> g[N];
ll dp[N + 1][N + 1];
int dist[N][N];

void dfs(int i, int s) {
	for (int t : g[i]) {
		if (dist[s][t] > dist[s][i] + 1) {
			dist[s][t] = dist[s][i] + 1;
			dfs(t, s);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) dist[i][j] = n + 1;
		dist[i][i] = 0;
		dfs(i, i);
	}

	ll two_inv = modPow(2, MOD - 2);
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= n; ++b) {
			if (a == 0) dp[a][b] = 1;
			else if (b == 0) dp[a][b] = 0;
			else dp[a][b] = ((dp[a-1][b] + dp[a][b-1]) * two_inv) % MOD;
		}
	}

	ll res = 0;
	ll n_inv = modPow(n, MOD - 2);
	for (int a = 0; a < n; ++a) {
		for (int b = a + 1; b < n; ++b) {
			int k = dist[a][b];
			vector<int> counts(k + 1);
			for (int i = 0; i < n; ++i) {
				int d = (k + dist[b][i] - dist[a][i]) / 2;
				++counts[d];
			}

			for (int j = 0; j <= k; ++j) {
				ll ch = (counts[j] * n_inv) % MOD;
				ll prob_b = dp[j][k - j] * ch % MOD;
				res = mAdd(res, prob_b);
			}
		}
	}
	cout << res << '\n';
}