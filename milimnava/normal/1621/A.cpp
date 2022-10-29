#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		if (k * 2 - 1 > n) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j && i % 2 == 1 && i <= k * 2 - 1) cout << 'R';
				else cout << '.';
			}
			cout << endl;
		}
	}
	return 0;
}