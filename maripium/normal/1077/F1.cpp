#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, k, x;
long long a[N];
long long f[N][N];
long long rmq[13][N];

long long get(int l,int r) {
	int LG = __lg(r - l + 1);
	return max(rmq[LG][l], rmq[LG][r - (1 << LG) + 1]);
}

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
	memset(f, -123, sizeof f);
	f[0][0] = 0;
	for (int it = 0; it < x; ++it) {
		for (int i = 0; i <= n; ++i) rmq[0][i] = f[it][i];
		for (int i = 1; i <= 12; ++i) {
			for (int j = 0; j + (1 << i) - 1 <= n; ++j) {
				rmq[i][j] = max(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			f[it + 1][i] = a[i] + get(max(i - k, 0), i - 1);
		}
	}
	long long ans = -1;
	for (int i = n - k + 1; i <= n; ++i) ans = max(ans, f[x][i]);
	printf("%I64d\n", ans);
}