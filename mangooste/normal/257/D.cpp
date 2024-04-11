#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), ans(n, 0);
	for (auto &el : a) {
		cin >> el;
	}
	int sum = a.back();
	for (int i = n - 2; i >= 0; i--) {
		ans[i] = (sum > 0);
		sum += a[i] * (sum > 0 ? -1 : 1);
	}
	for (int i = 0; i < n; i++) {
		cout << "-+"[ans[i] ^ (sum > 0)];
	}
}