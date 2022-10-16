// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int N = 1e5 + 5, S = 105;

int n, m, a[N], d[S][N], k, s, q[N], b[N], t;

vector<int> g[N];

void inline bfs(int c) {
	int hh = 1, tt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == c) {
			d[c][i] = 0;
			q[++tt] = i;
		}
	while (hh <= tt) {
		int u = q[hh++];
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			int w = d[c][u] + 1;
			if (w < d[c][v]) {
				d[c][v] = w, q[++tt] = v; 
			}
		}
	}
}

int main() {
	memset(d, 0x3f, sizeof d);
	read(n), read(m), read(k), read(s);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		g[u].pb(v), g[v].pb(u);
	}
	for (int i = 1; i <= k; i++) bfs(i);
	for (int i = 1; i <= n; i++) {
		t = 0;
		for (int j = 1; j <= k; j++) b[++t] = d[j][i];
		sort(b + 1, b + 1 + t);
		int ans = 0;
		for (int j = 1; j <= s; j++) ans += b[j];
		printf("%d ", ans);
	}
	return 0;
}