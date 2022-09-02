#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	// Use k ones
	// Minimise (maxr - minr)^2 + (maxc - minc)^2

	// Can always do <= 2 by placing on diagonals
	// Is it always optimal?
	//	YES, if k != 0 (mod n), then both differences are at least 1

	if (k % n == 0) cout << 0 << '\n';
	else cout << 2 << '\n';

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			int d = x-y;
			if (d < 0) d += n;
			int ind = d*n + x;
			if (ind < k) cout << 1;
			else cout << '0';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}