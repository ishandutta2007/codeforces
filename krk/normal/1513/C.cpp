#include <bits/stdc++.h>
using namespace std;

const int Maxd = 10;
const int Maxn = 200005;
const int mod = 1000000007;

int dp[Maxn][Maxd];
int T;
char str[Maxn];
int m;

int main()
{
	fill(dp[0], dp[0] + Maxd, 1);
	for (int i = 1; i < Maxn; i++) {
		for (int j = 0; j + 1 < Maxd; j++)
			dp[i][j] = dp[i - 1][j + 1];
		dp[i][Maxd - 1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%s %d", str, &m);
		int n = strlen(str);
		int res = 0;
		for (int i = 0; i < n; i++)
			res = (res + dp[m][str[i] - '0']) % mod;
		printf("%d\n", res);
	}
    return 0;
}