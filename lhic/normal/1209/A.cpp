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

const int N = 120;

int n;

int a[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		int fl = 0;
		for (int j = 0; j < i; ++j) {
			if (a[i] % a[j] == 0) {
				fl = 1;
				break;
			}
		}
		if (!fl)
			++cnt;
	}
	cout << cnt << "\n";
	return 0;
}