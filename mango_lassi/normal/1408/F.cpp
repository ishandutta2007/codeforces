#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// We can take any k (k power of two) elements and make them equal in k log_2 k operations
	// n = 4: f(0, 1), f(2, 3), f(0, 2), f(1, 3) -> ALL EQUAL
	// -> First make largest power of two possible. Then, make largest power of two possible again, shifted
	// This uses ~4e5 operations

	int n;
	cin >> n;
	int h = 1;
	while (2*h <= n) h *= 2;

	vector<pair<int, int>> ops;
	for (int i0 : {0, n-h}) {
		for (int k = 1; 2*k <= h; k *= 2) {
			for (int i = 0; i < h; i += 2*k) {
				for (int j = 0; j < k; ++j) {
					ops.push_back({i0 + i + j, i0 + (i + k) + j});
				}
			}
		}
	}
	cout << ops.size() << '\n';
	for (auto pr : ops) cout << pr.first + 1 << ' ' << pr.second + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}