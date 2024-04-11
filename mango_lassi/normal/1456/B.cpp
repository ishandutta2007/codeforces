#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Three consecutive elements with same largest bit -> 1 operation
	// -> n <= 2 log_2(1e9) in the interesting cases

	vector<ll> as(n);
	for (ll& v : as) cin >> v;

	for (int i = 0; i + 2 < n; ++i) {
		if (as[i] > (as[i + 1] ^ as[i + 2])) {
			cout << 1 << '\n';
			return 0;
		}
	}

	int res = n;
	for (int i = 0; i + 1 < n; ++i) {
		ll v1 = 0;
		for (int a = i; a >= 0; --a) {
			v1 ^= as[a];
			ll v2 = 0;
			for (int b = i+1; b < n; ++b) {
				v2 ^= as[b];

				if (v1 > v2) res = min(res, (i - a) + (b - (i+1)));
			}
		}
	}
	if (res < n) cout << res << '\n';
	else cout << -1 << '\n';
	
}