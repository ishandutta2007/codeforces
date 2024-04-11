#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
typedef double db;
const int N = 18;
int n;
db dp[N][1 << N];
db p[N][N];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%lf", &p[i][j]);
		}
	}
	dp[0][(1 << n) - 1] = 1;
	for(int i = (1 << n) - 2; i >= 0; i--) {
		for(int j = 0; j < n; j++) {
			if(!(i >> j & 1)) continue;
			for(int k = 0; k < n; k++) {
				if(i >> k & 1) continue;
				dp[j][i] = max(dp[j][i], dp[k][i ^ (1 << k)] * p[k][j] + dp[j][i ^ (1 << k)] * p[j][k]);
			}
		}
	}
	db res = 0;
	for(int i = 0; i < n; i++) res = max(res, dp[i][1 << i]);
	printf("%.10lf\n", res);
	return 0;
}