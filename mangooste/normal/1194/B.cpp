#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		int t[n][m];
		vector<int> r(n), c(m);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char ch;
				cin >> ch;
				t[i][j] = (ch == '.' ? 1 : 0);
				r[i] += t[i][j];
				c[j] += t[i][j];
			}
		}

		int ans = 1e9;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				ans = min(ans, r[i] + c[j] - t[i][j]);
			}
		}

		cout << ans << "\n";

	}
}