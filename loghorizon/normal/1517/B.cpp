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

const int N = 105;

int n, m, b[N][N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) read(b[i][j]);
		LL ans = 0;
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				for (int k = j + 1; k <= m; k++) {
					if (b[i][k] < b[i][j]) swap(b[i][j], b[i][k]);
				}
			}
			int p = 1;
			for (int i = 1; i <= n; i++)
				if (b[i][j] <= b[p][j]) p = i;
			ans += b[p][j];
			for (int i = 1; i <= n; i++) {
				if (i == p) continue;
				for (int k = j + 1; k <= m; k++) {
					if (b[i][k] > b[i][j]) swap(b[i][j], b[i][k]);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) printf("%d ", b[i][j]);
			puts("");
		}
	}
	return 0;
}