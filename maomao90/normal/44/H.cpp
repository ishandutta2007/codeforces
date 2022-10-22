#include <bits/stdc++.h>
using namespace std;

int n;
char num[55];
long long dp[55][20];
long long ans;

// long long memo[55][20][2];
// long long dp(int index, int cur, bool same) {
// 	if (index == n - 1) {
// 		if (same) return 0;
// 		else return 1;
// 	}
// 	if (memo[index][cur][same] != -1) return memo[index][cur][same];
// 	memo[index][cur][same] = 0;
// 	int digit = (int) num[index + 1] - '0';
// 	int nxt = (cur + digit) / 2;
// 	memo[index][cur][same] += dp(index + 1, nxt, nxt == digit && same);
// 	if ((cur + digit) % 2 == 1) 
// 		memo[index][cur][same] += dp(index + 1, nxt + 1, (nxt + 1) == digit && same);
// 	return memo[index][cur][same];
// }

int main() {
	scanf(" %s", num);
	n = strlen(num);
	for (int i = 0; i < 10; i++) dp[0][i] = 1;
	for (int i = 1; i < n; i++) {
		int curnum = (int) num[i] - '0';
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if ((j + curnum) / 2 == k || (j + curnum + 1) / 2 == k) {
					dp[i][k] += dp[i - 1][j];
				}
			}
		}
	}
	for (int i = 0; i < 10; i++) ans += dp[n - 1][i];
	bool extra = 1;
	for (int i = 1; i < n; i++) {
		int curnum = (int) num[i] - '0', prvnum = (int) num[i - 1] - '0';
		if (!((prvnum + curnum) / 2 == curnum || (prvnum + curnum + 1) / 2 == curnum)) extra = 0;
	}
	ans -= extra;
// 	memset(memo, -1, sizeof memo);
// 	for (int i = 0; i < 10; i++) ans += dp(0, i, i == (int) num[0] - '0');
	printf("%lld\n", ans);
	return 0;
}