#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int N = 3e5 + 5;

vector<int> adj[N], vec[N];
int dep[N], fa[N][20], ans[N];
int T, n, x, y, len;

void dfs1(int u, int fa) {
	::fa[u][0] = fa;
	for (int i = 1; i <= 19; i++) ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
	for (auto v: adj[u])
		if (v != fa) {
			dep[v] = dep[u] + 1;
			dfs1(v, u);
		}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int k = dep[u] - dep[v];
	for (int i = 0; i <= 19; i++) {
		if ((k >> i) & 1) {
			u = fa[u][i];
		}
	}
	if (u == v) return u;
	for (int i = 19; i >= 0; i--) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}

int dis(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) adj[i].clear();
		for (int i = 1; i < n; i++) {
			int u = read(), v = read();
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs1(1, 0);
		for (int i = 1; i <= n + 1; i++) vec[i].clear();
		for (int i = 1; i <= n; i++) vec[dep[i]].push_back(i);
		x = y = len = 0;
		int lasx = n;
		for (int i = n; i >= 1; i--) {
			for (auto j: vec[i + 1]) {
				if (!x)
					x = j;
				else if (!y) {
					y = j;
					len = dis(x, y);
				} else {
					int A = dis(x, j), B = dis(j, y);
					if (A >= B) {
						if (A > len) {
							y = j;
							len = A;
						}
					} else {
						if (B > len) {
							x = j;
							len = B;
						}
					}
				}
			}
			int nowx = max(0, i - (len + 1) / 2);
			if (!x) nowx = n;
			while (lasx > nowx) {
				ans[lasx] = i + 1;
				--lasx;
			}
		}
		while (lasx >= 1) {
			ans[lasx] = 1;
			--lasx;
		}
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		printf("\n");
	}
}