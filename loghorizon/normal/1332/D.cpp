#include <iostream>
#include <cstdio>

using namespace std;

const int N = 505;

int n = 3, m = 3, a[N][N], f[N][N];

int K;

int main() {
	scanf("%d", &K);
	int v = (1 << 18) - 1, w = 1 << 17;
	a[1][1] = a[1][2] = a[2][3] = v;
	a[1][3] = a[3][3] = K, a[2][2] = w;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
	return 0;
}