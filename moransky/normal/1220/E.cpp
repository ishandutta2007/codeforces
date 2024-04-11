// Skyqwq
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, m, S, d[N], w[N], c[N], cnt, sz[N];

LL s = 0, mx = 0, mx2 = 0;

bool f = 0;

int head[N], numE = 1;

int dfn[N], low[N], dfncnt;

bool st[N];

set<int> g[N];

struct E{
	int next, v;
} e[N << 1];

void inline add(int u, int v) {
	e[++numE] = (E) { head[u], v };
	head[u] = numE;
} 

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++dfncnt;
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		if (!dfn[v]) {
			tarjan(v, u), low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) st[i >> 1] = 1;
		} else low[u] = min(low[u], dfn[v]);
	}
}

int pos[N];

LL val[N], sum[N];

void dfs(int u) {
	c[u] = cnt, sz[cnt]++;
	pos[cnt] = u;
	val[cnt] += w[u];
	sum[cnt] += w[u];
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (st[i >> 1]) continue;
		if (!c[v]) dfs(v);
	}
}

int q[N];

void inline topo() {
	int hh = 1, tt = 0;
	for (int i = 1; i <= cnt; i++)
		if (sz[i] == 1 && d[i] == 1 && c[S] != i) q[++tt] = i;
	while (hh <= tt) {
		int u = q[hh++];
		mx = max(mx, val[u]);
		s -= sum[u];
		for (int v: g[u]) {
			val[v] = max(val[v], sum[v] + val[u]);
			if (--d[v] == 1 && sz[v] == 1 && c[S] != v) {
				q[++tt] = v;
			}
		}
	}
}

void dfs2(int u, int fa, LL t) {
	t += w[u];
	mx = max(mx, t);
	for (int i = head[u]; i; i = e[i].next) {
		int v = e[i].v;
		if (v == fa) continue;
		dfs2(v, u, t);
	}
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", w + i), s += w[i];
	for (int i = 1, u, v; i <= m; i++)
		scanf("%d%d", &u, &v), add(u, v), add(v, u);
	tarjan(1, 0);
	for (int i = 1; i <= n; i++)
		if (!c[i]) ++cnt, dfs(i);
	scanf("%d", &S);
	if (cnt == n) {
		dfs2(S, 0, 0);
		printf("%lld\n", mx);
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		int a = c[e[i * 2].v], b = c[e[i * 2 + 1].v];
		if (a != b && !g[a].count(b)) {
			d[a]++, d[b]++;
			g[a].insert(b), g[b].insert(a);
		}
	}
	topo();
	printf("%lld\n", s + mx);
	return 0;
}