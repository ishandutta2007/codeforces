#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		int w, h; cin >> w >> h;
		vector <int> x[2], y[2];
		for (int i = 0; i <= 1; i++) {
			int n; cin >> n;
			x[i].resize(n);
			for (int j = 0; j < n; j++) cin >> x[i][j];
		}
		for (int i = 0; i <= 1; i++) {
			int n; cin >> n;
			y[i].resize(n);
			for (int j = 0; j < n; j++) cin >> y[i][j];
		}
		long long maxn = 0;
		maxn = max(maxn, 1ll * max(x[0][x[0].size() - 1] - x[0][0], x[1][x[1].size() - 1] - x[1][0]) * h);
		maxn = max(maxn, 1ll * max(y[0][y[0].size() - 1] - y[0][0], y[1][y[1].size() - 1] - y[1][0]) * w);
		cout << maxn << endl;
	}
	return 0;
}