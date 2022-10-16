#include <cstdio>
#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;

const int N = 1005, M = 30005;

int n, m, s, t, pre[N], ans = INT_MAX, v1 = -1, v2 = -1;

bool ok = false;

int head[N], numE = 1, era, low[N], dfn[N], dfncnt;

bool vis[N];

struct E{
	int next, v, w;
} e[M << 1];

void inline add(int u, int v, int w) {
	e[++numE] = (E) { head[u], v, w };
	head[u] = numE;
}

void dfs(int u) {
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (!vis[v]) {
			vis[v] = true;
			pre[v] = i;
			dfs(v);
		}
	}
}

bool tarjan(int u, int last) {
	dfn[u] = low[u] = ++dfncnt;
	bool op = false;
	if (u == t) op = true;
	for (int i = head[u]; i; i = e[i].next) {
		if (i == era || i == (era ^ 1)) continue;
		int v = e[i].v;
		if (!dfn[v]) {
			if (tarjan(v, i)) {
				op = true;
				if (low[v] > dfn[u] && e[era].w + e[i].w < ans) {
					ok = true;
					ans = e[era].w + e[i].w, v1 = era >> 1, v2 = i >> 1;
				}
			}
			low[u] = min(low[u], low[v]);
		} else if (i != (last ^ 1)) low[u] = min(low[u], dfn[v]);
	}
	return op;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1, u, v, w; i <= m; i++)
		scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, w);
	vis[s] = true;
	dfs(s);
	if (!vis[t]) { 
		puts("0\n0");
		return 0;
	}
	int x = t;
	while (x != s) {
		int i = pre[x];
		era = i;
		memset(dfn, 0, sizeof dfn);
		dfncnt = 0;
		tarjan(s, 0);
		if (!dfn[t] && e[i].w < ans) {
			ans = e[i].w, v1 = i >> 1, v2 = -1;
			ok = true;
		}
		x = e[i ^ 1].v;
	}
	if (!ok) { puts("-1"); return 0; }
	else {
		printf("%d\n", ans);
		if (v2 == -1) printf("1\n%d\n", v1);
		else printf("2\n%d %d\n", v1, v2);
	}
	return 0;
}