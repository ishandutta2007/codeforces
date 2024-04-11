#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int L, R;
		cin >> L >> R;
		if (L * 2 <= R) {
			cout << L << ' ' << L * 2 << '\n';
		} else {
			cout << -1 << ' ' << -1 << '\n';
		}
	}
}