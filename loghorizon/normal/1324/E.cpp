#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2005, INF = 0xcfcfcfcf;

int n, h, l, r, a[N], f[N][N];

int main() {
	scanf("%d%d%d%d", &n, &h, &l, &r);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);

	memset(f, 0xcf, sizeof f);
	f[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < h; j++) {
			if (f[i][j] < 0) continue;
			int t = (j + a[i + 1]) % h;
			f[i + 1][t] = max(f[i + 1][t], f[i][j] + (l <= t && t <= r ? 1 : 0));
			t = (j + a[i + 1] - 1 + h) % h;
			f[i + 1][t] = max(f[i + 1][t], f[i][j] + (l <= t && t <= r ? 1 : 0));
		}
	}

	int ans = 0;
	for (int j = 0; j < h; j++) ans = max(f[n][j], ans);
	printf("%d\n", ans);
	return 0;
}