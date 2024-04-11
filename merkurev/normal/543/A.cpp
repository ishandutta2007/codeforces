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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int mod;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

const int maxn = 505;
int a[maxn];
int dp[2][maxn][maxn];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int n, m, b;
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	
	int t = 0, nt = 1;
	dp[t][0][0] = (1 % mod);
	for (int it = 0; it < m; it++)
	{
		memset(dp[nt], 0, sizeof dp[nt] );

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= b; j++)
			{
				int cur = dp[t][i][j];
				if (cur == 0)
					continue;
			//	eprintf("it = %d, i = %d, j = %d\n", it, i, j);
				if (j + a[i] <= b)
					add(dp[nt][i][j + a[i] ], cur);
				if (i + 1 < n)
					add(dp[t][i + 1][j], cur);
			}

		swap(t, nt);
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= b; j++)
			add(sum, dp[t][i][j] );

	printf("%d\n", sum);

	return 0;
}