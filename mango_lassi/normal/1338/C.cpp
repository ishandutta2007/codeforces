#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

// 00 00 00
// 01 10 11
// 10 11 01
// 11 01 10
vector<vector<int>> base = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

void solve() {
	ll n;
	cin >> n;
	--n;
	for (ll m = 0;; ++m) {
		ll low = 1ll << (2*m);
		ll high = 4*low - 1;
		ll len = high - low + 1;
		if (n >= len) {
			n -= len;
			continue;
		}

		int j = n % 3;
		n /= 3;

		// n % 4 determines first two bits
		// (n / 4) % 4 determines second two bits
		// ...

		ll res = low * (j + 1);
		for (ll k = 0; k < m; ++k) {
			ll mult = 1ll << (2*k);
			res |= mult * base[j][n%4];
			n /= 4;
		}
		cout << res << '\n';
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}