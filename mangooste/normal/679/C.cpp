#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

int n, k;
vector<string> a;
vector<vector<int>> num;
vector<int> sz;

inline bool ok(int x, int y) {
	return 0 <= min(x, y) && max(x, y) < n;
}

void dfs(int x, int y, vector<pair<int, int>> &comp) {
	num[x][y] = 0;
	comp.emplace_back(x, y);
	for (int d = 0; d < 4; d++) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (ok(xx, yy) && num[xx][yy] == -1 && a[xx][yy] == '.') dfs(xx, yy, comp);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	a.resize(n);
	for (auto &x : a) cin >> x;
	num.resize(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i][j] != -1 || a[i][j] == 'X') continue;
			vector<pair<int, int>> comp;
			dfs(i, j, comp);
			for (auto[x, y] : comp) num[x][y] = sz.size();
			sz.push_back(comp.size());
		}
	}

	vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + (a[i][j] == '.');
	}
	auto get = [&](int x1, int y1, int x2, int y2) {
		return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
	};

	int ans = (sz.size() ? *max_element(sz.begin(), sz.end()) : 0);
	for (int i = 0; i + k <= n; i++) {
		vector<int> cnt(sz.size(), 0);
		int now = k * k;
		for (int j = 0; j < k && i; j++) {
			if (a[i - 1][j] == 'X') continue;
			if (!cnt[num[i - 1][j]]) now += sz[num[i - 1][j]];
			cnt[num[i - 1][j]]++;
		}
		for (int j = 0; j < k && i + k != n; j++) {
			if (a[i + k][j] == 'X') continue;
			if (!cnt[num[i + k][j]]) now += sz[num[i + k][j]];
			cnt[num[i + k][j]]++;
		}
		for (int j = i; j < i + k && k != n; j++) {
			if (a[j][k] == 'X') continue;
			if (!cnt[num[j][k]]) now += sz[num[j][k]];
			cnt[num[j][k]]++;
		}
		for (int x = i; x < i + k; x++) {
			for (int y = 0; y < k; y++) {
				if (a[x][y] == 'X') continue;
				if (!cnt[num[x][y]]) now += sz[num[x][y]];
				cnt[num[x][y]]++;
			}
		}

		ans = max(ans, now - get(i, 0, i + k - 1, k - 1));
		for (int j = 1; j + k <= n; j++) {
			for (int x = i; x < i + k && j > 1; x++) {
				if (a[x][j - 2] == 'X') continue;
				cnt[num[x][j - 2]]--;
				if (!cnt[num[x][j - 2]]) now -= sz[num[x][j - 2]];
			}
			for (int x = i; x < i + k && j + k < n; x++) {
				if (a[x][j + k] == 'X') continue;
				if (!cnt[num[x][j + k]]) now += sz[num[x][j + k]];
				cnt[num[x][j + k]]++;
			}
			if (i) {
				if (a[i - 1][j - 1] == '.') {
					cnt[num[i - 1][j - 1]]--;
					if (!cnt[num[i - 1][j - 1]]) now -= sz[num[i - 1][j - 1]];
				}
				if (a[i - 1][j + k - 1] == '.') {
					if (!cnt[num[i - 1][j + k - 1]]) now += sz[num[i - 1][j + k - 1]];
					cnt[num[i - 1][j + k - 1]]++;
				}
			}
			if (i + k < n) {
				if (a[i + k][j - 1] == '.') {
					cnt[num[i + k][j - 1]]--;
					if (!cnt[num[i + k][j - 1]]) now -= sz[num[i + k][j - 1]];
				}
				if (a[i + k][j + k - 1] == '.') {
					if (!cnt[num[i + k][j + k - 1]]) now += sz[num[i + k][j + k - 1]];
					cnt[num[i + k][j + k - 1]]++;
				}
			}
			ans = max(ans, now - get(i, j, i + k - 1, j + k - 1));
		}
	}
	cout << ans << '\n';
}