// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

typedef pair<int, int> PII;

const int N = 1e5 + 5, P = 1e9 + 7, L = 17;

int n, q, a[N], fa[N][L], dep[N], ans[N];

vector<int> g[N];

bool st[N];

int pr[N], tot;

void inline prework(int n) {
	for (int i = 2; i <= n; i++) {
		if (!st[i]) pr[++tot] = i;
		for (int j = 1; pr[j] * i <= n; j++) {
			st[pr[j] * i] = 1;
			if (i % pr[j] == 0) break;
		}
	}
}

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b >>= 1;
	}
	return res;
}

struct T{
	vector<int> c[2];
	void inline insert(int x, int o) {
		while (c[0].size() <= x) {
			c[0].pb(0), c[1].pb(0);
		}
		c[0][x] += o, c[1][x] += o * x;
	}
	int inline get(int x) {
		int r1 = 0, r2 = 0;
		for (int i = 0; i < min(x, (int)c[0].size()); i++) {
			r1 += c[1][i];
		}
		for (int i = x; i < c[0].size(); i++) {
			r2 += c[0][i] * x;
		}
		return r1 + r2;
	}
} t[N * 8];

int idx;

map<int, int> id;

int inline get(int x) {
	if (id.count(x)) return id[x];
	return id[x] = ++idx;
}

vector<PII> c[N], e[N], d[N];

vector<PII> div(int x) {
	vector<PII> res;
	for (int i = 1; pr[i] * pr[i] <= x; i++) {
		if (x % pr[i] == 0) {
			int c = 0;
			while (x % pr[i] == 0) c++, x /= pr[i];
			res.pb(mp(pr[i], c));
		}
	}
	if (x > 1) res.pb(mp(x, 1));
	return res;
}

void dfs1(int u) {
	for (int i = 1; i < L; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa[u][0]) continue;
		fa[v][0] = u, dep[v] = dep[u] + 1;
		dfs1(v);
	}
}

int inline lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = L - 1; ~i; i--)
		if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = L - 1; ~i; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void dfs2(int u) {
	for (int i = 0; i < c[u].size(); i++) {
		PII v = c[u][i];
		t[get(v.fi)].insert(v.se, 1);
	}
	for (int i = 0; i < e[u].size(); i++) {
		PII v = e[u][i];
		int id = v.fi, w = v.se;
		for (int j = 0; j < d[id].size(); j++) {
			PII F = d[id][j];
			int res = power(F.fi, t[get(F.fi)].get(F.se));
			if (w == -1) res = power(res, P - 2);
			ans[id] = 1ll * ans[id] * res % P;
		}
	}
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (v == fa[u][0]) continue;
		dfs2(v);
	}
	for (int i = 0; i < c[u].size(); i++) {
		PII v = c[u][i];
		t[get(v.fi)].insert(v.se, -1);
	}
}

int main() {
	read(n); prework(4000);
	for (int i = 1, u, v; i < n; i++) {
		read(u), read(v);
		g[u].pb(v), g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		c[i] = div(a[i]);
	}
	read(q);
	dfs1(1);
	for (int i = 1; i <= q; i++) {
		int u, v, x; read(u), read(v), read(x);
		ans[i] = 1;
		d[i] = div(x);
		int p = lca(u, v);
		e[u].pb(mp(i, 1));
		e[v].pb(mp(i, 1));
		e[p].pb(mp(i, -1));
		if (fa[p][0]) e[fa[p][0]].pb(mp(i, -1));
	}
	dfs2(1);
	for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
	return 0;
}