#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m = min(n, (n + 3) / 4);

		cout << string(n - m, '9') + string(m, '8') << '\n';
	}
}