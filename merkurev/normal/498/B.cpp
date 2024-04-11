#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


const int maxn = 5005;
double dp[2][maxn];
double add[maxn];

double eps = 1e-14;
double pppow[105][maxn];


int main()
{
	int n, T;
	scanf("%d%d", &n, &T);
	int t = 0, nt = 1;

	dp[0][0] = 1;

	for (int i = 0; i <= 100; i++)
	{
		double x = (100 - i) / 100.;
		pppow[i][0] = 1;
		for (int j = 1; j < maxn; j++)
			pppow[i][j] = pppow[i][j - 1] * x;
	}

	double answer = 0;
	for (int i = 0; i < n; i++)
	{
		memset(dp[nt], 0, sizeof dp[nt] );
		memset(add, 0, sizeof add);

		int p;
		int ct;
		scanf("%d%d", &p, &ct);
		double pd = p / 100.;

		for (int j = 0; j <= T; j++)
		{
			double cur = dp[t][j];
			if (cur < eps)
				continue;
			add[j + 1] += cur * pd;
			int et = min(T + 1, j + ct);
			double X = cur * pppow[p][et - j];
			dp[nt][et] += X; 
			add[et + 1] -= X * pd;
		}
		for (int j = 1; j <= T + 1; j++)
		{
			add[j] += add[j - 1] * (1. - pd);
			if (add[j] < eps)
				add[j] = 0;
			dp[nt][j] += add[j];
			if (dp[nt][j] < eps)
				dp[nt][j] = 0;
		}
		answer += dp[nt][T + 1] * i;

		swap(t, nt);
	}
	for (int i = 0; i <= T; i++)
		answer += dp[t][i] * n;
	printf("%.10lf\n", answer);

	return 0;
}