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

const int N = 1010;

int n, m;
ll k;

string s;

int lcp[N][N];

ll dp[N][N];

int go[N][N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> m >> k;
	cin >> s;

	for (int i = s.size() - 1; i >= 0; --i) {
		lcp[i][i] = s.size() - i;
		for (int j = i + 1; j < s.size(); ++j) {
			if (s[i] == s[j]) {
				lcp[i][j] = lcp[j][i] = 1 + lcp[i + 1][j + 1];
			}
		}
	}

	vector<pair<int, int>> vv;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= s.size(); ++j) {
			vv.emplace_back(i, j);
		}
	}

	sort(ALL(vv), [] (pair<int, int> a, pair<int, int> b) {
				int l = lcp[a.first][b.first];
				int l1 = a.second - a.first;
				int l2 = b.second - b.first;
				if (l1 > l) {
					if (l2 > l) {
						return s[a.first + l] < s[b.first + l];
					} else {
						return false;
					}
				} else {
					if (l2 > l) {
						return true;
					} else {
						return l1 < l2;
					}
				}
			});

	for (int i = 0; i < vv.size(); ++i) {
		go[vv[i].first][vv[i].second] = i;
	}

	int l = 0;
	int r = vv.size();
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		memset(dp, 0, sizeof(dp));
		dp[n][0] = 1;

		ll sum = 0;

		for (int i = n - 1; i >= 0; --i) {
			int len = 1;
			while (i + len <= n && go[i][i + len] < mid) {
				++len;
			}
			dp[i][0] = 1;
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = min(k, dp[i + 1][j] + dp[i + len][j - 1]);
			}
			if (i == 0) {
				sum = dp[i + len][m - 1];
			}
		}

		if (sum >= k) {
			l = mid;
		} else {
			r = mid;
		}
	}

	cout << s.substr(vv[l].first, vv[l].second - vv[l].first) << "\n";

	return 0;
}