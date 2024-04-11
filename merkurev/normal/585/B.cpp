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

const int maxn = 155;
char s[3][maxn];
bool dp[3][maxn];


bool empty(int i, int j)
{
	return (!isalpha(s[j][i] ) && !isalpha(s[j][i + 1] ) && !isalpha(s[j][i + 2] ) && !isalpha(s[j][i + 3] ) );
}

void solve()
{
	memset(s, 0, sizeof s);
	memset(dp, false, sizeof dp);
	int n;
	scanf("%d%*d", &n);
	for (int i = 0; i < 3; i++)
		scanf("%s", s[i] );
	for (int j = 0; j < 3; j++)
		if (s[j][0] == 's' && !isalpha(s[j][1] ) )
			dp[j][1] = true;
	bool ans = false;
	for (int i = 1; i <= n + 3; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (!dp[j][i] )
				continue;
//			eprintf("i = %d, j = %d\n", i, j);
			if (i >= n)
				ans = true;
			if (empty(i, j) )
				dp[j][i + 3] = true;
			if (j > 0 && empty(i, j - 1) )
				dp[j - 1][i + 3] = true;
			if (j < 2 && empty(i, j + 1) )
				dp[j + 1][i + 3] = true;
		}
	}
	printf(ans ? "YES\n" : "NO\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();



	return 0;
}