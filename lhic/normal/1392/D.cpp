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
string s;

void solve() {
	cin >> n;
	cin >> s;
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] != s[i + 1]) {
			rotate(s.begin(), s.begin() + i + 1, s.end());
			break;
		}
	}
	if (s[0] == s[n - 1]) {
		cout << (n + 2) / 3 << "\n";
		return;
	}
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cnt += 1;
		if (i + 1 == n || s[i] != s[i + 1]) {
			ans += cnt / 3;
			cnt = 0;
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