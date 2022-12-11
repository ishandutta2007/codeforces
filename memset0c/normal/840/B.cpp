// =================================
//   author: memset0
//   date: 2019.01.28 10:10:18
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
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

const int N = 3e5 + 10;
int n, m, sum, a[N], vis[N];
std::vector <int> ans;

struct Graph {
	int tot = 2, hed[N], to[N << 1], nxt[N << 1], val[N << 1];
	inline void add(int u, int v, int w) { nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++; }
} G, E;

void dfs(int u, int father) {
	vis[u] = 1;
	for (int i = G.hed[u], v, w; i; i = G.nxt[i]) {
		v = G.to[i], w = G.val[i]; if (vis[v]) continue;
		E.add(u, v, w), dfs(v, u);
	}
}

void dfs2(int u) {
	for (int i = E.hed[u], v, w; i; i = E.nxt[i]) {
		v = E.to[i], w = E.val[i], dfs2(v);
		if (a[v]) a[u] ^= 1, ans.push_back(w);
	}
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) if (~a[i]) sum ^= a[i];
	for (int i = 1; i <= n; i++) if (!~a[i]) a[i] = sum, sum = 0;
	if (sum) return (void)(puts("-1"));
	for (int i = 1, u, v; i <= m; i++) read(u), read(v), G.add(u, v, i), G.add(v, u, i);
	dfs(1, 0), dfs2(1), print(ans.size(), '\n');
	for (auto i : ans) print(i, '\n');
}

} signed main() { return ringo::main(), 0; }