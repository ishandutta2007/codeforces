/* Never Say Die. */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <stack>
using namespace std;
typedef long long LL;
typedef long double LD;

#define N 1005
int n, K;
char s[N];

int dp[N][N * 2];

stack <char> sta;

int main() {
	scanf("%d%d", &n, &K);
	scanf("%s", s + 1);
	memset(dp, -1, sizeof dp);
	dp[0][N] = 0;
	for (int i = 1; i <= n; i++) {
		int q = min(i, K);
		if (s[i] == 'L' || s[i] == '?') {
			for (int j = -q; j <= q; j++) {
				if (~dp[i - 1][j + N]) dp[i][j + N - 1] = 1;
			}
		}
		if (s[i] == 'D' || s[i] == '?') {
			for (int j = -q; j <= q; j++) {
				if (~dp[i - 1][j + N]) dp[i][j + N] = 0;
			}
		}
		if (s[i] == 'W' || s[i] == '?') {
			for (int j = -q; j <= q; j++) {
				if (~dp[i - 1][j + N]) dp[i][j + N + 1] = 2;
			}
		}
		if (i != n) dp[i][K + N] = dp[i][K + 1 + N] = dp[i][-K + N] = dp[i][-K - 1 + N] = -1;
	}
	for (int i = -K; i <= K; i += 2 * K) {
		if (~dp[n][i + N]) {
			for (int j = n, k = i; j; j--) {
				switch (dp[j][k + N]) {
					case 1 :
						sta.push('L');
						k++;
					break; case 0:
						sta.push('D');
					break; case 2:
						sta.push('W');
						k--;
				}
			}
			while (!sta.empty()) putchar(sta.top()), sta.pop();
			puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}