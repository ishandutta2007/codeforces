#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 3605, P = 998244353;

int n, m, K, fact[N], infact[N];

int f[N][N], g[N][N], ans;

bool visX[N], visY[N];

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

void inline work(int dp[N][N], int len, bool vis[]) {
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j * 2 <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			if (i >= 2 && j >= 1 && !vis[i] && !vis[i - 1]) (dp[i][j] += dp[i - 2][j - 1]) %= P; 
		}
	}
}

int inline A(int a, int b) {
	return (LL)fact[a] * infact[a - b] % P;
}

int main() {
	scanf("%d%d%d", &n, &m, &K);
	fact[0] = infact[0] = 1;
	int t = max(n, m);
	for (int i = 1; i <= t; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[t] = power(fact[t], P - 2);
	for (int i = t - 1; i; i--) infact[i] = (LL)infact[i + 1] * (i + 1) % P; 
	for (int i = 1; i <= K; i++) {
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		visX[r1] = visX[r2] = true, visY[c1] = visY[c2] = true;
	}
	f[0][0] = g[0][0] = 1;
	work(f, n, visX); work(g, m, visY);
	int sumX = 0, sumY = 0;
	for (int i = 1; i <= n; i++) sumX += !visX[i];
	for (int i = 1; i <= m; i++) sumY += !visY[i];
	for (int i = 0; i * 2 <= sumX; i++) {
		for (int j = 0; j * 2 <= sumY; j++) {
			ans = (ans + (LL)f[n][i] * g[m][j] % P * A(sumY - 2 * j, i) % P * A(sumX - 2 * i, j)) % P;
		}
	}
	printf("%d\n", ans);
	return 0;
}