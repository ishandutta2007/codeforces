/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
typedef long double LD;

#define MAXN 1005
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;
char G[MAXN][MAXN];
int dis[4][MAXN][MAXN];
bool inq[4][MAXN][MAXN];
struct sta {
	int d, x, y;
	sta () {}
	sta (int q, int w, int e) : d(q), x(w), y(e) {}
};

queue <sta> q; 

int sx, sy, tx, ty;

bool ok(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m && G[x][y] != '*';
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%s", G[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (G[i][j] == 'S') G[i][j] = '.', sx = i, sy = j;
			else if (G[i][j] == 'T') G[i][j] = '.', tx = i, ty = j;
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 0; i < 4; i++) {
		dis[i][sx][sy] = 0; q.push(sta(i, sx, sy));
		inq[i][sx][sy] = 1;
	}
	while (!q.empty()) {
		sta qq = q.front(); q.pop();
		int dd = qq.d, x = qq.x, y = qq.y, tox, toy;
		inq[dd][x][y] = 0;
		if (x == tx && y == ty) {
			puts("YES");
			return 0;
		}
		if (ok(tox = x + dx[dd], toy = y + dy[dd]) && dis[dd][tox][toy] > dis[dd][x][y]) {
			dis[dd][tox][toy] = dis[dd][x][y];
			if (!inq[dd][tox][toy]) q.push(sta(dd, tox, toy));
			inq[dd][tox][toy] = 1;
		}
		if (dis[dd][x][y] < 2) {
			for (int d = 0; d < 4; d++) {	
				if (ok(tox = x + dx[d], toy = y + dy[d]) && dis[d][tox][toy] > dis[dd][x][y] + 1) {
				dis[d][tox][toy] = dis[dd][x][y] + 1;
				if (!inq[d][tox][toy]) q.push(sta(d, tox, toy));
				inq[d][tox][toy] = 1;
				}
			}
		}
	}
	puts("NO");
	return 0;
}