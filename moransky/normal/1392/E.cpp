// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 30;

int n, w[N][N], b[N][N];

LL a[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int t = i + j - 2;
			a[i][j] = (1ll << t) ^ a[i - 1][j + 1];
			b[i][j] = t, w[i][j] = a[i][j] >> t;
			printf("%lld ", a[i][j]);
		} 
		puts("");
		fflush(stdout);
	}
	int q; scanf("%d", &q);
	while (q--) {
		LL k; scanf("%lld", &k);
		int x = 1, y = 1;
		while (1) {
			printf("%d %d\n", x, y);
			fflush(stdout);
			if (x == n && y == n) break;
			if (y == n) x++;
			else if (x == n) y++;
			else {
				int t = b[x + 1][y];
				if ((k >> t & 1) == w[x + 1][y])x++;
				else y++;
			}
		}
		puts(""); fflush(stdout);
	}
	return 0;
}