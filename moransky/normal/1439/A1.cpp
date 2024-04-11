#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 105;

int n, m, a[N][N], tot;

struct Q{
	int a, b, c, d, e, f;
} e[N * N * 3];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) scanf("%1d", &a[i][j]);
		tot = 0;
		if (a[1][1]) {
			a[1][1] ^= 1, a[1][2] ^= 1, a[2][1] ^= 1;
			e[++tot] = (Q) { 1, 1, 1, 2, 2, 1 };
		}
		for (int i = 2; i <= n; i++) {
			if (a[i][1]) {
				a[i][1] ^= 1, a[i][2] ^= 1;
				a[i - 1][2] ^= 1;
				e[++tot] = (Q) { i, 1, i, 2, i - 1, 2 };
			}
		}
		if (a[1][2]) {
			a[1][2] ^= 1;
			e[++tot] = (Q) { 1, 1, 1, 2, 2, 1 };
			e[++tot] = (Q) { 1, 1, 1, 2, 2, 2 };
			e[++tot] = (Q) { 2, 1, 2, 2, 1, 2 };
		}
		
		for (int i = 3; i <= m; i++) {
			if (a[1][i]) {
				a[1][i] ^= 1, a[2][i] ^= 1;
				a[2][i - 1] ^= 1;
				e[++tot] = (Q) { 1, i, 2, i, 2, i - 1 };
			}
		}
		
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (a[i][j]) {
					e[++tot] = (Q) { i - 1, j - 1, i - 1, j, i, j };
					e[++tot] = (Q) { i - 1, j - 1, i, j - 1, i, j };
					e[++tot] = (Q) { i, j - 1, i - 1, j, i, j };
				}
			}
		}
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i++)
			printf("%d %d %d %d %d %d\n", e[i].a, e[i].b, e[i].c, e[i].d, e[i].e, e[i].f);
	}	
	return 0;
}