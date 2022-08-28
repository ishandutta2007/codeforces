#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

const int MAGIC = 1005;

const int maxn = 1e5 + 100;
const int maxr = MAGIC;
double dp[2][maxr];
double sum[maxr];


int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, k;
	scanf("%d%d", &n, &k);

	double ot = (double) (k - 1) / (double) k;
	double here = 1. / (double) k;
	for (int i = 1; i < maxr; i++)
		sum[i] = sum[i - 1] + (double) i;

	int t = 0;
	for (int i = 1; i <= n; i++)
	{
		int nt = (t ^ 1);
		memset(dp[nt], 0, sizeof dp[nt] );
		for (int level = 1; level < maxr - 1; level++)
		{
			double hl = 1. / (double) (level + 1);
			double otl = 1. - hl;
			dp[nt][level] = ot * dp[t][level] 
				+ here * hl * (level + dp[t][level + 1] )
				+ here * otl * (sum[level] / (double) level + dp[t][level] );
			//fprintf(stderr, "i = %d, level = %d, dp[i][level] = %.10lf\n", i, level, dp[i][level] );
		}
		t = nt;
	}
	printf("%.15lf\n", dp[t][1] * (double) k);


	return 0;
};