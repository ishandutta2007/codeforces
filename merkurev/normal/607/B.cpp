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


const int N = 505;
int s[N];

int dp[N][N];

const int INF = (int) 1e9;

void upd(int &a, int b)
{
	a = min(a, b);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &s[i] );

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = INF;
		}
	for (int i = 0; i < n; i++)
	{
		dp[0][i] = 0;
		dp[1][i] = 0;
	}

	for (int len = 2; len <= n; len++)
	{
		for (int a = 0; a + len <= n; a++)
		{
			int b = a + len - 1;
			for (int c = a; c < b; c++)
			{
				if (s[a] != s[c] )
					continue;
				upd(dp[len][a], dp[c - a + 1][a] + 1 + dp[b - c][c + 1] );
			}
			if (s[a] == s[b] )
			{
				upd(dp[len][a], dp[len - 2][a + 1] );
			}
		
		}
	}

	printf("%d\n", dp[n][0] + 1);

	return 0;
}