// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

typedef long long LL;

const int INF = 2e9;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5;

int n, m, val, sum[N], st[1003][1003], d[N];

int head[N], numE = 0, id[N];

struct E{
	int u, v, w;
	bool operator < (const E &b) const {
		return w < b.w;
	}
} e[N << 1], h[N];

vector<int> g[N];

// 
struct DSU{
	int f[N], sz[N];
	void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1; }
	int inline find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	void inline merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (sz[x] > sz[y]) swap(x, y);
		sz[y] += sz[x], f[x] = y;
	}
} t1, t2;

int cnt;

int vis[N];


void dfs(int u) {
	vis[u] = cnt;
	t2.merge(u, cnt);
	int L = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int R = g[u][i] - 1;
		if (L <= R) {
			for (int k = t1.find(L); k <= R; ) {
				t1.f[k] = k + 1;
				dfs(k);
				k = t1.find(k);
			}	
		}
		L = g[u][i] + 1;
	}
}
void dfs2(int u) {
	id[u] = cnt;
	for (int v = 1; v <= n; v++) {
		if (v == u || id[v] || st[u][v]) continue;
		dfs2(v); 
	}
}

bool vs[N];

LL inline kruscal() {
	int o = 0;
	for (int i = 1; i <= n; i++) vs[i] = 0, d[i] = 2e9;
	t1.init(n);
	int tot = 0;
	vs[1] = 0, d[1] = 0;
	LL res = 0;
	for (int i = 1; i <= n; i++) {
		int p = -1;
		for (int j = 1; j <= n; j++) {
			if (!vs[j] && (p == -1 || d[j] < d[p])) p = j;
		}
		vs[p] = 1;
		res += d[p];
		for (int k = 1; k <= n; k++)
			if (!vs[k]) d[k] = min(d[k], st[p][k]);
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &m); t1.init(n + 1); t2.init(n);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e[i] = (E) { u, v, w };
		val ^= w;
		g[u].pb(v), g[v].pb(u);
	}	
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end()), g[i].pb(n + 1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) cnt = i, dfs(i);
	}
	for (int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v;
		if (t2.find(u) == t2.find(v)) sum[t2.find(u)]++;
	}
	bool ok = false;
	for (int i = 1; i <= n; i++) {
		if (t2.find(i) == i) {
			int sz = t2.sz[i];
			if (sz * (sz - 1ll) / 2 - sum[i] != sz - 1) {
				ok = true;
			}
		}
	}
	if (ok) {
		LL res = 0;
		t1.init(n);
		sort(e + 1, e + 1 + m);
		for (int i = 1; i <= m; i++) {
			int u = t2.find(e[i].u), v = t2.find(e[i].v), w = e[i].w;
			if (t1.find(u) != t1.find(v)) res += w, t1.merge(u, v);
		}
		printf("%lld\n", res);
	} else {
		for (int i = 1; i <= m; i++)
			st[e[i].u][e[i].v] = st[e[i].v][e[i].u] = e[i].w;
		LL ans = 9e18;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (!st[i][j]) {
					st[i][j] = st[j][i] = val;
					e[++m] = (E) { i, j, val };
					ans = min(ans, kruscal());
					--m;
					st[i][j] = st[j][i] = 0;
				}
			}
		}
		printf("%lld\n", ans);

	}
	return 0;
}