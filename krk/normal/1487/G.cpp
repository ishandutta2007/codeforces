#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxn = 405;
const int mod = 998244353;

int n;
int a[Maxl];
int dp[2][3][3][2][Maxn][Maxn];
int cur;
int got1[Maxn];
int got2[Maxn][Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < Maxl; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i == 2 && j == 2) {
				dp[cur][2][2][0][0][0] += 24 * 23;
				dp[cur][2][2][1][0][0] += 24;
			} else {
				int ways = 1;
				if (i == 2) ways *= 24;
				if (j == 2) ways *= 24;
				dp[cur][i][j][i == j][(i == 0) + (j == 0)][(i == 1) + (j == 1)] += ways;
			}
	for (int i = 2; i < n; i++) {
		for (int a = 0; a < 3; a++)
			for (int b = 0; b < 3; b++)
				for (int sam = 0; sam < 2; sam++)
					for (int cnta = 0; cnta + 1 < Maxn; cnta++)
						for (int cntb = 0; cntb + 1 < Maxn; cntb++) {
							int ways = dp[cur][a][b][sam][cnta][cntb]; dp[cur][a][b][sam][cnta][cntb] = 0;
							if (ways == 0) continue;
							for (int c = 0; c < 3; c++)
								if (c < 2) {
									if (a != c) {
										int nsam = b == c;
										int ncnta = cnta + (c == 0);
										int ncntb = cntb + (c == 1);
										dp[!cur][b][c][nsam][ncnta][ncntb] = (dp[!cur][b][c][nsam][ncnta][ncntb] + ways) % mod;
									}
								} else if (a < 2 && b < 2)
									dp[!cur][b][c][0][cnta][cntb] = (dp[!cur][b][c][0][cnta][cntb] + ll(ways) * 24) % mod;
								else if (a < 2) {
									dp[!cur][b][c][0][cnta][cntb] = (dp[!cur][b][c][0][cnta][cntb] + ll(ways) * 23) % mod;
									dp[!cur][b][c][1][cnta][cntb] = (dp[!cur][b][c][1][cnta][cntb] + ways) % mod;
								} else if (b < 2)
									dp[!cur][b][c][0][cnta][cntb] = (dp[!cur][b][c][0][cnta][cntb] + ll(ways) * 23) % mod;
								else if (sam)
									dp[!cur][b][c][0][cnta][cntb] = (dp[!cur][b][c][0][cnta][cntb] + ll(ways) * 23) % mod;
								else {
									dp[!cur][b][c][0][cnta][cntb] = (dp[!cur][b][c][0][cnta][cntb] + ll(ways) * 22) % mod;
									dp[!cur][b][c][1][cnta][cntb] = (dp[!cur][b][c][1][cnta][cntb] + ways) % mod;
								}
						}
		cur = !cur;
	}
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
			for (int sam = 0; sam < 2; sam++)
				for (int cnta = 0; cnta < Maxn; cnta++)
					for (int cntb = 0; cntb < Maxn; cntb++) {
						int ways = dp[cur][a][b][sam][cnta][cntb];
						res = (res + ways) % mod;
						got1[cnta] = (got1[cnta] + ways) % mod;
						got2[cnta][cntb] = (got2[cnta][cntb] + ways) % mod;
					}
	for (int i = Maxn - 1; i >= 0; i--) {
		if (i + 1 < Maxn) got1[i] = (got1[i] + got1[i + 1]) % mod;
		for (int j = Maxn - 1; j >= 0; j--) {
			if (i + 1 < Maxn) got2[i][j] = (got2[i][j] + got2[i + 1][j]) % mod;
			if (j + 1 < Maxn) got2[i][j] = (got2[i][j] + got2[i][j + 1]) % mod;
			if (i + 1 < Maxn && j + 1 < Maxn)
				got2[i][j] = (got2[i][j] - got2[i + 1][j + 1] + mod) % mod;
		}
	}
	for (int i = 0; i < Maxl; i++) {
		res = (res - got1[a[i] + 1] + mod) % mod;
		for (int j = i + 1; j < Maxl; j++)
			res = (res + got2[a[i] + 1][a[j] + 1]) % mod;
	}
	printf("%d\n", res);
    return 0;
}