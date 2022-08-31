#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int N = (1 << 17);
const int INF = 1e9;

int n, k;

int a[N * 2];
int dp[N * 2][2][2];

void upd(int& a, int b) {
	a = max(a, b);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> k;
	int shift = (1 << n) - 1;
	for (int i = 0; i < shift + (1 << n); ++i) {
		dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -INF;
	}

	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		--x;
		x += shift;
		a[x] = 1;
	}

	for (int i = shift - 1; i >= 0; --i) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (l >= shift) {
			if (a[l] + a[r] == 2) {
				dp[i][1][1] = 1;
			} else if (a[l] + a[r] == 1) {
				dp[i][1][0] = dp[i][0][1] = 1;
			}
		} else {
			for (int l1 = 0; l1 <= 1; ++l1) {
				for (int l2 = 0; l2 <= 1; ++l2) {
					if (dp[l][l1][l2] < 0) {
						continue;
					}
					for (int r1 = 0; r1 <= 1; ++r1) {
						for (int r2 = 0; r2 <= 1; ++r2) {
							if (dp[r][r1][r2] < 0) {
								continue;
							}

							int sm = dp[l][l1][l2] + dp[r][r1][r2];
							if (l1 + r1) {
								++sm;
							}
							if (l2 + r2) {
								++sm;
							}
							int ls = l1 + r1;
							int rs = min(1, l2 + r2);
							if (ls == 2) {
								ls = 1;
								rs = 1;
							}
							if (ls && rs) {
								++sm;
								upd(dp[i][1][1], sm);
							} else {
								if (ls) {
									upd(dp[i][1][0], sm);
									upd(dp[i][0][1], sm + 1);
								} else {
									upd(dp[i][ls][rs], sm + rs);
								}
							}
						}
					}
				}
			}
		}
	}

	int ans = 0;

	for (int l = 0; l <= 1; ++l) {
		for (int r = 0; r <= 1; ++r) {
			int flag = (l + r > 0);
			ans = max(ans, flag + dp[0][l][r]);
		}
	}

	cout << ans << "\n";

	return 0;
}