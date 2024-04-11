#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100;
const int K = 100;
ll dp[N + 1][K + 1];
ll binom[2*N + 1][2*N + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	ll p;
	cin >> n >> m >> k >> p;

	for (int a = 0; a <= 2*n; ++a) {
		binom[a][0] = 1;
		for (int b = 1; b <= a; ++b) {
			binom[a][b] = (binom[a-1][b] + binom[a-1][b-1]) % p;
		}
	}

	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int a = 2; a <= n; ++a) dp[a][1] = a * dp[a-1][1] % p;

	for (int it = 2; it <= m; ++it) {
		for (int a = n; a > 0; --a) {
			for (int b = 0; b <= min(k, a); ++b) {
				ll val = 0;
				if ((b == 0) || (it + b <= a + 1)) {
					for (int x = 0; x < a; ++x) {
						ll cur = 0;
						for (int y = max(0, b-a+x+1); y <= min(x, b); ++y) {
							ll add = (dp[x][y] * dp[a-x-1][b-y]) % p;
							cur += add;
						}
						val = (val + (cur % p) * binom[a-1][x]) % p;
					}
				}
				dp[a][b] = val % p;
			}
		}
	}
	if (m + k <= n + 1) cout << dp[n][k] << '\n';
	else cout << 0 << '\n';
}