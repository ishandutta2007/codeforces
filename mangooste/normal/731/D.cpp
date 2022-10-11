#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, c;
	cin >> n >> c;
	vector<vector<int>> a(n);
	for (auto &els : a) {
		int m;
		cin >> m;
		els.resize(m);
		for (auto &el : els) {
			cin >> el;
		}
	}
	int need = 0;
	vector<int> bit(c + 1, 0);
	for (int i = 1; i < n; i++) {
		int j = 0;
		while (j < min(a[i - 1].size(), a[i].size()) && a[i - 1][j] == a[i][j]) {
			j++;
		}
		if (j == a[i].size() && j != a[i - 1].size()) {
			cout << -1;
			return 0;
		}
		if (j == min(a[i - 1].size(), a[i].size())) {
			continue;
		}
		need++;
		int c1 = a[i - 1][j], c2 = a[i][j];
		if (c1 < c2) {
			bit[0]++;
			bit[c - c2 + 1]--;
			bit[c - c1 + 1]++;
			bit.back()--;
		} else {
			bit[c - c1 + 1]++;
			bit[c - c2 + 1]--;
		}
	}
	for (int i = 1; i < c; i++) {
		bit[i] += bit[i - 1];
	}
	for (int i = 0; i < c; i++) {
		if (bit[i] == need) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}