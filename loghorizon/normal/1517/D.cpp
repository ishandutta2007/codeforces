// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

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

const int N = 505, S = 21, INF = 1e9;

int n, m, k, e1[N][N], e2[N][N], f[S][N][N];

void inline chk(int &x, int y) {
	if (y < x) x = y;
}

int main() {
	read(n); read(m); read(k);
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= m; j++) read(e1[i][j]);
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) read(e2[i][j]);
	}
	if (k & 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) printf("-1 ");
			puts("");
		}
		return 0;
	}
	for (int t = 1; t <= k / 2; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				f[t][i][j] = INF;
				if (i > 1) chk(f[t][i][j], f[t - 1][i - 1][j] + e2[i][j]);
				if (i < n) chk(f[t][i][j], f[t - 1][i + 1][j] + e2[i + 1][j]);
				if (j > 1) chk(f[t][i][j], f[t - 1][i][j - 1] + e1[i][j]);
				if (j < m) chk(f[t][i][j], f[t - 1][i][j + 1] + e1[i][j + 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) printf("%d ", f[k / 2][i][j] * 2);
			puts("");
		}
	return 0;
}