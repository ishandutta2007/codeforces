// Skyqwq
#include <iostream>
#include <cstdio>
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

const int N = 3e5 + 5;

typedef pair<int, int> PII;

int n, w[N];

LL ans = -9e18, f[N];

vector<PII> g[N];

void dfs(int u, int fa) {
	f[u] = w[u];
	chkMax(ans, (LL)w[u]);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].fi, t = g[u][i].se;
		if (v == fa) continue;
		dfs(v, u);
		chkMax(ans, f[u] + f[v] - t);
		chkMax(f[u], w[u] - t + f[v]);
	}
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(w[i]);
	for (int i = 1; i < n; i++) {
		int u, v, w; read(u), read(v), read(w);
		g[u].pb(mp(v, w)), g[v].pb(mp(u, w));
	}
	dfs(1, 0);
	print(ans);
	return 0;
}