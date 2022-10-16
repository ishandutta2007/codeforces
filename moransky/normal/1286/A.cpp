#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 105;

int n, p[N], f[N][N][N][2];

int c[2], v[N];

void chk(int &x, int y) {
	if (y < x) x = y;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i), v[p[i]] = 1;
	for (int i = 1; i <= n; i++) {
		if (!v[i]) c[i & 1]++;
	}
	memset(f, 0x3f, sizeof f);
	if (p[1]) {
		f[1][c[0]][c[1]][p[1] & 1] = 0;
	} else {
		if (c[0]) f[1][c[0] - 1][c[1]][0] = 0;
		if (c[1]) f[1][c[0]][c[1] - 1][1] = 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				for (int u = 0; u < 2; u++) {
					if (p[i]) {
						int t = (abs(p[i] - u)) & 1;
						chk(f[i][j][k][p[i] & 1], f[i - 1][j][k][u] + t);
					} else {
						if (u == 0) chk(f[i][j][k][u], f[i - 1][j + 1][k][u ^ 1] + 1);
						if (u == 1) chk(f[i][j][k][u], f[i - 1][j][k + 1][u ^ 1] + 1);
						if (u == 0) chk(f[i][j][k][u], f[i - 1][j + 1][k][u]);
						if (u == 1) chk(f[i][j][k][u], f[i - 1][j][k + 1][u]);
					}
				}
			}
		}
	}
	printf("%d\n", min(f[n][0][0][0], f[n][0][0][1]));
	return 0;
}