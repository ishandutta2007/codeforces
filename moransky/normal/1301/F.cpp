#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> PII;

const int N = 1005, K = 41, INF = 1e9;

int n, m, k, Q, d[K][N][N], a[N][N];

PII q[N * N];

vector<PII> c[K];

bool vis[K];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void inline bfs(int col) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) d[col][i][j] = INF;
	for (int i = 1; i <= k; i++) vis[i] = false;
	int hh = 0, tt = -1;
	for (int i = 0; i < c[col].size(); i++) {
		PII u = c[col][i];
		q[++tt] = u;
		d[col][u.first][u.second] = 0;
	}
	while (hh <= tt) {
		PII u = q[hh++];
		if (!vis[a[u.first][u.second]]) {
			int now = a[u.first][u.second];
			vis[now] = true;
			for (int i = 0; i < c[now].size(); i++) {
				PII v = c[now][i];
				if (d[col][u.first][u.second] + 1 < d[col][v.first][v.second]) {
					d[col][v.first][v.second] = d[col][u.first][u.second] + 1;
					q[++tt] = v;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = u.first + dx[i], ny = u.second + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if (d[col][u.first][u.second] + 1 < d[col][nx][ny]) {
				d[col][nx][ny] = d[col][u.first][u.second] + 1;
				q[++tt] = make_pair(nx, ny);
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			c[a[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= k; i++) bfs(i);
	scanf("%d", &Q);
	while (Q--) {
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int res = abs(r2 - r1) + abs(c2 - c1);
		for (int i = 1; i <= k; i++) res = min(res, d[i][r1][c1] + 1 + d[i][r2][c2]);
		printf("%d\n", res);
	}
	return 0;
}