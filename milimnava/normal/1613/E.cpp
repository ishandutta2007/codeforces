#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		vector<vector<int> > a(n, vector<int>(m, 0)), cnt = a, res = a;
		int sx, sy;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c; cin >> c;
				if (c == '.') a[i][j] = 0;
				if (c == '#') a[i][j] = 1;
				if (c == 'L') a[i][j] = 2, sx = i, sy = j;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0) continue;
				for (int d = 0; d < 4; d++) {
					int x = i + dx[d], y = j + dy[d];
					if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != 1) ++cnt[i][j];
				}
			}
		}
		queue<pair<int, int> > q;
		res[sx][sy] = 1;
		q.push(make_pair(sx, sy));
		while (!q.empty()) {
			int i = q.front().first, j = q.front().second; q.pop();
			for (int d = 0; d < 4; d++) {
				int x = i + dx[d], y = j + dy[d];
				if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 0) {
					--cnt[x][y];
					if (cnt[x][y] <= 1 && !res[x][y]) {
						res[x][y] = 1;
						q.push(make_pair(x, y));
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 0) {
					if (res[i][j]) putchar('+');
					else putchar('.');
				}
				if (a[i][j] == 1) putchar('#');
				if (a[i][j] == 2) putchar('L');
			}
			putchar('\n');
		}
	}
	return 0;
}