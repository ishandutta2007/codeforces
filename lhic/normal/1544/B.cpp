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
	for (int i = 0; i < n; ++i) {
		if (i == 0 || i == n - 1) {
			cout << 1;
			for (int j = 1; j < m - 2; ++j) {
				cout << (j - 1) % 2;
			}
			cout << 0 << 1 << "\n";
		} else if (i + 2 == n || (i - 1) % 2 == 0) {
			for (int j = 0; j < m; ++j) {
				cout << 0;
			}
			cout << "\n";
		} else {
			cout << 1;
			for (int j = 1; j + 1 < m; ++j) {
				cout << 0;
			}
			cout << 1 << "\n";
		}
	}
	cout << "\n";
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