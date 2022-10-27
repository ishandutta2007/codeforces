#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 3e5 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const char name[] = "DURL";

int n, m;
LL P, Q;

vector <char> G[N];
char tmp[N];


LL ans = INF;
vector <LL> dis[N];

struct node {
	int x, y;LL d;
	bool operator < (const node &a) const {
		return d > a.d;
	}
};

void check() {
	priority_queue <node> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (G[i][j] == '.') {
				dis[i][j] = 0;
				q.push({i, j, 0ll});
			}
		}
	}
	while (!q.empty()) {
		auto [x, y, d] = q.top(); q.pop();
		if (dis[x][y] != d) continue;
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k], ty = y + dy[k];
			ans = min(ans, dis[tx][ty] + d);
		}
#define upd(x, y, w) do { if (dis[x][y] > w) dis[x][y] = w, q.push({x, y, w});} while (0)
		if (G[x][y + 1] == 'L') upd(x, y + 2, d + Q);
		if (G[x][y - 1] == 'R') upd(x, y - 2, d + Q);
		if (G[x + 1][y] == 'U') upd(x + 2, y, d + Q);
		if (G[x - 1][y] == 'D') upd(x - 2, y, d + Q);
		if (G[x][y - 1] == 'U') upd(x + 1, y - 1, d + P);
		if (G[x][y - 1] == 'D') upd(x - 1, y - 1, d + P);
		if (G[x][y + 1] == 'U') upd(x + 1, y + 1, d + P);
		if (G[x][y + 1] == 'D') upd(x - 1, y + 1, d + P);
		if (G[x - 1][y] == 'R') upd(x - 1, y - 1, d + P);
		if (G[x - 1][y] == 'L') upd(x - 1, y + 1, d + P);
		if (G[x + 1][y] == 'R') upd(x + 1, y - 1, d + P);
		if (G[x + 1][y] == 'L') upd(x + 1, y + 1, d + P);
	}
}

int main() {
	int p, q;
	read(n); read(m); read(p); read(q);
	P = p, Q = q;
	for (int i = 0; i <= n + 1; i++) {
		dis[i].assign(m + 2, INF);
		G[i].assign(m + 2, '#');
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", tmp + 1);
		for (int j = 1; j <= m; j++) {
			G[i][j] = tmp[j];
		}
	}
	check();
	printf("%lld\n", ans == INF ? -1ll : ans);
}