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

const int N = 30;

int n;

ll dp[N][N];
ll a[N][N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (i == n - 1 && j == n - 1) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i - 1 < 0 || j + 1 >= n) {
				a[i][j] = 0;
			} else {
				a[i][j] = a[i - 1][j + 1] + dp[i][j + 1];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout.flush();

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll k;
		cin >> k;
		vector<pair<int, int>> vv;
		int x = 0;
		int y = 0;
		vv.emplace_back(x, y);
		while (min(x, y) < n - 1) {
			if (k < dp[x][y + 1]) {
				++y;
			} else {
				k -= dp[x][y + 1];
				++x;
			}
			vv.emplace_back(x, y);
		}
		for (auto p : vv) {
			cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
		cout.flush();
	}
	return 0;
}