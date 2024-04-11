#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5;

int n, k, a[N], ret, d[N], ans[N];

vector<int> g[N];



struct C{
	int c[2][20];
};

C inline up(C a) {
	C b;
	memset(b.c, 0, sizeof b.c);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			b.c[j][(i + 1) % k] = a.c[j][i];
		}
	}
	swap(b.c[0][0], b.c[1][0]);
	return b;
}

C inline operator + (const C &a, const C &b)  {
	C c;
	memset(c.c, 0, sizeof c.c);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 2; j++) {
			c.c[j][i] = a.c[j][i] ^ b.c[j][i];
		}
	}
	return c;
}

C inline operator + (C a, int b) {
	a.c[0][0] ^= b;
	return a;
}

int inline get(const C &a) {
	int res = 0;
	for (int i = 0; i < k; i++)
		res ^= a.c[1][i];
	return res;
}

C f[N], h[N];

void dfs1(int u, int fa) {
	for (int v: g[u]) {
		if (v == fa) continue;
		d[v] = d[u] + 1;
		dfs1(v, u);
		h[v] = f[u];
		f[u] = f[u] + f[v];
	}
	f[u] = up(f[u]) + a[u];
	C now;
	memset(now.c, 0, sizeof now.c);
	for (int i = g[u].size() - 1; ~i; i--) {
		int v = g[u][i];
		if (v == fa) continue;
		h[v] = h[v] + now;
		now = now + f[v];
	}
}

void dfs2(int u, int fa) {
	ans[u] = get(f[u]) ^ get(h[u]);
	for (int v: g[u]) {
		if (v == fa) continue;
		h[v] = up(h[v]) + (h[u] + a[u]);
		h[v] = up(h[v]);
		dfs2(v, u);
	}
}

int main() {
	read(n), read(k);
	for (int i = 1, u, v; i < n; i++) {
		read(u), read(v);
		g[u].pb(v), g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) read(a[i]);
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		printf(ans[i] ? "1 " : "0 ");
}