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
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		if (a[0] + a[1] <= a.back()) cout << "1 2 " << n << '\n';
		else cout << "-1\n";
	}
}