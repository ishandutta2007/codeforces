#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

#define i64 long long int
// #define i128 __int128_t

int n;
int dp[5005][5005][3];
int h[5005];
void upd(int&x, int y) {
	if (x == -1 || x > y)x = y;
}
int calc(int A, int B) {
	if (A < B)return 0;
	return A - B + 1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &h[i]);
	h[0] = 0;
	memset(dp, -1, sizeof(dp));
	dp[0][0][2] = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j <= (i + 1) / 2; j++)for (int t = 0; t < 3; t++) {
		int T = dp[i][j][t];
		if (T == -1)continue;
		if (t == 2) {
			upd(dp[i + 1][j + 1][0], T + calc(h[i], h[i+1]));
			upd(dp[i + 1][j][2], T);
		}else
			if (t == 1) {
				upd(dp[i + 1][j + 1][0], T + calc(h[i], min(h[i - 1], h[i + 1])));
				upd(dp[i + 1][j][2], T + calc(h[i], h[i - 1]));
			}else
				if (t == 0) {
					upd(dp[i + 1][j][1], T);
				}
	}
	for (int i = 1; i <= (n + 1) / 2; i++) {
		int res = -1;
		for (int j = 0; j < 3; j++)if (dp[n][i][j] != -1) {
			upd(res, dp[n][i][j] + (j == 1 ? calc(h[n], h[n - 1]) : 0));
		}
		printf("%d%c", res, i < (n + 1) / 2 ? ' ' : '\n');
	}
	return 0;
}