#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

vector <pii> adj[N];
int dep[N];
int n, q, rt1, rt2, ans;

void dfs1(int u, int fa) {
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v == fa) continue;
		dep[v] = dep[u] + adj[u][i].second; dfs1(v, u);
	}
}

struct tree_t {
	int fa[N][17], mxdep[N], wson[N], val[N], sum[N], pos[N], id[N], dfn[N], dep[N];
	int tot;

	void dfs1(int u, int fa) {
		tree_t::fa[u][0] = fa;
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i].first;
			if (v == fa) continue;
			dep[v] = dep[u] + adj[u][i].second;
			dfs1(v, u);
			if (mxdep[v] + adj[u][i].second > mxdep[u]) {
				mxdep[u] = mxdep[v] + adj[u][i].second;
				wson[u] = v;
			}
		}
	}

	void dfs2(int u, int fa, int top) {
		for (int i = 0; i < (int)adj[u].size(); i++) {
			int v = adj[u][i].first;
			if (v == fa) continue;
			if (v == wson[u]) {
				sum[top] += adj[u][i].second;
				dfs2(v, u, top);
			} else {
				sum[++tot] = adj[u][i].second;
				pos[tot] = v;
				dfs2(v, u, tot);
			}
		}
	}

	void ini(int rt) {
		dfs1(rt, 0); pos[1] = rt; dfs2(rt, 0, tot = 1);
		for (int i = 1; i <= tot; i++) id[i] = i;
		sort(id + 1, id + tot + 1, [&](int x, int y) { return sum[x] > sum[y]; });
		for (int i = 1; i <= tot; i++) {
			sum[id[i]] += sum[id[i - 1]];
			int u = pos[id[i]];
			while (u) {
				dfn[u] = i;
				u = wson[u];
			}
		}
		for (int j = 1; j <= 16; j++) {
			for (int i = 1; i <= n; i++) {
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
			}
		}
	}

	int jump(int x, int y, int flag = 0) {
		int tmp = x;
		for (int i = 16; i >= 0; i--) {
			if (dfn[fa[tmp][i]] >= y) {
				tmp = fa[tmp][i];
			}
		}
		if (fa[tmp][0]) tmp = fa[tmp][0];
		if (flag) return dep[x] - dep[tmp] - mxdep[tmp];
		return dep[x] - dep[tmp];
	}

	int getans(int x, int y) {
		y = min(tot, 2 * y - 1);
		if (dfn[x] <= y) return sum[id[y]];
		return max(sum[id[y - 1]] + mxdep[x] + jump(x, y), sum[id[y]] + mxdep[x] + jump(x, y + 1, 1));
	}
} tr1, tr2;

int main() {
	read(n); read(q);
	for (int i = 1; i < n; i++) {
		int u, v, w;
		read(u); read(v); read(w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs1(1, 0); rt1 = 1;
	for (int i = 2; i <= n; i++) if (dep[i] > dep[rt1]) rt1 = i;
	dfs1(rt1, 0); rt2 = 1;
	for (int i = 2; i <= n; i++) if (dep[i] > dep[rt2]) rt2 = i;
	tr1.ini(rt1); tr2.ini(rt2);
	for (int i = 1; i <= q; i++) {
		int x, y;
		read(x); read(y);
		x = (x + ans - 1) % n + 1; y = (y + ans - 1) % n + 1;
		print(ans = max(tr1.getans(x, y), tr2.getans(x, y)), '\n');
	}
	return 0;
}