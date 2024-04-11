// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, P = 1e9 + 7;

int n, a[N], fa[N], ans, sz[N];

PII D[N], U[N];

vector<int> g[N];

PII inline rev(PII a) {
	swap(a.fi, a.se);
	return a;
}

PII inline operator + (const PII &a, const PII &b) {
	return mp((a.fi + b.fi) % P, (a.se + b.se) % P);
}

PII inline operator - (const PII &a, const PII &b) {
	return mp((a.fi - b.fi + P) % P, (a.se - b.se + P) % P);
}

void dfs1(int u) {
	sz[u] = 1;
	D[u].fi = 1;
	for (int v: g[u]) {
		if (v == fa[u]) continue;
		fa[v] = u;
		dfs1(v);
		sz[u] += sz[v];
		D[u] = D[u] + rev(D[v]);
	}
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int inline calc(PII x, int y) {
	return 1ll * y * (x.fi - x.se + P) % P;
}

void dfs2(int u) {
	int gx = n;
	for (int v: g[u]) {
		if (v == fa[u]) continue;
		U[v] = rev(U[u] + D[u] - rev(D[v]));
		add(gx, calc(rev(D[v]), n - sz[v]));
		dfs2(v);
	}
	add(gx, calc(U[u], sz[u]));
	add(ans, 1ll * gx * a[u] % P);
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), a[i] = (a[i] + P) % P;
	for (int i = 1, u, v; i < n; i++)
		read(u), read(v), g[u].pb(v), g[v].pb(u);
	dfs1(1);
	dfs2(1);
	printf("%d\n", ans);
    return 0;
}