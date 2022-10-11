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
		vector<int> p(n);
		for (auto &x : p)
			cin >> x;
		for (int i = n - 1; i >= 0; i--)
			cout << p[i] << ' ';
		cout << '\n';
	}
}