// =================================
//   author: memset0
//   date: 2019.05.09 20:06:48
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

const int N = 2e5 + 10, mod = 1e9 + 7;
int n, ans, tim, priCnt;
std::vector<int> S, G[N];
int fa[N], son[N], siz[N], top[N], pri[N], vis[N], tag[N];
int a[N], b[N], f[N], g[N], in[N], out[N], dep[N], phi[N], mu[N];

inline int dec(int a, int b) { a -= b; return a < 0 ? a + mod : a; }
inline int inc(int a, int b) { a += b; return a >= mod ? a - mod : a; }
inline int mul(int a, int b) { return (ll)a * b - (ll)a * b / mod * mod; }
inline int inv(int x) { return x < 2 ? 1 : mul(mod - mod / x, inv(mod % x)); }

void dfs1(int u) {
	siz[u] = 1;
	for (auto v : G[u]) if (v != fa[u]) {
		fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int tpt) {
	top[u] = tpt, in[u] = ++tim;
	if (siz[u] == 1) return;
	dfs2(son[u], tpt);
	for (auto v : G[u]) if (v != fa[u] && v != son[u])
		dfs2(v, v);
}

inline int lca(int u, int v) {
	// printf("lca %d %d", u, v);
	while (top[u] != top[v]) {
		if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
		v = fa[top[v]];
	}
	// printf(" => %d\n", dep[u] < dep[v] ? u : v);
	return dep[u] < dep[v] ? u : v;
}

struct treeClass {
	std::vector<int> T, G[N];
	int ans, top, stk[N], depS[N], phiS[N], mulS[N];

	static inline bool compByDfn(int a, int b) { return in[a] < in[b]; }
	void clear() { for (auto u : T) G[u].clear(); T.clear(), top = 0, ans = 0; }
	
	void dfs(int u) {
		phiS[u] = tag[u] ? phi[u] : 0;
		depS[u] = tag[u] ? dep[u] : 0;
		mulS[u] = tag[u] ? mul(phi[u], dep[u]) : 0;
		// printf("mul(%d) => %d\n", u, mulS[u]);
		for (auto v : G[u]) {
			dfs(v);
			ans = inc(ans, mul(phiS[v], mulS[u]));
			ans = inc(ans, mul(phiS[u], mulS[v]));
			ans = dec(ans, mul(inc(dep[u], dep[u]), mul(phiS[u], phiS[v])));
			// printf("%d -> %d : %d %d %d\n", u, v,
			// 	mul(phiS[v], mulS[u]),
			// 	mul(phiS[u], mulS[v]),
			// 	mul(inc(dep[u], dep[u]), mul(phiS[u], phiS[v])));
			phiS[u] = inc(phiS[u], phiS[v]);
			depS[u] = inc(depS[u], depS[v]);
			mulS[u] = inc(mulS[u], mulS[v]);
		}
		// printf("dfs %d -> ans = %d\n", u, ans);
	}

	void build(std::vector<int> &S) {
		bool flag = false;
		for (int i = 0; i < S.size(); i++) flag |= S[i] == 1;
		if (!flag) S.push_back(1);
		std::sort(S.begin(), S.end(), compByDfn);
		for (int i = 0; i < S.size(); i++) {
			int u = S[i], lca = ringo::lca(u, stk[top]);
			if (lca != stk[top]) {
				while (top >= 2 && dep[stk[top - 1]] >= dep[lca])
					G[stk[top - 1]].push_back(stk[top]), top--;
				if (stk[top] != lca) {
					G[lca].push_back(stk[top--]);
					stk[++top] = lca, T.push_back(lca);
				}
			}
			stk[++top] = u, T.push_back(u);
		}
		for (int i = 1; i < top; i++) G[stk[i]].push_back(stk[i + 1]);
		// printf("build\n");
		// print(S, 0, S.size() - 1, "S");
		// print(T, 0, T.size() - 1, "T");
		// print(stk, 1, top, "stk");
		// for (int i = 1; i <= n; i++)
		// 	for (auto j : G[i])
		// 		printf("%d -> %d\n", i, j);
		S.clear();
	}
} tree;

void main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), b[a[i]] = i;
	for (int u, v, i = 1; i < n; i++) {
		read(u), read(v);
		G[u].push_back(v), G[v].push_back(u);
	}
	phi[b[1]] = mu[1] = dep[1] = 1, dfs1(1), dfs2(1, 1);;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) phi[b[i]] = i - 1, mu[i] = mod - 1, pri[++priCnt] = i;
		for (int j = 1, k; j <= priCnt && i * pri[j] <= n; j++) {
			k = i * pri[j], vis[k] = 1;
			if (i % pri[j]) mu[k] = dec(0, mu[i]), phi[b[k]] = phi[b[i]] * (pri[j] - 1);
			else { mu[k] = 0, phi[b[k]] = phi[b[i]] * pri[j]; break; }
		}
	}
	// print(a, 1, n, "a");
	// print(phi, 1, n, "phi");
	// print(dep, 1, n, "dep");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i * j <= n; j++) S.push_back(b[i * j]), tag[b[i * j]] = 1;
		tree.clear(), tree.build(S), tree.dfs(1);
		for (int j = 1; i * j <= n; j++) tag[b[i * j]] = 0;
		g[i] = tree.ans;
		// printf("[gcd = %d] ans = %d mul = %d\n", i, tree.ans, movement);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; i * j <= n; j++)
			f[i] = inc(f[i], mul(g[i * j], mu[j]));
		f[i] = mul(f[i], mul(i, inv(phi[b[i]])));
	}
	for (int i = 1; i <= n; i++) ans = inc(ans, f[i]);
	// print(f, 1, n, "f"), print(g, 1, n, "g");
	// print(ans, '\n');
	print(mul(ans << 1, inv(mul(n, n - 1))), '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}