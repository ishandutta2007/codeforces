#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2501;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto &els : a) {
		for (auto &el : els) {
			cin >> el;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i][i] != 0) {
			cout << "NOT MAGIC";
			return 0;
		}
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) {
				cout << "NOT MAGIC";
				return 0;
			}
		}
	}
	vector<array<int, 3>> ord;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ord.push_back({a[i][j], i, j});
		}
	}
	sort(ord.begin(), ord.end());
	vector<bitset<MAXN>> now(n);
	for (int i = 0; i < n; i++) {
		now[i].reset();
	}
	ord.push_back({-1, -1, -1});
	for (int i = 1, j = 0; i < ord.size(); i++) {
		if (ord[i][0] != ord[i - 1][0]) {
			for (int k = j; k < i; k++) {
				int v = ord[k][1], u = ord[k][2];
				if ((now[v] & now[u]).count()) {
					cout << "NOT MAGIC";
					return 0;
				}
			}
			for (; j < i; j++) {
				int v = ord[j][1], u = ord[j][2];
				now[v][u] = 1;
				now[u][v] = 1;
			}
		}
	}
	cout << "MAGIC";
}