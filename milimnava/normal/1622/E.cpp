#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		vector<int> a(n), len(n * 2 + 1);
		vector<vector<int> > b(n, vector<int> (m, 0)), vec(n * 2 + 1, vector<int> (m, 0));
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				b[i][j] = c - '0';
			}
		}
		vector<int> res(m);
		int ans = -1;
		for (int i = 0; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if ((i >> j) & 1) sum += a[j];
				else sum -= a[j];
			}
			for (int j = 0; j <= n * 2; j++) len[j] = 0;
			for (int j = 0; j < m; j++) {
				int sum2 = n;
				for (int k = 0; k < n; k++) {
					if (b[k][j]) {
						if ((i >> k) & 1) --sum2;
						else ++sum2;
					}
				}
				vec[sum2][len[sum2]] = j; ++len[sum2];
			}
			vector<int> nowres(m);
			int now = 0;
			for (int j = 0; j <= 2 * n; j++) {
				for (int k = 0; k < len[j]; k++) {
					++now;
					sum += now * (j - n);
					nowres[vec[j][k]] = now;
				}
			}
			if (sum > ans) {
				ans = sum;
				res = nowres;
			}
		}
		for (int i = 0; i < m; i++) cout << res[i] << " ";
		cout << endl;
	}
	return 0;
}