// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long LL;

#define pb push_back

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 3e5 + 5;

int n, a[N], b[N], dfn[N], dfncnt, sz[N], ans, cnt;

vector<int> g[N], e[N];

LL c[N];

void inline clear() {
	dfncnt = ans = cnt = 0;
	for (int i = 1; i <= n; i++) g[i].clear(), e[i].clear(), dfn[i] = 0, c[i] = 0;
}

void inline add(int x, int k) {
	if (x > n) return;
	for (; x <= n; x += x & -x) c[x] += k;
}

LL inline ask(int x) {
	LL res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}

void dfs1(int u, int fa) {
	sz[u] = 1;
	dfn[u] = ++dfncnt;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa) continue;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}

void dfs2(int u, int fa) {
	int k = ask(dfn[u]);
	if (!k) {
		cnt++;
	} else {
		add(dfn[k], -k);
		add(dfn[k] + sz[k], k);
	}

	add(dfn[u], u);
	add(dfn[u] + sz[u], -u);
	ans = max(ans, cnt);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa) continue;
		dfs2(v, u);
	}
	add(dfn[u], -u);
	add(dfn[u] + sz[u], u);
	cnt--;
	if (k) {
		cnt++;
		add(dfn[k], k);
		add(dfn[k] + sz[k], -k);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) scanf("%d", a + i), g[a[i]].pb(i);
		for (int i = 2; i <= n; i++) scanf("%d", b + i), e[b[i]].pb(i);
		dfs1(1, 0);
		dfs2(1, 0);
		printf("%d\n", ans);
		clear();
	}
	return 0;
}