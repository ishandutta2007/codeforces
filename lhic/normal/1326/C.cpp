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
const ll MOD = 998244353;

int n, k;
int p[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	ll sum = 0;
	for (int i = n; i > n - k; --i) {
		sum += i;
	}
	ll ans = 1;
	int pr = -1;
	for (int i = 0; i < n; ++i) {
		if (p[i] > n - k) {
			if (pr != -1) {
				ans = (ans * (i - pr)) % MOD;
			}
			pr = i;
		}
	}
	cout << sum << " " << ans << "\n";
	return 0;
}