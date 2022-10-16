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

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5005, INF = 0x3f3f3f3f;

int n, a[N], f[N][N], g[N][N];

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	memset(f, 0x3f, sizeof f);
	memset(g, 0x3f, sizeof g);
	f[0][0] = g[0][0] = 0;
	f[1][1] = max(a[2] - a[1] + 1, 0);
	f[2][1] = max(a[1] - a[2] + 1, 0) + max(a[3] - a[2] + 1, 0);
	for (int i = 0; i <= n; i++) {
		if (i) {
			for (int j = 0; j <= n; j++)
				g[i][j] = min(f[i][j], g[i - 1][j]);
		}
		if (i + 2 <= n && i) {
			int A = min(a[i + 1], a[i] - 1);
			int w = 0;
			if (A >= a[i + 2]) w += A - a[i + 2] + 1;
			if (a[i + 3] >= a[i + 2]) w += a[i + 3] - a[i + 2] + 1;
			for (int j = 0; j <= n; j++) {
				if (f[i][j] == INF) continue;
				chkMin(f[i + 2][j + 1], f[i][j] + w);
			}
		}
		if (i + 3 <= n) {
			int A = a[i + 2];
			int w = 0;
			if (A >= a[i + 3]) w += A - a[i + 3] + 1;
			if (a[i + 4] >= a[i + 3]) w += a[i + 4] - a[i + 3] + 1;
			for (int j = 0; j <= n; j++) {
				if (g[i][j] == INF) continue;
				chkMin(f[i + 3][j + 1], g[i][j] + w);
			}
		}
	}
	for (int i = 1; i <= (n + 1) / 2; i++) printf("%d ", g[n][i]);
}