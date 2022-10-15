#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 4443

int n, m;
int L[N], S[N], C[N], top[N];
LL dp[N][N], INF;
int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) read(L[i]);
	for (int i = 1 ; i <= n; i++) read(S[i]);
	for (int i = 1; i <= n + m; i++) read(C[i]);
	memset(dp, 200, sizeof dp);
	INF = -dp[0][0];
//	cerr << INF << endl;
	for (int i = 1; i <= n + m; i++) dp[i][0] = 0; 

	for (int i = n; i >= 1; i--) {
		for (int k = top[L[i]]; k >= 0; k--) { 
			dp[L[i]][k + 1] = max(dp[L[i]][k + 1], dp[L[i]][k] - S[i] + C[L[i]]);
		}
		top[L[i]]++;
		for (int j = 0; j <= n + m + 1; j++) {
			for (int k = top[j]; k >= 0; k--) {
				if (dp[j][k] != -INF) {
					dp[j + 1][k >> 1] = max(dp[j + 1][k >> 1], dp[j][k] + C[j + 1] * (k >> 1));
					top[j + 1] = max(top[j + 1], k >> 1);
				}
			}
		}
	}
	printf("%lld\n", dp[n + m][0]);
}