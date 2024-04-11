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

const int MOD = (int) 1e9 + 7;

void sadd(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
	sadd(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}


const int N = 5005;
char str[N];
int a[N];

const int ALP = 26;
int nxt[N][ALP];
int dp[N][N];

void init()
{
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < N; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j] );
	}
}


int cnt[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < n; i++)
		a[i] = str[i] - 'a';
		
	for (int j = 0; j < ALP; j++)
		nxt[n][j] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < ALP; j++)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i] ] = i;
	}

	for (int j = 0; j < ALP; j++)
		sadd(dp[nxt[0][j] ][1], 1);
	for (int i = 0; i < n; i++)
	{
		for (int len = 1; len <= i + 1; len++)
		{
//			eprintf("i = %d, len = %d, dp = %d\n", i, len, dp[i][len] );
			sadd(cnt[len], dp[i][len] );
		}

		for (int j = 0; j < ALP; j++)
		{
			if (j == a[i] ) continue;
			int ni = nxt[i + 1][j];
			if (ni == n) continue;
			for (int len = 1; len <= i + 1; len++)
				sadd(dp[ni][len + 1], dp[i][len] );
		}
	}
	
	init();

	int ans = 0;
	for (int len = 1; len <= n; len++)
		sadd(ans, mul(cnt[len], dp[n - 1][len - 1] ) );

	printf("%d\n", ans);

	return 0;
}