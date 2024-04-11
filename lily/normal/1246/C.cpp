#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 2011
#define MOD 1000000007

int n, m;
char s[N][N];
int R[N][N], C[N][N];
LL f[N][N], g[N][N], c[N][N], d[N][N];

void upd(LL &x, LL y) {
	(x += y) %= MOD;
}


int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}	
	for (int i = 1; i <= n; i++) {
		for (int j = m; j; j--) {
			R[i][j] = R[i][j + 1] + (s[i][j + 1] == 'R');
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n; i; i--) {
			C[i][j] = C[i + 1][j] + (s[i + 1][j] == 'R');
		}
	}
	if (n == 1 || m == 1){
		printf("%d\n", int(R[1][1] == 0 && C[1][1] == 0));
		return 0;
	}
	f[1][1] = 1; g[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			upd(d[i][j], d[i - 1][j]);
			upd(f[i][j], d[i][j]);
		}
		for (int j = 1; j <= m; j++) {
			upd(c[i][j + 1], f[i][j]);
			upd(c[i][m - R[i][j] + 1], -f[i][j]);
		}
		for (int j = 1; j <= m; j++) {
			upd(c[i][j], c[i][j - 1]);
			upd(g[i][j], c[i][j]);
		}
		for (int j = 1; j <= m; j++) {
			upd(d[i + 1][j], g[i][j]);
			upd(d[n - C[i][j] + 1][j], -g[i][j]);
		}
	}
	printf("%d\n", int(((f[n][m] + g[n][m]) % MOD + MOD) % MOD));
}