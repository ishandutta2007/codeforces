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

vector<tuple<int, int, int>> vv;

int n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	int c1 = 0;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < b)
			++c1;
		vv.emplace_back(a, b, i);
	}
	int fl = 0;
	if (c1 < n - c1) {
		fl = 1;
		for (int i = 0; i < n; ++i)
			swap(get<0>(vv[i]), get<1>(vv[i]));
	}
	sort(vv.begin(), vv.end());
	reverse(ALL(vv));
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (get<0>(vv[i]) < get<1>(vv[i]))
			ans.push_back(get<2>(vv[i]));
	}
	if (fl)
		reverse(ALL(ans));
	cout << ans.size() << "\n";
	for (int i: ans)
		cout << i + 1 << " ";
	cout << "\n";
	return 0;
}