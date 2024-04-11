#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 305, M = 2000005;

int n, m, t, q, d[M], a[N][N], f[N * N], sz[N * N];

struct Q{
	int x, y, id;
} e[M];

bool vis[N][N];

vector<Q> add[M], del[M]; 

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

bool inline merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	if (sz[x] > sz[y]) swap(x, y);
	sz[y] += sz[x], f[x] = y;
	return true;
}

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void work(const vector<Q> &s, int opp) {
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) vis[i][j] = false;
	for (int i = 1; i <= n * m; i++) f[i] = i, sz[i] = 1;
	for (int i = 0; i < s.size(); i++) {
		Q u = s[i];
		vis[u.x][u.y] = true;
		int now = 1;
		for (int j = 0; j < 4; j++) {
			int nx = u.x + dx[j], ny = u.y + dy[j];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny]) {
				now -= merge((u.x - 1) * m + u.y, (nx - 1) * m + ny);
			}
		}
		d[u.id] += opp * now;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		if (a[x][y] == c) continue;
		add[c].push_back((Q){ x, y, i });
		del[a[x][y]].push_back((Q){ x, y, i });
		a[x][y] = c;
		t = max(t, c);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			del[a[i][j]].push_back((Q){ i, j, q + 1 });
	for (int i = 0; i <= t; i++) reverse(del[i].begin(), del[i].end());
	for (int i = 0; i <= t; i++) work(add[i], 1), work(del[i], -1);
	int ans = 1;
	for (int i = 1; i <= q; i++) {
		ans += d[i];
		printf("%d\n", ans);
	}
	return 0;
}