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


int mod = (int) 1e9 + 7;

void add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}

const int N = 5005;
char str[N];

int dp[N][N];
int gr[N][N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s", str);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			gr[i][j] = N;

	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
		{
			if (str[i] > str[j] )
			{
				gr[i][j] = 1;
				continue;
			}
			if (str[i] < str[j] )
			{
				gr[i][j] = N;
				continue;
			}
			gr[i][j] = 1 + gr[i + 1][j + 1];
		}

//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			eprintf("i = %d, j = %d, gr = %d\n", i, j, gr[i][j] );
	add(dp[0][1], 1);

	for (int l = 0; l < n; l++)
		for (int r = l + 1; r < n; r++)
		{
//			eprintf("l = %d, r = %d, dp = %d\n", l, r, dp[l][r] );
			int len = r - l;
			int nr = r + len;
			add(dp[l][r + 1], dp[l][r] );
			if (nr > n)
				continue;
			
			if (str[r] == '0')
				continue;
			if (gr[r][l] > len)
				nr++;
			add(dp[r][nr], dp[l][r] );
		}
	int ans = 0;
	for (int l = 0; l < n; l++)
		add(ans, dp[l][n] );
	printf("%d\n", ans);

	return 0;
}