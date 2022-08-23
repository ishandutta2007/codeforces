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
	int n;
	cin >> n;
	if (n == 2) {
		cout << -1 << "\n";
		return 0;
	}

	int k = 1;
	while ((k + 1) * (k + 1) <= n) {
		++k;
	}
	if (n == k * k + 2 * k - 1) {
		cout << k + 2 << "\n";
		cout << string(1, 'o') + string(k + 1, '.') << "\n";
		cout << string(k - 1, 'o') + string(3, '.') << "\n";
		cout << string(k - 1, 'o') + string(3, '.') << "\n";
		for (int i = 0; i < k - 2; ++i) {
			cout << string(k + 1, 'o') + string(1, '.') << "\n";
		}
		cout << string(k + 2, 'o') + string(0, '.') << "\n";
	} else if (k * k == n) {
		cout << k << "\n";
		for (int i = 0; i < k; ++i) {
			cout << string(k, 'o') << "\n";
		}
	} else {
		int ln = (n - k * k + 1) / 2;
		cout << k + 1 << "\n";
		cout << string(ln, 'o') + string(k + 1 - ln, '.') << "\n";
		if ((n - k * k) % 2 == 1) {
			cout << string(k - 1, 'o') + string(2, '.') << "\n";
		} else if (ln == k) {
			cout << string(k + 1, 'o') + string(0, '.') << "\n";
		} else {
			cout << string(k, 'o') + string(1, '.') << "\n";
		}
		for (int i = k - 2; i >= 0; --i) {
			if (i >= ln) {
				cout << string(k, 'o') + string(1, '.') << "\n";
			} else {
				cout << string(k + 1, 'o') + string(0, '.') << "\n";
			}
		}
	}
	return 0;
}