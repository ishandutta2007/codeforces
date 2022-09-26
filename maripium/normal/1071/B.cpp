#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int dx[] = {0, 1};
const int dy[] = {1, 0};

int n, k;
char a[N][N];
int f[N][N];
bool visit[N][N];
vector<pair<int,int>> opt;

bool inside(int x,int y) {
	return x > 0 && x <= n && y > 0 && y <= n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	memset(f, 69, sizeof f);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i + j == 2) f[i][j] = 0;
			if (i > 1) f[i][j] = min(f[i][j], f[i - 1][j]);
			if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1]);
			if (a[i][j] != 'a') f[i][j]++;
		}
	}
	int mx = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (f[i][j] <= k) mx = max(mx, i + j - 1);
		}
	}
	for (int i = 1; i <= mx; ++i) cout << 'a';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (f[i][j] <= k && i + j - 1 == mx) {
				opt.push_back({i, j});
			}
		}
	}
	if (opt.empty()) cout << a[1][1], opt.push_back({1, 1}), mx++;
	for (int it = mx + 1; it <= n + n - 1; ++it) {
		vector<pair<int,int>> new_opt;
		int mn = 26;
		for (auto c : opt) {
			int x = c.first, y = c.second;
			for (int i = 0; i < 2; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!inside(nx, ny)) continue;
				if (visit[nx][ny]) continue;
				visit[nx][ny] = 1;
				if (a[nx][ny] < (mn + 'a')) mn = a[nx][ny] - 'a', new_opt.clear();
				if (a[nx][ny] == (mn + 'a')) new_opt.push_back({nx, ny});
			}
		}
		for (auto c : opt) {
			int x = c.first, y = c.second;
			for (int i = 0; i < 2; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (!inside(nx, ny)) continue;
				visit[nx][ny] = 0;
			}
		}
		cout << char(mn + 'a'); opt.swap(new_opt);
	}
}