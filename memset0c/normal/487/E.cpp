// =================================
//   author: memset0
//   date: 2019.07.01 09:42:54
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 2e5 + 10;
std::set<int> set[N];
std::vector<int> G[N], E[N];
int n, m, q, nod, len, tim, pos, w[N];
struct node { int u, l, r, mid, min; } p[N << 2];
int fa[N], top[N], dfn[N], siz[N], id[N], wid[N], low[N], stk[N], ins[N], son[N], dep[N];

void tarjan(int u, int father) {
	dfn[u] = low[u] = ++tim, stk[++len] = u, ins[u] = true;
	// printf("tarjan %d %d : %d\n", u, father, tim);
	for (auto v : G[u])
		if (!dfn[v]) {
			tarjan(v, u), low[u] = std::min(low[u], low[v]);
			// printf("%d -> %d %d\n", v, dfn[v], low[v]);
			if (low[v] >= dfn[u]) {
				E[u].push_back(++nod), E[nod].push_back(u);
				int x; do {
					x = stk[len--], ins[x] = false;
					E[x].push_back(nod), E[nod].push_back(x);
				} while (x != v);
			}
		} else if (ins[v] && v != father) {
			low[u] = std::min(low[u], dfn[v]);
		}
}

void dfs(int u) {
	// printf("dfs %d\n", u);
	siz[u] = 1;
	for (auto v : E[u]) if (v != fa[u]) {
		// printf("%d -> %d\n", u, v);
		fa[v] = u, dep[v] = dep[u] + 1, dfs(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
		if (u > n) set[u].insert(w[v]);
	}
	// if (set[u].size()) {
	// 	printf("%d : ", u);
	// 	for (const auto &it : set[u]) print(it, ' ');
	// 	putchar('\n');
	// }
	if (u > n) w[u] = *set[u].begin();
}

void dfs(int u, int tpt) {
	// printf("dfs %d %d\n", u, tpt);
	top[u] = tpt, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs(son[u], tpt);
	for (auto v : E[u]) if (v != fa[u] && v != son[u])
		dfs(v, v);
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].min = w[wid[l]]; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

void modify(int u, int k, int x) {
	if (p[u].l == p[u].r) { p[u].min = x; return; }
	if (k <= p[u].mid) modify(u << 1, k, x);
	else modify(u << 1 | 1, k, x);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r) return p[u].min;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return std::min(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

void main() {
	read(n), read(m), read(q), nod = n;
	for (int i = 1; i <= n; i++) read(w[i]);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		G[u].push_back(v), G[v].push_back(u);
	}
	tarjan(1, 0), dep[1] = 1, dfs(1), dfs(1, 1);
	build(1, 1, nod);
	// for (int i = 1; i <= nod; i++) print(w[i], " \n"[i == nod]);
	// for (int i = 1; i <= nod; i++) print(query(1, i, i), " \n"[i == nod]);
	// for (int i = 1; i <= nod; i++) print(top[i], " \n"[i == nod]);
	// for (int i = 1; i <= n; i++)
	// 	for (auto j : G[i]) if (i < j)
	// 		printf("%d <=> %d\n", i, j);
	// for (int i = 1; i <= nod; i++)
	// 	for (auto j : E[i]) if (i < j)
	// 		printf("%d <-> %d\n", i, j);
	for (int i = 1, u, v, x, ans; i <= q; i++)
		if (getchar() == 'C') {
			read(u), read(x);
			if (fa[u] > n) {
				set[fa[u]].erase(w[u]), set[fa[u]].insert(x);
				modify(1, id[fa[u]], *set[fa[u]].begin());
			}
			modify(1, id[u], w[u] = x);
		} else {
			read(u), read(v), ans = 1e9;
			// printf(">> %d %d : %d %d\n", u, v, top[u], top[v]);
			while (top[u] != top[v]) {
				if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
				// printf("=> %d\n", query(1, id[top[v]], id[v]));
				ans = std::min(ans, query(1, id[top[v]], id[v])), v = fa[top[v]];
			}
			if (dep[u] > dep[v]) std::swap(u, v);
			// printf("=> %d > %d\n", query(1, id[u], id[v]), ans);
			ans = std::min(ans, query(1, id[u], id[v]));
			// printf(">> LCA %d : %d\n", u, id[u]);
			if (u > n) ans = std::min(ans, w[fa[u]]);
			print(ans, '\n');
		}
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}