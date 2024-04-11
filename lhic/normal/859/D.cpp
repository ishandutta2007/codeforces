#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int k;
ld p[100][100];
ld dp[20][100];
ld pr[20][100];

int main() {
	cin >> k;
	int n = (1 << k);
	for (int i = 0; i < (1 << k); ++i)
		for (int j = 0; j < (1 << k); ++j)
			cin >> p[i][j], p[i][j] /= 100;
	for (int i = 0; i < n; ++i)
		pr[0][i] = 1;
	for (int r = 1; r <= k; ++r) {
		for (int i = 0; i < n; i += (1 << r)) {
			int bl = (1 << (r - 1));
			for (int j = i; j < i + bl; ++j) {
				for (int l = i + bl; l < i + 2 * bl; ++l)
					pr[r][j] += pr[r - 1][j] * pr[r - 1][l] * p[j][l];
				for (int l = i + bl; l < i + 2 * bl; ++l)
					dp[r][j] = max(dp[r][j], dp[r - 1][j] + dp[r - 1][l] + bl * pr[r][j]);
			}
			for (int j = i + bl; j < i + 2 * bl; ++j) {
				for (int l = i; l < i + bl; ++l)
					pr[r][j] += pr[r - 1][j] * pr[r - 1][l] * p[j][l];
				for (int l = i; l < i + bl; ++l)
					dp[r][j] = max(dp[r][j], dp[r - 1][j] + dp[r - 1][l] + bl * pr[r][j]);
			}
		}
	}
	ld ans = 0;
	for (int j = 0; j < n; ++j)
		ans = max(ans, dp[k][j]);
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";
	return 0;
}