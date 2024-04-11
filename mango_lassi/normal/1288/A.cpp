#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll calc(ll x, ll d) {
	return x + (d + x) / (x + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n, d;
		cin >> n >> d;

		// Optimal to increment x until ceil(d / (x+1)) decreases by one or less
		// Which is when
		//	d / (x+1) - d / (x+2) <= 1
		// 	1 / (x+1)(x+2) <= 1 / d
		// 	d <= (x+1)(x+2)
		ll low = 0;
		ll high = d-1;
		while(low != high) {
			ll x = (low + high) >> 1;
			if (d <= (x+1) * (x+2)) high = x;
			else low = x + 1;
		}
		if (calc(low, d) <= n) cout << "YES\n";
		else cout << "NO\n";
	}
}