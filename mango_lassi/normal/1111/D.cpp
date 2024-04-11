#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 1e5;
const int C = 26 * 2;
ll dp[2*N+1];
ll tmp[2*N+1];
ll tmp2[2*N+1];
ll fact[N+1];
ll ans[C][C];
ll cou[C];

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return (a * modPow(a, b-1)) % MOD;
	else return modPow((a*a) % MOD, b / 2);
}

int getInd(char c) {
	if ('a' <= c && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	for (auto c : str) ++cou[getInd(c)];

	int n = str.size();

	// Initial calculation
	dp[n] = 1;
	for (int j = 0; j < C; ++j) {
		if (cou[j] == 0) continue;
		for (int i = cou[j]; i <= 2*n - cou[j]; ++i) {
			tmp[i-cou[j]] += dp[i];
			tmp[i+cou[j]] += dp[i];
		}
		for (int i = 0; i <= 2*n; ++i) {
			dp[i] = tmp[i] % MOD;
			tmp[i] = 0;
		}
	}

	// For all pairs, undo
	for (int a = 0; a < C; ++a) {
		for (int b = a+1; b < C; ++b) {
			int ca = cou[a];
			int cb = cou[b];
			if (ca == 0 || cb == 0) continue;
			for (int i = 2*n; i >= n; --i) {
				tmp[i - ca] = dp[i] - (i+ca <= 2*n ? tmp[i + ca] : 0);
				tmp2[i - cb] = tmp[i] - (i+cb <= 2*n ? tmp2[i + cb] : 0);
			}

			ans[a][b] = tmp2[n+ca+cb] % MOD;
			if (ans[a][b] < 0) ans[a][b] += MOD;
			ans[b][a] = ans[a][b];

			for (int i = n; i <= 2*n; ++i) {
				tmp[i] = 0;
				tmp2[i] = 0;
			}
		}
	}
	// Answer queries
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1] * i) % MOD;
	ll mult = 1;
	mult = (mult * fact[n / 2]) % MOD;
	mult = (mult * fact[n / 2]) % MOD;
	for (int i = 0; i < C; ++i) {
		mult = (mult * modPow(fact[cou[i]], MOD-2)) % MOD;
	}
	
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		int a = getInd(str[x]);
		int b = getInd(str[y]);
		if (a == b) {
			cout << (mult * dp[n]) % MOD << '\n';
		} else {
			cout << (2 * mult * ans[a][b]) % MOD << '\n';
		}
	}
}