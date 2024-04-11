#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	vector<vector<vector<int>>> dist(3, vector<vector<int>>(n, vector<int>(m, 4 * n * m)));
	deque<array<int, 3>> dq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isdigit(a[i][j])) {
				dist[a[i][j] - '1'][i][j] = 0;
				dq.push_back({a[i][j] - '1', i, j});
			}
		}
	}
	while (dq.size()) {
		auto [type, x, y] = dq.front();
		dq.pop_front();
		for (int d = 0; d < 4; d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < n && 0 <= yy && yy < m && a[xx][yy] != '#' && dist[type][xx][yy] > dist[type][x][y] + !isdigit(a[xx][yy])) {
				dist[type][xx][yy] = dist[type][x][y] + !isdigit(a[xx][yy]);
				if (isdigit(a[xx][yy])) {
					dq.push_front({type, xx, yy});
				} else {
					dq.push_back({type, xx, yy});
				}
			}
		}
	}
	int ans = n * m * 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2 * (a[i][j] == '.'));
		}
	}
	cout << (ans == n * m * 3 ? -1 : ans);
}