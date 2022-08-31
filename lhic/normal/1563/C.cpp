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
int a[3000];


void solve() {
	vector<pair<int, int>> ans;

	auto rev = [&] (int l, int r) {
		ans.emplace_back(l, r);
		reverse(a + l, a + r);
	};
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}
	for (int i = n - 1; i > 0; i -= 2) {
		int pos = 0;
		while (a[pos] != i) {
			++pos;
		}
		if (pos % 2 == 1) {
			cout << -1 << "\n";
			return;
		}
		rev(0, pos + 1);
		pos = 0;
		while (a[pos] != (i - 1)) {
			++pos;
		}
		if (pos % 2 == 0) {
			cout << -1 << "\n";
			return;
		}
		rev(0, pos);
		rev(0, i + 1);
		pos = 0;
		while (a[pos] != i) {
			++pos;
		}
		rev(0, pos + 1);
		rev(0, i + 1);
	}
	for (int i = 0; i < n; ++i) {
		assert(a[i] == i);
	}
	cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		cout << y << " ";
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