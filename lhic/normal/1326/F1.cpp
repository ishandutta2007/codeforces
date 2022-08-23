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

int n;
int ed[20][20];

vector<ll> dp[1 << 14][14];

int pc[1 << 18];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			ed[i][j] = c - '0';
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		pc[i] = __builtin_popcount(i);
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				dp[i][j].resize(1 << (pc[i] - 1));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[1 << i][i][0] = 1;
	}

	for (int i = 0; i + 1 < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (!((i >> j) & 1)) {
				continue;
			}
			for (int k = 0; k < n; ++k) {
				if ((i >> k) & 1) {
					continue;
				}
				int ad = ed[j][k] << (pc[i] - 1);
				for (int x = 0; x < dp[i][j].size(); ++x) {
					dp[i ^ (1 << k)][k][x + ad] += dp[i][j][x];
				}
			}
		}
	}
	vector<ll> ans(1 << (n - 1));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < dp[(1 << n) - 1][i].size(); ++j) {
			ans[j] += dp[(1 << n) - 1][i][j];
		}
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}