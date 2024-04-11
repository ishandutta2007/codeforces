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

const int N = 205;
const int K = 1005;

void add(int &a, int b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}
int sum(int a, int b)
{
	add(a, b);
	return a;
}
int mul(int a, int b)
{
	return (a * 1LL * b) % MOD;
}

int a[N];
int dp[2][N][K];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);
	a[n] = a[n - 1];

	int t = 0, nt = 1;
	dp[t][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		memset(dp[nt], 0, sizeof dp[nt] );
		int d = a[i + 1] - a[i];
		
		for (int cntOpen = 0; cntOpen <= i && cntOpen <= n - i; cntOpen++)
			for (int sum = 0; sum <= k; sum++)
			{
				int cur = dp[t][cntOpen][sum];
				if (sum + cntOpen * d <= k)
					add(dp[nt][cntOpen][sum + cntOpen * d], mul(cur, cntOpen + 1) );
				if (cntOpen > 0 && sum + (cntOpen - 1) * d <= k)
					add(dp[nt][cntOpen - 1][sum + (cntOpen - 1) * d], mul(cur, cntOpen) );
				if (sum + (cntOpen + 1) * d <= k)	
					add(dp[nt][cntOpen + 1][sum + (cntOpen + 1) * d], cur);
			}
		swap(t, nt);
	}
	int ans = 0;
	for (int sum = 0; sum <= k; sum++)
		add(ans, dp[t][0][sum] );
	printf("%d\n", ans);

	return 0;
}