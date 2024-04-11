// =================================
//   author: memset0
//   date: 2019.03.08 17:40:35
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
	x = 0; register char c = getchar(); register bool f = 0;	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1e5 + 10, D = 51;
int n, m, d, cnt, c_dfn, top, dis, final_ans;
int col[N], cho[N], fst[N], ans[N], low[N], dfn[N], tim[N], dep[N], stk[N], able[N], ins[N], vis[N], f[N][20], a[N][D], dp[N][D], now[N][D];
char s[N];
std::vector <int> list, G[N];
std::vector <std::pair <int, int> > E[N];

inline int gcd(int x, int y) {
	if (!~x) return y;
	if (!~y) return x;
	return std::__gcd(x, y);
}

void tarjan(int u) {
	// debug("tarjan %d\n", u);
	dfn[u] = low[u] = ++c_dfn, stk[++top] = u, ins[u] = 1;
	for (auto v : G[u])
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	if (dfn[u] == low[u]) {
		++cnt;
		while (top) {
			int v = stk[top--];
			ins[v] = 0;
			col[v] = cnt;
			if (u == v) return;
		}
	}
}

void build(int u) {
	list.push_back(u);
	vis[u] = 1;
	for (auto v : G[u])
		if (col[v] == col[u] && !vis[v]) {
			dep[v] = dep[u] + 1;
			f[v][0] = u;
			build(v);
		}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) std::swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

int query(int u, int v) {
	int t = lca(u, v);
	// debug("query dis %d %d => %d\n", u, v, dep[u] + dep[v] - (dep[t] << 1));
	return dep[u] + dep[v] - (dep[t] << 1);
}

void solve(int u) {
	vis[u] = 1;
	for (auto v : G[u])
		if (col[u] == col[v]) {
			if (!vis[v]) {
				// debug(">> %d => %d\n", u, v);
				solve(v);
			} else {
				// debug(">> %d -> %d | %d %d : %d\n", u, v, ans[col[u]], query(u, v) + 1, gcd(ans[col[u]], query(u, v) + 1));
				// ans[col[u]] = gcd(ans[col[u]], query(u, v) + 1);
				ans[col[u]] = gcd(ans[col[u]], std::abs(dep[u] + 1 - dep[v]));
			}
		}
}

void dfs(int u, int dis, std::vector <int> &V) {
	tim[u] = dis, V.push_back(u);
	// debug("dfs %d %d\n", u, dis);
	for (auto v : G[u])
		if ((!~tim[v]) && col[u] == col[v]) {
			dfs(v, dis % d + 1, V);
		}
}

int get_now(int u, int x) {
	if (~now[u][x]) return now[u][x];
	std::vector <int> V;
	now[u][x] = 0;
	dfs(fst[u], x, V);
	// debug("get now %d %d\n", u, x);
	for (auto i : V) {
		for (int j = 1; j <= d; j++) {
			int tmp = (tim[i] + (j - 1) * ans[u] - 1) % d + 1;
			// debug("%d : %d %d\n", 	i, tmp, a[i][tmp]);
			if (a[i][tmp]) {
				++now[u][x];
				break;
			}
		}
	}
	// for (auto u : V) debug("[%d %d %d]\n", u, tim[u], vis[u]);
	debug(">>>> now[%d(%d)][%d] = %d\n", u, fst[u], x, now[u][x]);
	for (auto u : V) tim[u] = -1;
	return now[u][x];
}

int final_solve(int u, int x) {
    if (~dp[u][x]) return dp[u][x];
    dp[u][x] = 0;
    for (auto nxt : E[u]) {
		int v = nxt.first;
		int s = x + nxt.second;
		int GCD = gcd(ans[u], ans[v]);
		for (int i = 1; i <= d; i++) {
			int y = (s + (i - 1) * GCD - 1) % d + 1;
			debug("[%d %d] => [%d %d] : %d\n", u, x, v, y, final_solve(v, y));
			dp[u][x] = std::max(dp[u][x], final_solve(v, y));
		}
    }
    debug("dp[%d][%d] = %d + %d\n", u, x, dp[u][x], get_now(u, x));
    dp[u][x] += get_now(u, x);
    return dp[u][x];
}

void main() {
	memset(dp, -1, sizeof(dp));
	memset(tim, -1, sizeof(tim));
	memset(cho, -1, sizeof(cho));
	memset(ans, -1, sizeof(ans));
	memset(fst, -1, sizeof(fst));
	memset(now, -1, sizeof(now));
	read(n), read(m), read(d);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= d; j++)
			a[i][j] = s[j] - '0';
	}
	for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		if (!~ans[col[i]]) {
			dep[i] = 1, fst[col[i]] = i;
			list.clear();
			build(i);
			for (int i = 1; i < 20; i++)
				for (auto u : list)
					f[u][i] = f[f[u][i - 1]][i - 1];
			for (auto u : list) vis[u] = 0;
			solve(i);
		}
	// for (int i = 1; i <= n; i++) print(col[i], " \n"[i == n]);
	// for (int i = 1; i <= n; i++) print(ans[i], " \n"[i == n]);
	for (int i = 1; i <= n; i++) ans[i] = gcd(ans[i], d);
	// for (int i = 1; i <= n; i++) print(dep[i], " \n"[i == n]);
	for (int u = 1; u <= n; u++)
		for (auto v : G[u])
			if (col[u] != col[v]) {
				int GCD = gcd(ans[col[u]], ans[col[v]]);
				int w = (dep[u] - dep[v] % GCD + GCD + GCD) % GCD;
				// w = (GCD - w) % GCD;
				debug("%d -> %d | %d -> %d | %d\n", u, v, col[u], col[v], w);
				E[col[u]].push_back(std::make_pair(col[v], w + 1));
			}
    print(final_solve(col[1], 1), '\n');
}

} signed main() { return ringo::main(), 0; }