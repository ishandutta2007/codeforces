#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10, m = 1000;
int n, k;
db f[2][m + 10], ans;

int main() {
	scanf("%d%d", &n, &k);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		int p = i & 1, q = p ^ 1;
		for (int j = 0; j <= m; ++j) {
			f[p][j] =
				f[q][j] * (k - 1) / k +
				(f[q][j + 1] + j + f[q][j] * j + j * (j + 1) / 2) / (j + 1) / k;
		}
	}
	printf("%.10lf\n", f[n & 1][1] * k);
	return 0;
}