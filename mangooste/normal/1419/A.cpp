#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (n % 2 == 0) {
			bool any_even = false;
			for (int i = 1; i < n; i += 2)
				any_even |= ((s[i] - '0') % 2 == 0);
			cout << (any_even ? 2 : 1) << '\n';
		} else {
			bool any_odd = false;
			for (int i = 0; i < n; i += 2)
				any_odd |= ((s[i] - '0') % 2 == 1);
			cout << (any_odd ? 1 : 2) << '\n';
		}
	}
}