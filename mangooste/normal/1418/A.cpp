#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		long long x, y, k;
		cin >> x >> y >> k;
		long long will = k * y + k;
		x--;
		cout << (will + x - 2) / x + k << '\n';
	}
}