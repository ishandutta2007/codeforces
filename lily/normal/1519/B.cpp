#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)

const int N = 101;

int f[N][N], g[N][N];

int main() {
	int T;
	read(T);
	while (T--) {
		int n, m, k;
		read(n); read(m); read(k);
		memset(f, 0x3f, sizeof f);
		memset(g, 128, sizeof g);
		f[1][1] = g[1][1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = (i == 1) ? 2 : 1; j <= m; j++) {
				f[i][j] = min(f[i - 1][j] + j, f[i][j - 1] + i);
				g[i][j] = max(g[i - 1][j] + j, g[i][j - 1] + i);
			}
		}
		puts((f[n][m] <= k && k <= g[n][m]) ? "YES" : "NO");
	}

}