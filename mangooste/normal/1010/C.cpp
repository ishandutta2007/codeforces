#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	int g = k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		g = gcd(g, x);
	}
	vector<int> ans;
	for (int i = 0; i < k; i += g) {
		ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}