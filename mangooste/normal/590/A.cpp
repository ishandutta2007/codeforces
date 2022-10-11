#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	int ans = 0;
	for (int i = 0; i < n;) {
		int j = i + 1;
		while (j < n && a[j] != a[j - 1]) {
			j++;
		}
		ans = max(ans, (j - i - 1) / 2);
		for (int pos = 1; i + pos <= j - 1 - pos; pos++) {
			a[i + pos] = a[i + pos - 1];
			a[j - 1 - pos] = a[j - pos];
		}
		i = j;
	}
	cout << ans << '\n';
	for (auto &el : a) {
		cout << el << ' ';
	}
}