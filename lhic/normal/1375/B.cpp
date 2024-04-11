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

void solve() {
	int n, m;
	cin >> n >> m;
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			int cnt = 0;
			if (i == 0 || i == n - 1) {
				++cnt;
			}
			if (j == 0 || j == m - 1) {
				++cnt;
			}
			if (x > 4 - cnt) {
				fl = 1;
			}
		}
	}
	if (fl) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cnt = 0;
			if (i == 0 || i == n - 1) {
				++cnt;
			}
			if (j == 0 || j == m - 1) {
				++cnt;
			}
			cout << 4 - cnt << " ";
		}
		cout << "\n";
	}
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