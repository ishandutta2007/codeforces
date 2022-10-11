#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll L, R, m;
		cin >> L >> R >> m;
		ll ml = m - R + L, mr = m - L + R;
		for (ll a = L; a <= R; a++) {
			ll n = a * ((m + a - 1) / a);
			if (ml <= n && n <= mr) {
				cout << a << ' ' << L << ' ' << n - m + L;
				break;
			}
			n -= a;
			if (ml <= n && n <= mr) {
				cout << a << ' ' << m + L - n << ' ' << L;
				break;
			}
		}
		cout << '\n';
	}
}