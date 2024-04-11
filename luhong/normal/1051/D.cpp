#include <cstdio>

int dp[1010][2010][2][2];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	dp[1][2][0][1] = 1;
	dp[1][2][1][0] = 1;
	dp[1][1][0][0] = 1;
	dp[1][1][1][1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int k = 1; k <= 2 * i; k++)
		{
			for(int a = 0; a <= 1; a++)
				for(int b = 0; b <= 1; b++)
					for(int c = 0; c <= 1; c++)
						for(int d = 0; d <= 1; d++)
						{
							int v = k;
							if(c == d)
							{
								if(a != c && b != d) v--;
							}
							else
							{
								if(a != c) v--;
								if(b != d) v--;
							}
							
							if(v >= 1) dp[i][k][c][d] = (dp[i - 1][v][a][b] + dp[i][k][c][d]) % 998244353; 
						}
		}
	}
	printf("%d\n", (dp[n][k][0][1] + (dp[n][k][1][1] + (dp[n][k][0][0] + dp[n][k][1][0]) % 998244353) % 998244353) % 998244353);
	return 0;
}