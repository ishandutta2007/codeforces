#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		ll xr = 0;
		ll sm = 0;
		for (int i = 0; i < n; ++i) {
			ll v;
			cin >> v;
			xr ^= v;
			sm += v;
		}
		// 1. Make xor zero
		// 2. Output sum
		cout << 2 << '\n';
		cout << xr << ' ' << (sm + xr) << '\n';
	}
}