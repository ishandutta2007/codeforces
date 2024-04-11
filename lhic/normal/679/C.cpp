#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;
const int MAXN = 510;

int n, k;
int arr[MAXN][MAXN];
int was[MAXN][MAXN];
int cl[MAXN][MAXN];
int nc[MAXN * MAXN];
int lst[MAXN * MAXN];
int tm;
int cc;
int cnt[MAXN * MAXN];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int c) {
	was[x][y] = 1;
	cl[x][y] = c;
	++cnt[c];
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!arr[nx][ny] && !was[nx][ny])
			dfs(nx, ny, c);
	}
}

int add(int x, int y) {
	if (arr[x][y])
		return 0;
	if (lst[cl[x][y]] == tm)
		return 0;
	lst[cl[x][y]] = tm;
	return cnt[cl[x][y]] - nc[cl[x][y]];
}


int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			arr[i][j] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			char c;
			scanf(" %c", &c);
			if (c == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	cc = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (!arr[i][j] && !was[i][j]) {
				dfs(i, j, cc++);
			}
		}
	int ans = 0;
	for (int i = 0; i < cc; ++i)
		ans = max(ans, cnt[i]);
	for (int i = 1; i <= n - k + 1; ++i) {
		memset(nc, 0, sizeof(nc[0]) * cc);
		for (int j = i; j < i + k; ++j)
			for (int j1 = 1; j1 <= k; ++j1)
				if (!arr[j][j1])
					++nc[cl[j][j1]];
		for (int j = 1; j <= n - k + 1; ++j) {
			++tm;
			int now = k * k;
			for (int i1 = i; i1 < i + k; ++i1)
				now += add(i1, j - 1), now += add(i1, j + k);
			for (int j1 = j; j1 < j + k; ++j1)
				now += add(i - 1, j1), now += add(i + k, j1);
			ans = max(ans, now);
			for (int i1 = i; i1 < i + k; ++i1)
				if (!arr[i1][j])
					--nc[cl[i1][j]];
			for (int i1 = i; i1 < i + k; ++i1)
				if (!arr[i1][j + k])
					++nc[cl[i1][j + k]];
		}
	}
	cout << ans << "\n";
	return 0;
}