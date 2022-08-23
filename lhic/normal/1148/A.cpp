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
	ll a, b, c;
	cin >> a >> b >> c;
	if (a > b) {
		cout << 2 * c + b + b + 1 << "\n";
	}
	else if (b > a) {
		cout << 2 * c + 1 + 2 * a << "\n";
	}
	else {
		cout << 2 * c + a + b << "\n";
	}
	return 0;
}