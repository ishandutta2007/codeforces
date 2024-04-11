#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 505, INF = 0x3f3f3f3f;

int n, a[N], f[N][N], g[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), f[i][i] = a[i];
	for (int l = 2; l <= n; l++) {
		for (int i = 1, j; (j = i + l - 1) <= n; i++) {
			for (int k = i; k < j; k++) {
				if (f[i][k] && f[i][k] == f[k + 1][j]) {
					f[i][j] = f[i][k] + 1;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		g[i] = i;
		for (int j = 0; j < i; j++) {
			if (f[j + 1][i]) g[i] = min(g[i], g[j] + 1);
		}
	}
	printf("%d\n", g[n]);
	return 0;
}