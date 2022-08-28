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


const int N = (int) 1e3 + 100;
const int T = (int) 1e4 + 100;
double dp[T][N];

void solve(int n)
{
	dp[0][0] = 1;
	for (int t = 0; t + 1 < T; t++)
	{
		for (int k = 0; k <= min(t + 1, n); k++)
		{
			dp[t + 1][k] += dp[t][k] * (double) k /  (double) n;
			if (k != n)
				dp[t + 1][k + 1] += dp[t][k] * (double) (n - k) / (double) n;
		}
	}
//	eprintf("%.10lf\n", dp[T - 1][n] );
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, t;
	scanf("%d%d", &n, &t);

	solve(n);
	for (int it = 0; it < t; it++)
	{
		int x;
		scanf("%d", &x);
		int ans = -1;
		for (int i = 0; i < T; i++)
		{
			if (dp[i][n] * 2000 >= x - 1e-7)
			{
				ans = i;
				break;
			}
		}
		if (ans == -1) throw;
		printf("%d\n", ans);	
	}


	return 0;
}