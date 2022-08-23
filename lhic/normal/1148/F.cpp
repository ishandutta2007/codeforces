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

ll v[N];
ll m[N];


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	ll sm = 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i] >> m[i], sm += v[i];
	if (sm < 0) {
		for (int i = 0; i < n; ++i)
			v[i] = -v[i];
	}
	ll ans = 0;
	for (int i = 0; i < 62; ++i) {
		ll sm = 0;
		for (int j = 0; j < n; ++j) {
			if (m[j] == 1)
				sm += v[j];
		}
		if (sm > 0) {
			ans += (1ll << i);
			for (int j = 0; j < n; ++j)
				if (m[j] & 1)
					v[j] = -v[j];
		}
		for (int j = 0; j < n; ++j)
			m[j] /= 2;
	}
	cout << ans << "\n";
	return 0;
}