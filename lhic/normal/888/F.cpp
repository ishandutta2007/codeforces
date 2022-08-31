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
const ll MOD = 1e9 + 7;

void add(ll &a, ll b) {
	a += b;
	a %= MOD;
}

int n;

ll dp[510][510][2][2];
int a[510][510];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; ++i) {
		a[i][n] = a[n][i] = a[0][i];
	}
	for (int i = n; i >= 0; --i) {
		for (int j = i + 1; j <= n; ++j) {
			if (i + 1 == j) {
				for (int k = 0; k < 2; ++k)
					for (int l = 0; l < 2; ++l)
						dp[i][j][k][l] = 1;
				continue;
			}
			dp[i][j][0][0] = 0;
			for (int k = i + 1; k < j; ++k) {
				if (a[k][j])
					add(dp[i][j][0][1], dp[i][k][0][1] * dp[k][j][1][1]);
				if (a[i][k]) {
					add(dp[i][j][1][0], dp[i][k][1][1] * dp[k][j][1][0]);
					add(dp[i][j][1][1], dp[i][k][1][1] * dp[k][j][1][1]);
				}
			}
			add(dp[i][j][1][1], dp[i][j][0][1]);
		}
	}
	ll ans = 0;
	for (int k = 1; k < n; ++k) {
		if (a[0][k])
			add(ans, dp[0][k][0][1] * dp[k][n][1][1]);
	}
	cout << ans << "\n";
	return 0;
}