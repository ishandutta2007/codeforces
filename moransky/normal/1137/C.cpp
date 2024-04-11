// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
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

const int N = 1e5 + 5, S = 51, INF = 0xcfcfcfcf;

int n, m, d, f[N][S], dfn[N], dfncnt, low[N], h[N];
int st[N], top, c[N], cnt, ans, now, t[N], dis[N];

vector<int> b[N];

bool ins[N], vis[N];

char s[N][S];

vector<int> g[N];

int inline gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void inline insert(int u, int s, int v) {
	chkMax(f[u][s], v);
}

void tarjan(int u) {
	dfn[u] = low[u] = ++dfncnt;
	st[++top] = u, ins[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (!dfn[v]) {
			tarjan(v);
			chkMin(low[u], low[v]);
		} else if (ins[v]) chkMin(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++cnt; int v;
		h[cnt] = u;
		do {
			v = st[top--], c[v] = cnt, b[cnt].pb(v), ins[v] = 0;
		} while (v != u);
	}
}

int inline abs(int x) {
	return x < 0 ? -x : x;
}

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (c[v] != c[u]) continue;
		if (!vis[v]) {
			dis[v] = dis[u] + 1;
			dfs(v);
		} else {
			t[c[u]] = gcd(t[c[u]], abs(dis[u] - dis[v]) + 1);
		}
	}
}

int main() {
	memset(f, 0xcf, sizeof f);
	read(n), read(m), read(d);
	for (int i = 1; i <= m; i++) {
		int u, v; read(u), read(v);
		g[u].pb(v);
	}
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i]);
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	insert(c[1], 0, 0);
	for (int i = 1; i <= cnt; i++) {
		dfs(h[i]);
	}
	for (int w = cnt; w; w--) {
		int D = gcd(t[w], d);
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < d; j++) {
				int F = abs(i - j);
				if (F % D == 0) {
					chkMax(f[w][j], f[w][i]);
				}
			}
		}
		for (int i = 0; i < d; i++) {
			if (f[w][i] == INF) continue;
			int tot = 0;
			for (int j = 0; j < b[w].size(); j++) {
				int u = b[w][j];
				for (int k = 0; k < d; k++) {
					if (s[u][k] == '0') continue;
					int O = abs(i + dis[u] - k);
					if (O % D == 0) {
						++tot;
						break;
					}
				}
			}
			f[w][i] += tot;
		}
		
		for (int i = 0; i < d; i++) {
			if (f[w][i] == INF) continue;
			chkMax(ans, f[w][i]);
			int tot = 0;
			for (int j = 0; j < b[w].size(); j++) {
				int u = b[w][j];
				for (int k = 0; k < g[u].size(); k++) {
					int v = g[u][k];
					if (c[u] == c[v]) continue;
					insert(c[v], (i + dis[u] + 1) % d, f[w][i]);
				}
			}
		}
	}
	print(ans);
	return 0;
}