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

const int N = 13;
const int M = 2010;

int n, m;
int a[N][N];
int tmpa[N][M];

int dp[1 << N];
int dp2[1 << N];
int bm1[1 << N];
int bm[1 << N];


void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> tmpa[i][j];
		}
	}
	vector<pair<int, int>> vv;
	for (int i = 0; i < m; ++i) {
		int mx = tmpa[0][i];
		for (int j = 0; j < n; ++j) {
			mx = max(mx, tmpa[j][i]);
		}
		vv.emplace_back(mx, i);
	}
	sort(ALL(vv));
	reverse(ALL(vv));
	if (vv.size() > n) {
		vv.resize(n);
	}
	for (int i = 0; i < vv.size(); ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = tmpa[j][vv[i].second];
		}
	}
	fill(dp, dp + (1 << n), 0);
	for (int i = 0; i < vv.size(); ++i) {
		fill(bm1, bm1 + (1 << n), 0);
		for (int j = 0; j < (1 << n); ++j) {
			int ans = 0;
			for (int k = 0; k < n; ++k) {
				if ((j >> k) & 1) {
					ans += a[i][k];
				}
			}
			bm1[j] = ans;
		}
		int mod = (1 << n) - 1;
		fill(bm, bm + (1 << n), 0);
		for (int j = 0; j < (1 << n); ++j) {
			int cur = j;
			for (int sh = 0; sh < n; ++sh, cur = (cur * 2) % mod) {
				bm[j] = max(bm[j], bm1[cur]);
			}
		}
		fill(dp2, dp2 + (1 << n), 0);
		for (int j = 0; j < (1 << n); ++j) {
			if (i != 0 && j % 2 == 0) {
				continue;
			}
			int msk = mod - j;
			for (int k = msk; k > 0; k = (k - 1) & msk) {
				dp2[j ^ k] = max(dp2[j ^ k], dp[j] + bm[k]);
			}
		}

		for (int j = 0; j < (1 << n); ++j) {
			dp[j] = max(dp[j], dp2[j]);
		}
	}
	cout << dp[(1 << n) - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		solve();
	}
	return 0;
}