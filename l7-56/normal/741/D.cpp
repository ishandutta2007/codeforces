#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 10;
int n;
struct Edge {
	int v,w,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add_e(int x, int y, int z) {
	e[++cnt_e] = {y, z, h[x]};
	h[x] = cnt_e;
}

int st[maxn],ed[maxn],idx,id[maxn],d[maxn],dep[maxn],siz[maxn],son[maxn];
void dfs1(int u, int pre) {
	siz[u] = 1;
	st[u] = ++idx;
	id[idx] = u;
	dep[u] = dep[pre] + 1;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v, w = e[j].w;
		if (v == pre) continue;
		d[v] = d[u] ^ w;
		dfs1(v, u);
		siz[u] += siz[v];
		if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

int ans[maxn],mx[1 << 22];
int ask(int val) {
	int ret = mx[val];
	for (int bit = 0; bit < 22; ++bit) ret = max(ret, mx[(1 << bit) ^ val]);
	return ret;
}
void dfs2(int u, int pre, bool clr) {
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre || v == son[u]) continue;
		dfs2(v, u, 1);
		ans[u] = max(ans[u], ans[v]);
	}
	if (son[u]) dfs2(son[u], u, 0), ans[u] = max(ans[u], ans[son[u]]);
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre || v == son[u]) continue;
		for (int x = st[v]; x <= ed[v]; ++x) {
			int val = ask(d[id[x]]);
			if (!val) continue;
			ans[u] = max(ans[u], dep[id[x]] + val - dep[u] * 2);
		}
		for (int x = st[v]; x <= ed[v]; ++x) mx[d[id[x]]] = max(mx[d[id[x]]], dep[id[x]]);
	}
	int val = ask(d[u]);
	if (val) ans[u] = max(ans[u], val - dep[u]);
	mx[d[u]] = max(mx[d[u]], dep[u]);
	if (clr)
		for (int x = st[u]; x <= ed[u]; ++x) mx[d[id[x]]] = 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		int p; char ch[2];
		scanf("%d%s", &p, ch);
		int val = 1 << (int) (ch[0] - 'a');
		add_e(p, i, val), add_e(i, p, val);
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
	return 0;
}