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
const int N = 210000;

int n;
ll a[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (a[i] > a[i + 1]) {
			ans += a[i] - a[i + 1];
		}
	}
	cout << ans << "\n";
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