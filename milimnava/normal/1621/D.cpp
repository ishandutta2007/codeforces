#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<vector<long long> > a(2 * n + 1, vector<long long>(2 * n + 1, 0));
		for (int i = 1; i <= n * 2; i++) {
			for (int j = 1; j <= n * 2; j++) {
				cin >> a[i][j];
			}
		}
		long long ans = 2e9;
		ans = min(ans, a[n][2 * n]);
		ans = min(ans, a[2 * n][n]);
		ans = min(ans, a[1][2 * n]);
		ans = min(ans, a[2 * n][1]);
		ans = min(ans, a[n][n + 1]);
		ans = min(ans, a[n + 1][n]);
		ans = min(ans, a[1][n + 1]);
		ans = min(ans, a[n + 1][1]);
		for (int i = n + 1; i <= n * 2; i++) {
			for (int j = n + 1; j <= n * 2; j++) {
				ans += a[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}