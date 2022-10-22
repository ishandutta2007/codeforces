#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 7;

int w[Maxn];
int dp[Maxn + 1][1 << Maxn];

int Set(int mask, int b, int val)
{
	if (bool(mask & 1 << b) != val)
		mask ^= 1 << b;
	return mask;
}

int main()
{
	for (int i = 0; i < Maxn; i++)
		scanf("%d", &w[i]);
	dp[0][0] = 1;
	for (int r = 1; r <= Maxn; r++) {
		for (int j = 0; j < 1 << (r - 1); j++) {		
			dp[0][j | 1 << (r - 1)] = dp[0][j];
			dp[0][j] = 0;
		}
		for (int t = 0; t < w[r - 1]; t++) {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < 1 << r; j++) {
					int ways = dp[i][j]; dp[i][j] = 0;
					bool block = bool(j & 1 << i);
					// 0 0
					int ni = i + 1;
					int nj = Set(Set(j, i, 0), i + 1, 0);
					if (i < r - 1)
						dp[ni][nj] = (dp[ni][nj] + ways) % mod;
					// 0 1
					nj = Set(j, i, 0);
					dp[ni][nj] = (dp[ni][nj] + ways) % mod;
					// 1 0
					nj = Set(Set(j, i, 1), i + 1, 0);
					if (i < r - 1)
						dp[ni][nj] = (dp[ni][nj] + ways) % mod;
					// 1 1
					nj = Set(j, i, 1);
					if (!block)
						dp[ni][nj] = (dp[ni][nj] + ways) % mod;
				}
			for (int j = 0; j < 1 << r; j++) {
				dp[0][j] = dp[r][j];
				dp[r][j] = 0;
			}
		}
	}
	printf("%d\n", dp[0][(1 << Maxn) - 1]);
    return 0;
}