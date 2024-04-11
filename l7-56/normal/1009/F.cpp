#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
int n;
struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add(int x, int y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

int siz[maxn],dep[maxn],son[maxn],st[maxn],ed[maxn],id[maxn],idx;
void dfs1(int u, int pre) {
	siz[u] = 1;
	dep[u] = dep[pre] + 1;
	st[u] = ++idx;
	id[idx] = u;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs1(v, u); siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

int cnt[maxn],res,ans[maxn];
void upd(int val) {
	++cnt[val];
	if (cnt[val] > cnt[res] || (cnt[val] == cnt[res] && val < res)) res = val;
}
void dfs2(int u, int pre, bool clr) {
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre || v == son[u]) continue;
		dfs2(v, u, 1);
	}
	if (son[u]) dfs2(son[u], u, 0);
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre || v == son[u]) continue;
		for (int x = st[v]; x <= ed[v]; ++x) upd(dep[id[x]]);
	}
	upd(dep[u]);
	ans[u] = res - dep[u];
	if (clr) {
		for (int x = st[u]; x <= ed[u]; ++x) cnt[dep[id[x]]] = 0;
		res = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}