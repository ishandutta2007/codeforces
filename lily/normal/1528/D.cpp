#include <bits/stdc++.h>
using namespace std;

const int N = 605;
const int INF = 0x3f3f3f3f;

struct edge {
	int v, w;
	bool operator < (const edge &a) const {
		return w < a.w;
	}
};
vector <edge> E[N];

int n, m;
int ans[N][N];
int ww[N][N];
int dis[N];
bool vis[N];


void upd(int &aa, int bb) {
	aa = min(aa, bb);
}

void work(int x) {
	memset(dis, 0x3f, sizeof dis);
	dis[x] = 0;
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int T = n; T--; ) {
		int u = 0, cur = INF;
		for (int i = 0; i < n; i++) if (!vis[i] && dis[i] < cur) cur = dis[i], u = i;
		vis[u] = 1;
		int j = E[u][0].v;
		int last = E[u][0].w;
		upd(dis[(j + cur) % n], cur + last);
		for (int i = (j + 1) % n; i != j; ++i %= n) {
			last = min(last + 1, ww[u][i]);
			upd(dis[(i + cur) % n], cur + last);
		}
	}
	for (int i = 0; i < n; i++) ans[x][i] = dis[i];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
	}
	for (int i = 0; i < n; i++) sort(E[i].begin(), E[i].end());
	memset(ww, 0x3f, sizeof ww);
	for (int i = 0; i < n; i++) {
		for (auto e : E[i]) {
			ww[i][e.v] = min(ww[i][e.v], e.w);
		}
	}
	for (int i = 0; i < n; i++) work(i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');
		}
}