#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modPow(ll a, ll b, ll p) {
	if (b & 1) return (a * modPow(a, b ^ 1, p)) % p;
	if (b == 0) return 1;
	return modPow(a*a % p, b >> 1, p);
}

const int N = 400;
ll add[N+1];
ll dp0[N+1][N+1];
ll dp[N+2][N+1];
ll fact[N+1];
ll inv_fact[N+1];

ll binom(int a, int b, ll p) {
	if (b > a) return 0;
	ll dv = (inv_fact[a-b] * inv_fact[b]) % p;
	return fact[a] * dv % p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll p;
	cin >> n >> p;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1] * i) % p;
	inv_fact[n] = modPow(fact[n], p - 2, p);
	for (int i = n-1; i >= 0; --i) inv_fact[i] = (inv_fact[i+1] * (i+1)) % p;

	for (int i = 0; i <= n; ++i) {
		dp0[i][0] = 1;
		dp0[0][i] = 1;
	}
	for (int a = 1; a <= n; ++a) {
		for (int b = 1; a + b <= n; ++b) {
			dp0[a][b] = (dp0[a-1][b] + dp0[a][b-1]) % p;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			add[i] += dp0[j][i-1-j];
		}
		add[i] %= p;
	}

	dp[0][0] = 1;
	for (int i = 2; i <= n + 1; ++i) {
		for (int j = 0; j <= i - 2; ++j) {
			int k = i-j-1;
			for (int t = k; t <= i-1; ++t) {
				ll mult = add[i - j - 1] * binom(t, k, p) % p;
				dp[i][t] = (dp[i][t] + dp[j][t - k] * mult) % p;
			}
		}
	}

	ll res = 0;
	for (int t = 1; t <= n; ++t) res = (res + dp[n+1][t]) % p;
	cout << res << '\n';
}