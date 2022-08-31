#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = 105;
const int M = 1005;
const int SUM = N * M;

int x[N];
double dp[2][SUM];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i] );
		x[i]--;
	}
	int t = 0, nt = 1;
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		memset(dp[nt], 0, sizeof dp[nt]);
		for (int j = 0; j < (i + 1) * m; j++)
		{
			dp[nt][j] += dp[t][j];
			dp[nt][j + m] -= dp[t][j];
			dp[nt][j + x[i] ] -= dp[t][j];
			dp[nt][j + x[i] + 1] += dp[t][j];
		}
		for (int j = 0; j < (i + 1) * m; j++)
			dp[nt][j + 1] += dp[nt][j];
		double sum = 0;
		for (int j = 0; j < (i + 1) * m; j++)
			sum += dp[nt][j];
		for (int j = 0; j < (i + 1) * m; j++)
			dp[nt][j] /= sum;
		
//		for (int j = 0; j < (i + 1) * m; j++)
//			eprintf("%.5lf ", dp[nt][j] );
//		eprintf("\n");

		swap(t, nt);
	}
	int sx = 0;
	for (int i = 0; i < n; i++)
		sx += x[i];

	double ans = 0;
	for (int i = 0; i < sx; i++)
		ans += dp[t][i];

	printf("%.15lf\n", ans * (m - 1) + 1);


	return 0;
}