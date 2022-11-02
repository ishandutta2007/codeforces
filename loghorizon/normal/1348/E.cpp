#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 505;

int n, K, a[N], b[N], c[N];

bool f[N][N];

LL A = 0, B = 0;
int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i), A += a[i], B += b[i];
	LL L = A / K + B / K, R = (A + B) / K;
	if (L == R) printf("%lld\n", R);
	else {
		f[0][0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < K; j++) f[i][j] = f[i - 1][j];
			for (int j = 0; j < K; j++) {
				if (f[i - 1][j]) {
					for (int k = 1; k < K; k++) {
						if (k <= a[i] && K - k <= b[i]) {
							f[i][(j + k) % K] = true;
						}
					}
				}
			}
		}
		for (int i = 1; i < K; i++) {
			if (f[n][i]) L = max(L, (A - i) / K + (B + i) / K);
		}
		printf("%lld\n", L);
	}
	return 0;
}