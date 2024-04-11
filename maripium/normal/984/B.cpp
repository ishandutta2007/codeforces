#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
char c[N][N];

bool valid(int x,int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int x = 0;x < n;++x) {
		for (int y = 0;y < m;++y) {
			cin >> c[x][y];
		}
	}
	
	for (int x = 0;x < n;++x) {
		for (int y = 0;y < m;++y) {
			if (c[x][y] == '*') continue;
			else if (c[x][y] == '.') {
				for (int i = 0;i < 8;++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (!valid(nx, ny)) continue;
					if (c[nx][ny] == '*') return cout << "NO",0;
				}
			} else {
				int cnt = 0;
				for (int i = 0;i < 8;++i) {
					int nx = x + dx[i], ny = y + dy[i];
					if (!valid(nx, ny)) continue;
					if (c[nx][ny] == '*') cnt++;
				}
				if (c[x][y] - '0' != cnt) return cout << "NO",0;
			}
		}
	}
	cout << "YES";
}