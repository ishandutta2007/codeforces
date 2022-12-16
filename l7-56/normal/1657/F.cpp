#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;

const int maxn = 2e6 + 10;
int n,q;
namespace Tree {
	struct Edge {
		int v, nxt;
	} e[maxn << 1];
	int h[maxn], cnt_e;
	void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }
	int fa[maxn][20],dep[maxn];
	void dfs(int u, int pre) {
		fa[u][0] = pre, dep[u] = dep[pre] + 1;
		for (int i = 1; i <= 19; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (v == pre) continue;
			dfs(v, u);
		}
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		for (int i = 19; i >= 0; --i)
			if (dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
		if (x == y) return x;
		for (int i = 19; i >= 0; --i)
			if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
		return fa[x][0];
	}
	vi getPath(int st, int ed) {
		int mid = lca(st, ed);
		vi res1, res2;
		while (st != mid) res1.push_back(st), st = fa[st][0];
		res1.push_back(mid);
		while (ed != mid) res2.push_back(ed), ed = fa[ed][0];
		for (int i = res2.size() - 1; i >= 0; --i) res1.push_back(res2[i]);
		return res1;
	}
}

namespace SAT {
	struct Edge {
		int v, nxt;
	} e[maxn << 1];
	int h[maxn], cnt_e;
	void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }
	int dfn[maxn],low[maxn],idx,sta[maxn],tp,ins[maxn],scc[maxn],cnt_scc;
	void dfs(int u) {
		dfn[u] = low[u] = ++idx;
		ins[sta[++tp] = u] = 1;
		for (int j = h[u]; j; j = e[j].nxt) {
			int v = e[j].v;
			if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
			else if (ins[v]) low[u] = min(low[u], dfn[v]);
		}
		if (dfn[u] == low[u]) {
			++cnt_scc; int x;
			do {
				ins[x = sta[tp--]] = 0;
				scc[x] = cnt_scc;
			} while (x != u);
		}
	}
	bool build() {
		for (int i = 1; i <= (n + q) * 2; ++i) if (!dfn[i]) dfs(i);
		for (int i = 1; i <= n + q; ++i)
			if (scc[i] == scc[i + n + q]) return 0;
		return 1;
	}
}

char s[maxn],opt[maxn][2];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		Tree :: add(x, y), Tree :: add(y, x);
	}
	Tree :: dfs(1, 0);
	for (int i = 1; i <= q; ++i) {
		int x, y; scanf("%d%d%s", &x, &y, s + 1);
		vi v = Tree :: getPath(x, y); int len = v.size();
		for (int j = 1; j <= len; ++j) {
			int u = v[j - 1];
			char c1 = s[j], c2 = s[len - j + 1];
			if (!opt[u][0]) opt[u][0] = c1, opt[u][1] = c2;
			if (opt[u][0] != c1) SAT :: add(i, u + q + n + q), SAT :: add(u + q, i + n + q);
			if (opt[u][1] != c1) SAT :: add(i, u + q), SAT :: add(u + q + n + q, i + n + q);
			if (opt[u][0] != c2) SAT :: add(i + n + q, u + q + n + q), SAT :: add(u + q, i);
			if (opt[u][1] != c2) SAT :: add(i + n + q, u + q), SAT :: add(u + q + n + q, i);
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!opt[i][0]) opt[i][0] = opt[i][1] = 'a';
	if (!SAT :: build()) return printf("NO\n"), 0;
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		if (SAT :: scc[i + q] < SAT :: scc[i + q + n + q]) putchar(opt[i][0]);
		else putchar(opt[i][1]);
	return 0;
}