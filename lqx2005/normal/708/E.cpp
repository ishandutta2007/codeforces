#include <bits/stdc++.h>

using namespace std;
const int N = 1.5e3 + 10, P = 1e9 + 7;
int n, m, a, b, k, p;
int prop[N];
int dp[N][N];

int power(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P) {
		if(b & 1) {
			c = 1ll * c * a % P;
		}
	}
	return c;
}

int main() {
	cin >> n >> m >> a >> b >> k;
	p = 1ll * a * power(b, P - 2) % P;
	prop[0] = 1;
	for(int i = 1; i <= m; i++) {
		prop[i] = 1ll * prop[i - 1] * (k + 1 - i) % P * power(i, P - 2) % P;
	}
	for(int i = 0; i <= m; i++) {
		if(i > k) continue;
		prop[i] = 1ll * prop[i] * power(p, i) % P * power((1 - p + P) % P, k - i) % P;
	}
	dp[0][m] = 1;
	for(int i = 0; i < n; i++) {
		int f = dp[i][m], s1 = 0, s2 = 0;
		for(int j = 1; j <= m; j++) {
			s1 = (s1 + 1ll * dp[i][j - 1] * prop[j - 1] % P) % P;
			s2 = (s2 + prop[j - 1]) % P;
			dp[i + 1][j] = (dp[i + 1][j - 1] - 1ll * s1 * prop[m - j] % P + P) % P;
			dp[i + 1][j] = (dp[i + 1][j] + 1ll * s2 * prop[m - j] % P * (f - dp[i][m - j] + P) % P) % P;
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}