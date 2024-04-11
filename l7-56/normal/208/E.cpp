#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int maxn = 1e5 + 10;
int n,m;
struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add_e(int x, int y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

int dep[maxn],siz[maxn],son[maxn],fa[maxn][20],st[maxn],ed[maxn],id[maxn],idx;
void dfs1(int u) {
	dep[u] = dep[fa[u][0]] + 1;
	siz[u] = 1;
	for (int i = 1; i <= 19; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	st[u] = ++idx;
	id[idx] = u;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == fa[u][0]) continue;
		dfs1(v); siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

vector <pii> q[maxn];
int cnt[maxn],ans[maxn];
void add(int u) { cnt[dep[u]]++; }
void del(int u) { cnt[dep[u]]--; }
void dfs2(int u, bool clr) {
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == fa[u][0] || v == son[u]) continue;
		dfs2(v, 1);
	}
	if (son[u]) dfs2(son[u], 0);
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == fa[u][0] || v == son[u]) continue;
		for (int x = st[v]; x <= ed[v]; ++x) add(id[x]);
	}
	add(u);
	for (pii p : q[u]) ans[p.second] = cnt[p.first] - 1;
	if (clr)
		for (int x = st[u]; x <= ed[u]; ++x) del(id[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &fa[i][0]);
		add_e(fa[i][0], i), add_e(i, fa[i][0]);
	}
	for (int i = 1; i <= n; ++i)
		if (!fa[i][0]) dfs1(i);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int v,p;
		scanf("%d%d", &v, &p);
		if (dep[v] <= p) continue;
		for (int j = 19, t = p; j >= 0; --j)
			if (t >= (1 << j)) v = fa[v][j], t -= (1 << j);
		q[v].push_back({dep[v] + p, i});
	}
	for (int i = 1; i <= n; ++i)
		if (!fa[i][0]) dfs2(i, 1);
	for (int i = 1; i <= m; ++i) printf("%d%c", ans[i], " \n"[i == m]);
	return 0;
}