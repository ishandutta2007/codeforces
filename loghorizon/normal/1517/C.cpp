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

const int N = 505;

int n, a[N], b[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) read(a[i]), b[i][i] = a[i];
	for (int i = 1; i <= n; i++) {
		int x = i, y = i;
		int t = a[i] - 1;
		while (t) {
			t--;
			if (y > 1 && !b[x][y - 1]) {
				--y;
				b[x][y] = a[i];
			} else if (x < n && !b[x + 1][y]) {
				++x;
				b[x][y] = a[i];
			} else {
				puts("-1");
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) printf("%d ", b[i][j]);
		puts("");
	}
	return 0;
}