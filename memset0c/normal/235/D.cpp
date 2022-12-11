// =================================
//   author: memset0
//   date: 2019.05.10 09:17:03
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

const int N = 3010;
double ans;
bool vis[N], tag[N];
std::pair<int, int> R;
std::vector<int> C, S[N], G[N];
int n, m, dep[N], fa[N], d[N][N];

inline int dis(int u, int v) { return d[u][v]; }
inline int dis2(int u, int v) { return std::min(d[u][R.first] + d[R.second][v] + 1, d[u][R.second] + d[R.first][v] + 1); }

std::vector<int> dfs(int u) {
	// printf("dfs %d\n");
	vis[u] = 1;
	std::vector<int> U(1, u);
	for (auto v : G[u]) if (v != fa[u]) {
		if (vis[v]) {
			R = std::make_pair(u, v);
		} else {
			fa[v] = u, dep[v] = dep[u] + 1;
			// printf(">> %d -> %d\n", u, v);
			auto V = dfs(v);
			for (auto i : U) for (auto j : V)
				d[i][j] = d[j][i] = dep[i] + dep[j] - (dep[u] << 1);
			for (auto v : V) U.push_back(v);
		}
	}
	return U;
}

void addNodes(int u, int fa, std::vector<int> &S) {
	// printf("add nodes %d\n", u);
	S.push_back(u);
	for (auto v : G[u]) if (v != fa) {
		// printf("%d -> %d\n", u, v);
		addNodes(v, u, S);
	}
}

void main() {
	read(n);
	for (int u, v,  i = 1; i <= n; i++) {
		read(u), read(v), ++u, ++v;
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);

	int u = R.first, v = R.second;
	// printf(">> %d %d\n", R.first, R.second);
	if (dep[u] > dep[v]) std::swap(u, v);
	while (dep[v] > dep[u]) tag[v] = 1, v = fa[v];
	while (u != v) tag[u] = tag[v] = 1, u = fa[u], v = fa[v];
	tag[u] = 1;
	for (int i = 1; i <= n; i++) if (tag[i]) C.push_back(i);

	for (auto u : C) {
		S[u].push_back(u);
		for (auto v : G[u]) if (!tag[v]) {
			// printf("%d -> %d\n", u, v);
			addNodes(v, u, S[u]);
		}
		// print(S[u], 0, S[u].size() - 1, "S[" + std::to_string(u) + "]");
	}

	// for (int i = 1; i <= n; i++) 
	// 	for (int j = 1; j <= n; j++)
	// 		print(d[i][j], " \n"[j == n]);
	for (auto ru : C)
		for (auto rv : C) if (ru != rv) {
			int y = dis(ru, rv) - 1, z = dis2(ru, rv) - 1;
			for (auto u : S[ru])
				for (auto v : S[rv]) {
					int x = dis(u, ru) + dis(v, rv) + 2;
					double w = (1 / (double)(x + y + z)) * (1 + y / (double)(x + z) + z / (double)(x + y));
					// printf("%d -> %d : %.4lf | %d %d %d\n", u, v, w, x, y, z);
					ans += w;
				}
		}
	for (auto r : C)
		for (auto u : S[r])
			for (auto v : S[r]) if (u != v) {
				double w = 1 / ((double)dis(u, v) + 1);
				// printf("%d -> %d : %.4lf\n", u, v, w);
				ans += w;
			}
	printf("%.15lf\n", ans + n);
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}