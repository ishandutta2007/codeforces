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
		vector<int> a(n);
		for (auto &x : a)
			cin >> x;
		reverse(a.begin(), a.end());
		if (is_sorted(a.begin(), a.end()) && (int) (unique(a.begin(), a.end()) - a.begin()) == n)
			cout << "NO\n";
		else
			cout << "YES\n";
	}	
}