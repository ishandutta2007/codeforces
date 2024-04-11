#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		for (int i = 0; i < 2 * n - 1; i += 2)
			cout << s[i];
		cout << '\n';
	}
}