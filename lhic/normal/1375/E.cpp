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
const int N = 1200;

int n;
int a[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> vv;
	for (int i = 0; i < n; ++i) {
		vv.emplace_back(a[i], i);
	}
	sort(ALL(vv));
	for (int i = 0; i < n; ++i) {
		a[vv[i].second] = i;
	}
	vector<pair<int, int>> ans;

	for (int i = 0; i < n; ++i) {
		vv.clear();
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[i]) {
				vv.emplace_back(a[j], j);
			}
		}
		sort(ALL(vv));
		for (int k = (int)vv.size() - 1; k >= 0; --k) {
			ans.emplace_back(i, vv[k].second);
		}
	}
	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}
	return 0;
}