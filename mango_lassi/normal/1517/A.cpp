#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n;
		cin >> n;
		ll cou = n / 2050;
		if (cou * 2050 != n) {
			cout << -1 << '\n';
		} else {
			ll res = 0;
			while(cou > 0) {
				res += cou % 10;
				cou /= 10;
			}
			cout << res << '\n';
		}
	}
}