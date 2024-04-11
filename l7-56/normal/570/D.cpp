#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int maxn = 5e5 + 10;
int n,m,col[maxn];
struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add_e(int x, int y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}

int dep[maxn],siz[maxn],son[maxn],st[maxn],ed[maxn],id[maxn],idx;
void dfs1(int u, int pre) {
	siz[u] = 1;
	dep[u] = dep[pre] + 1;
	st[u] = ++idx;
	id[idx] = u;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

int cnt[maxn][30],res[maxn];
void upd(int u) {
	res[dep[u]] -= cnt[dep[u]][col[u]];
	cnt[dep[u]][col[u]] ^= 1;
	res[dep[u]] += cnt[dep[u]][col[u]];
}

int ans[maxn];
vector <pii> q[maxn];
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
		for (int x = st[v]; x <= ed[v]; ++x) upd(id[x]);
	}
	upd(u);
	for (pii p : q[u]) ans[p.second] = res[p.first];
	if (clr)
		for (int x = st[u]; x <= ed[u]; ++x) upd(id[x]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; ++i) {
		int p;
		scanf("%d", &p);
		add_e(p, i), add_e(i, p);
	}
	char s[maxn];
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) col[i] = s[i] - 'a';
	for (int i = 1; i <= m; ++i) {
		int a,b;
		scanf("%d%d", &a, &b);
		q[a].push_back({b, i});
	}
	dfs1(1, 0);
	dfs2(1, 0, 1);
	for (int i = 1; i <= m; ++i)
		printf(ans[i] < 2 ? "Yes\n" : "No\n");
	return 0;
}