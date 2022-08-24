#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

ll out(vector<ll> vv) {
	ll ans = 0;
	for (int j = (int)vv.size() - 1; j >= 0; --j)
		ans = ans * 10 + vv[j];
	return ans;
}

int main() {
	ll a, b;
	cin >> a >> b;
	vector<ll> va;
	vector<ll> vb;
	while (a)
		va.push_back(a % 10), a /= 10;
	while (b)
		vb.push_back(b % 10), b /= 10;
	if (va.size() < vb.size()) {
		sort(va.begin(), va.end());
		cout << out(va) << "\n";
		return 0;
	}
	ll ans = 0;
	int fl = 0;
	for (int i = va.size() - 1; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			if (va[j] < vb[i]) {
				vector<ll> tmp = va;
				swap(tmp[j], tmp[i]);
				sort(tmp.begin(), tmp.begin() + i);
				ans = max(ans, out(tmp));
			}
		}
		for (int j = 0; j <= i; ++j) {
			if (va[j] == vb[i]) {
				swap(va[j], va[i]);
				break;
			}
		}
		if (va[i] != vb[i]) {
			fl = 1;
			break;
		}
	}
	if (!fl)
		ans = max(ans, out(vb));
	cout << ans << "\n";
	return 0;
}