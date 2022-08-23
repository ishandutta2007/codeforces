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


vector<pair<int, int>> vv;

int n;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	vv.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> vv[i].first;
	}
	for (int i = 0; i < n; ++i) {
		cin >> vv[i].second;
	}
	sort(ALL(vv));

	ll ans = 0;

	multiset<int> ss;
	ll sum = 0;

	int cur = 0;

	int now = 0;
	while (now < vv.size() || ss.size()) {
		while (now < vv.size() && vv[now].first == cur) {
			ss.insert(vv[now].second);
			sum += vv[now].second;
			++now;
		}
		if (ss.size()) {
			ll x = *ss.rbegin();
			ss.erase(ss.find(x));
			sum -= x;
			ans += sum;
			cur += 1;
		} else {
			cur = vv[now].first;
		}
	}

	cout << ans << "\n";
	return 0;
}