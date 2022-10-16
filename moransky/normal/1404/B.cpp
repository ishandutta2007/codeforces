// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, a, b, da, db, f[N], ans, d[N];

vector<int> g[N];

void dfs(int u, int fa) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		d[v] = d[u] + 1;
		dfs(v, u);
		ans = max(ans, f[u] + f[v] + 1);
		f[u] = max(f[u], f[v] + 1);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs(a, 0);
		if (2 * da >= db || d[b] <= da || ans <= 2 * da) puts("Alice");
		else puts("Bob");
		for (int i = 1; i <= n; i++)
			g[i].clear(), d[i] = f[i] = 0;
		ans = 0;
	}
	return 0;
}