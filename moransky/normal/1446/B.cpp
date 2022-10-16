#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 5005;

int n, m, f[N][N], ans = 0;

char a[N], b[N];

int main() {
	memset(f, 0xcf, sizeof f);
	f[0][0] = 0;
	scanf("%d%d%s%s", &n, &m, a + 1, b + 1);	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) f[i][j] = 2 + max(0, f[i - 1][j - 1]);
			else f[i][j] = max(max(0, f[i - 1][j - 1]) - 2, max(f[i - 1][j] - 1, f[i][j - 1] - 1));
			ans = max(ans, f[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}