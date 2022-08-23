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

int ans[210000];

void solve() {
	int a, b;
	cin >> a >> b;
	for (int i = 0; i <= a + b; ++i) {
		ans[i] = 0;
	}
	vector<int> vv;
	vv.push_back((a + b) / 2);
	vv.push_back((a + b + 1) / 2);
	for (int c : vv) {
		for (int x = 0; x <= a && x <= c; ++x) {
			int y = c - x;
			int w = a - x;
			int z = b - y;
			if (z >= 0) {
				ans[y + w] = 1;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i <= a + b; ++i) {
		sum += ans[i];
	}
	cout << sum << "\n";
	for (int i = 0; i <= a + b; ++i) {
		if (ans[i]) {
			cout << i << " ";
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