#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const int maxn = 1e5 + 10;
int n,m,d;
struct Edge {
	int v,nxt;
}e[maxn << 1];
int h[maxn],cnt_e;
void add_e(int x, int y) {
	e[++cnt_e] = {y, h[x]};
	h[x] = cnt_e;
}
map <string, int> mp;
int col[maxn];

int dep[maxn],siz[maxn],son[maxn],fa[maxn],st[maxn],ed[maxn],id[maxn],idx;
void dfs1(int u, int pre) {
	dep[u] = dep[pre] + 1;
	siz[u] = 1;
	st[u] = ++idx;
	id[idx] = u;
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs1(v, u), siz[u] += siz[v];
		if (!son[u] || siz[son[u]] < siz[v]) son[u] = v;
	}
	ed[u] = idx;
}

set <int> cnt[maxn];
vector <pii> q[maxn];
int ans[maxn];
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
		for (int x = st[v]; x <= ed[v]; ++x)
			cnt[dep[id[x]]].insert(col[id[x]]);
	}
	cnt[dep[u]].insert(col[u]);
	for (pii p : q[u])
		if (p.first <= n) ans[p.second] = cnt[p.first].size();
	if (clr)
		for (int x = st[u]; x <= ed[u]; ++x) cnt[dep[id[x]]].clear();
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s >> fa[i];
		auto it = mp.find(s);
		if (it != mp.end()) col[i] = it -> second;
		else col[i] = mp[s] = ++d;
		if (fa[i]) add_e(fa[i], i), add_e(i, fa[i]);
	}
	for (int i = 1; i <= n; ++i)
		if (!fa[i]) dfs1(i, 0);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int v,k;
		scanf("%d%d", &v, &k);
		q[v].push_back({dep[v] + k, i});
	}
	for (int i = 1; i <= n; ++i)
		if (!fa[i]) dfs2(i, 0, 1);
	for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}
//