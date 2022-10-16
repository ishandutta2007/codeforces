#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, m, a, b;

vector<int> g[N];

void inline clear() {
	for (int i = 1; i <= n; i++) g[i].clear();
}

int x, y;

bool vis[N];

void dfs(int u, int t, int &c) {
	c++;
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == t || vis[v]) continue;
		dfs(v, t, c);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		x = y = 0;
		for (int i = 1, u, v; i <= m; i++) {
			scanf("%d%d", &u, &v);
			g[u].pb(v), g[v].pb(u);
		}
		for (int i = 1; i <= n; i++) vis[i] = 0;
		dfs(a, b, x);
		for (int i = 1; i <= n; i++) vis[i] = 0;
		dfs(b, a, y);
		printf("%lld\n", 1ll * (n - x - 1) * (n - y - 1));
		clear();
	}
	return 0;
}