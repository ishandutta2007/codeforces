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

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	int n;
	cin >> n;
	vector<pair<int, int>> vv;
	for (int i = 0; i < n; ++i) {
		int w, h;
		cin >> w >> h;
		vv.emplace_back(w, h);
		if (w != h) {
			vv.emplace_back(h, w);
		}
	}
	sort(ALL(vv));
	ll ans = 0;
	ll cnt_eq = 0;
	ll cnt = 0;
	for (int i = 0; i < vv.size(); ++i) {
		++cnt;
		++cnt_eq;
		if (i + 1 == vv.size() || vv[i + 1].first != vv[i].first) {
			ans += cnt * (cnt - 1) / 2;
			cnt = 0;
		}
		if (i + 1 == vv.size() || vv[i + 1] != vv[i]) {
			if (vv[i].first < vv[i].second) {
				ans -= cnt_eq * (cnt_eq - 1) / 2;
			}
			cnt_eq = 0;
		}
	}
	cout << ans << "\n";
	return 0;
}