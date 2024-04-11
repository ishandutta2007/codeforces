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

const int N = 310000;

int n;
vector<pair<ll, int>> vv;
ll t[N];
vector<tuple<ll, ll, ll>> ans;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll s;
		cin >> s;
		vv.emplace_back(s, i);
	}
	for (int i = 0; i < n; ++i)
		cin >> t[i];
	sort(t, t + n);
	sort(ALL(vv));
	vector<pair<ll, int>> st;
	for (int i = 0; i < n; ++i) {
		ll sh = t[i] - vv[i].first;
		if (sh == 0)
			continue;
		if (sh > 0)
			st.emplace_back(sh, vv[i].second);
		else {
			sh = -sh;
			while (!st.empty() && sh) {
				ll go = min(sh, st.back().first);
				ans.emplace_back(st.back().second, vv[i].second, go);
				sh -= go;
				st.back().first -= go;
				if (st.back().first == 0)
					st.pop_back();
			}
			if (sh) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	if (st.empty()) {
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto x: ans) {
			ll a, b, d;
			tie(a, b, d) = x;
			cout << a + 1 << " " << b + 1 << " " << d << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
	return 0;
}