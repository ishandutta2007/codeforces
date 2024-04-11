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

int MOD;

int n;

ll ans[4100000];
ll ad[4100000];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> MOD;
	ll sum = 0;
	ans[1] = 1;
	for (int i = 1; i <= n; ++i) {
		if (i != 1) {
			for (int j = 1; j < i && i * j <= n; ++j) {
				ad[i * j] += ans[j];
				if ((j + 1) * i <= n) {
					ad[(j + 1) * i] -= ans[j];
				}
			}
		}
		sum = (sum + ad[i]) % MOD;
		if (sum < 0) {
			sum += MOD;
		}
		ans[i] = (ans[i] + sum) % MOD;
		sum = (sum + ans[i]) % MOD;
		for (int j = 2; j <= i && i * j <= n; ++j) {
			ad[i * j] += ans[i];
			if ((i + 1) * j <= n) {
				ad[(i + 1) * j] -= ans[i];
			}
		}
	}
	cout << ans[n] << "\n";
	return 0;
}