// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>

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

const int N = 22, INF = 0x3f3f3f3f;

int n, m, g[N], f[1 << N], pre[1 << N], c[1 << N];

int d[N], t;
 
int main() {
	read(n), read(m);
	if (m == n * (n - 1) / 2) {
	    puts("0");
	    return 0;
	}
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v); --u, --v;
		g[u] |= (1 << v);
		g[v] |= (1 << u);
	}
	memset(f, 0x3f, sizeof f);
	f[0] = 0;
	for (int i = 0; i < n; i++)
		f[1 << i] = 0, c[1 << i] = -1, pre[1 << i] = 0;
	for (int i = 0; i < (1 << n); i++) {
		if (f[i] == INF) continue;
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				int t = i | g[j];
				if (f[i] + 1 < f[t]) {
					f[t] = f[i] + 1, pre[t] = i, c[t] = j;
				}
			}
		}
	}
	int ans = f[(1 << n) - 1];
	int p = (1 << n) - 1;
	while (p) {
		if (~c[p]) d[++t] = c[p];
		p = pre[p];
	}
	printf("%d\n", ans);
	for (int i = 1; i <= t; i++) printf("%d ", d[i] + 1);
	return 0;
}