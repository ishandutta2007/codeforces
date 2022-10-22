#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int Inf = 1000000000;

int dp[Maxn][Maxn][2][2];
int T;
int n;
char str[Maxn];

int main()
{
	fill((int*)dp, (int*)dp + Maxn * Maxn * 2 * 2, Inf);
	dp[0][0][0][0] = dp[0][0][0][1] = 0;
	for (int sam = 0; sam + 1 < Maxn; sam++)
		for (int dif = 0; dif + 1 < Maxn; dif++)
			for (int mid = 0; mid < 2; mid++)
				for (int r = 0; r < 2; r++) {
					if (sam > 0)
						dp[sam][dif][mid][r] = min(dp[sam][dif][mid][r], 1 - dp[sam - 1][dif + 1][mid][1]);
					if (dif > 0)
						dp[sam][dif][mid][r] = min(dp[sam][dif][mid][r], 1 - dp[sam][dif - 1][mid][1]);
					if (mid > 0)
						dp[sam][dif][mid][r] = min(dp[sam][dif][mid][r], 1 - dp[sam][dif][mid - 1][1]);
					if (dif > 0 && r == 1)
						dp[sam][dif][mid][r] = min(dp[sam][dif][mid][r], -dp[sam][dif][mid][0]);
				}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", str);
		int sam = 0, dif = 0, mid = 0;
		if (n % 2 && str[n / 2] == '0') mid++;
		for (int i = 0; i < n - 1 - i; i++)
			if (str[i] != str[n - 1 - i]) dif++;
			else if (str[i] == '0') sam++;
		int res = dp[sam][dif][mid][1];
		if (res > 0) printf("BOB\n");
		else if (res < 0) printf("ALICE\n");
		else printf("DRAW\n");
	}
    return 0;
}