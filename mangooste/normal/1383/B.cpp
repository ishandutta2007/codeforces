#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 20;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x = 0;
		cin >> n;
		vector<int> a(n);
		for (auto &el : a) {
			cin >> el;
			x ^= el;
		}

		if (x == 0) {
			cout << "DRAW\n";
			continue;
		}

		int b = 31 - __builtin_clz(x);

		int cnt = 0;
		for (auto &el : a) {
			cnt += (el >> b) & 1;
		}

		cout << (cnt % 4 == 1 || (n - cnt) % 2 ? "WIN\n" : "LOSE\n");
	}
}