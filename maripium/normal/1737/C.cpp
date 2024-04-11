#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		int r[3], c[3];
		for (int i = 0; i < 3; ++i) cin >> r[i] >> c[i];
		int x, y; cin >> x >> y;

		auto is_border = [&](int z) {
			return z == 1 || z == n;
		};
		auto solve = [&]() -> bool {
			bool cnt[2][2]{};
			for (int i = 0; i < 3; ++i) cnt[r[i] % 2][c[i] % 2] = true;

			for (int i = 0; i < 3; ++i) {
				if (!cnt[1 - (r[i] % 2)][1 - (c[i] % 2)] && is_border(r[i]) && is_border(c[i])) {
					return x == r[i] || y == c[i];
				}
			}
			return cnt[x % 2][y % 2];
		};
		if (solve()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}