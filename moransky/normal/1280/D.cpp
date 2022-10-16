#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 3e3 + 5;

typedef pair<int, LL> PII;

const PII INF = mp(0, -1e18);

int n, m, a[N], b[N], w[N], sz[N];

PII f[N][N], h[N];

vector<int> g[N];

void inline clear() {
	for (int i = 1; i <= n; i++) g[i].clear();
}

void inline chk(PII &x, PII y) {
	if (y > x) x = y;
}

void dfs(int u, int fa) {
	sz[u] = 1;
	f[u][0] = mp(0, w[u]);
	for (int k = 0; k < g[u].size(); k++) {
		int v = g[u][k];
		if (v == fa) continue;
		dfs(v, u);
		for (int i = 0; i < sz[u] + sz[v]; i++) h[i] = INF;
		for (int i = 0; i < sz[u]; i++) {
			for (int j = 0; j < sz[v]; j++) {
				chk(h[i + j], mp(f[u][i].fi + f[v][j].fi, f[u][i].se + f[v][j].se));
				chk(h[i + j + 1], mp(f[u][i].fi + f[v][j].fi + (f[v][j].se > 0), f[u][i].se));
			}
		}
		sz[u] += sz[v];
		for (int i = 0; i < sz[u]; i++) f[u][i] = h[i];
	}
}

int main() {
	int T; read(T);
	while (T--) {
		read(n); read(m);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= n; i++) read(b[i]), w[i] = b[i] - a[i];
		for (int i = 1, u, v; i < n; i++) {
			read(u); read(v);
			g[u].pb(v), g[v].pb(u);
		}
		dfs(1, 0);
		int ans = f[1][m - 1].fi + (f[1][m - 1].se > 0);
		printf("%d\n", ans);
		clear();
	}
	return 0;
}