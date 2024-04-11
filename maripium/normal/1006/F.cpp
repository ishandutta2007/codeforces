#include <bits/stdc++.h>
using namespace std;

const pair<int,int> Go[] = {{1, 0}, {0, 1}};
const pair<int,int> Back[] = {{-1, 0}, {0, -1}};

int n, m;
long long k, a[25][25];
map<long long,long long> mp[25][25];

bool valid(int x,int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= m; ++y) {
			cin >> a[x][y];
		}
	}
	
	if (n == 1 && m == 1) return cout << (a[1][1] == k) << '\n',0;
	// solve go
	int len = (m + n - 2) >> 1;
	mp[1][1][a[1][1]] = 1;
	for (int cnt = 0; cnt < len; ++cnt) {
		for (int x = 1; x <= n; ++x) {
			int y = cnt + 2 - x;
			if (!valid(x, y)) continue;
			for (int i = 0; i < 2; ++i) {
				int nx = x + Go[i].first, ny = y + Go[i].second;
				if (!valid(nx, ny)) continue;
				for (auto it : mp[x][y]) mp[nx][ny][it.first ^ a[nx][ny]] += it.second;
			} 
		}
	}
	
	// solve back
	len = m + n - 3 - len;
	mp[n][m][a[n][m]] = 1;
	for (int cnt = 0; cnt < len; ++cnt) {
		for (int x = 1; x <= n; ++x) {
			int y = n + m - cnt - x;
			if (!valid(x, y)) continue;
			for (int i = 0; i < 2; ++i) {
				int nx = x + Back[i].first, ny = y + Back[i].second;
				if (!valid(nx, ny)) continue;
				for (auto it : mp[x][y]) mp[nx][ny][it.first ^ a[nx][ny]] += it.second;
			}
		}
	}
	
	len = m + n - 3 - len;
	long long res = 0;
	for (int x = 1; x <= n; ++x) {
		int y = len + 2 - x;
		if (!valid(x, y)) continue;
		for (int i = 0; i < 2; ++i) {
			int nx = x + Go[i].first, ny = y + Go[i].second;
			for (auto it : mp[x][y]) {
				if (mp[nx][ny].count(it.first ^ k)) res += it.second * mp[nx][ny][it.first ^ k];
			}
		}
	}
	
	cout << res << '\n';
}