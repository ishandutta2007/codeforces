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

const ll MOD = 31607;

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

int n;
ll a_[22][22];
ll a[22][22];
ll b[22];
ll c[22][22];

ll ans = 0;

void run(int x, int par, ll cur) {
	if (x == n) {
		ll lose = cur;
		for (int i = 0; i < n; ++i) {
			lose = (lose * (MOD + 1 - c[x][i])) % MOD;
		}
		if (par) {
			ans -= lose;
		} else {
			ans += lose;
		}
		return;
	}

	memcpy(c[x + 1], c[x], sizeof(c[0][0]) * n);
	run(x + 1, par ^ 1, (cur * b[x]) % MOD);
	for (int i = 0; i < n; ++i) {
		c[x + 1][i] = c[x][i] * a[x][i] % MOD;
	}
	run(x + 1, par, cur);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	ll rv = pw(10000, MOD - 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a_[i][j];
			a_[i][j] = (a_[i][j] * rv) % MOD;
		}
	}
	for (int d1 = 0; d1 < 2; ++d1) {
		for (int d2 = 0; d2 < 2; ++d2) {
			ll ml = 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (d1 && i == j) {
						a[i][j] = 1;
						ml = (ml * a_[i][j]) % MOD;
					} else if (d2 && (i + j) == n - 1) {
						a[i][j] = 1;
						ml = (ml * a_[i][j]) % MOD;
					} else {
						a[i][j] = a_[i][j];
					}
				}
			}

			for (int i = 0; i < n; ++i) {
				b[i] = 1;
				for (int j = 0; j < n; ++j) {
					b[i] = (b[i] * a[i][j]) % MOD;
				}
				c[0][i] = 1;
			}

			run(0, (d1 + d2) % 2, ml);

		}
	}
	ans = (MOD + 1 - ans);
	ans %= MOD;
	if (ans < 0) {
		ans += MOD;
	}
	cout << ans << "\n";
	return 0;
}