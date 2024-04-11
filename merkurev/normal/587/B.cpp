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

const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e6 + 100;


int a[maxn];
int vals[maxn];
int cnt[maxn];

void add(int &_a, int b)
{
	_a += b;
	if (_a >= mod)
		_a -= mod;
	if (_a < 0)
		_a += mod;
}
int mul(int _a, int b)
{
	return (_a * 1LL * b) % mod;
}

int dp[2][maxn];
int answer;

void calcDp(long long bls, int k, int n, bool flag)
{
	int t = 0, nt = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int it = 0; it <= n; it++)
			dp[nt][it] = 0;

		for (int val = 0; val < n; val++)
		{
			int curdp = dp[t][val];
			if (curdp == 0)
				continue;
//			eprintf("i = %d, val = %d, dp = %d\n", i, val, curdp);
			long long x = max(0LL, bls - i + 1);
			if (!flag)
				x = min(x, 1LL);
			x %= mod;
//			eprintf("bls = %d, i = %d, x = %d\n", bls, i, x);
			add(answer, mul(curdp, x) );
			add(dp[nt][val], curdp);
		}
		for (int val = 0; val < n; val++)
		{
			dp[t][val] = mul(dp[nt][val], cnt[val] );
			add(dp[nt][val + 1], dp[nt][val] );
		}
	}
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long l;
	long long n, k;
	scanf("%lld%lld%lld", &n, &l, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		vals[i] = a[i];
	}
	sort(vals, vals + n);
	int m = unique(vals, vals + n) - vals;
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(vals, vals + m, a[i] ) - vals;
		a[i] = m - 1 - a[i];
		cnt[a[i] ]++;
	}

	if (l % n != 0)
	{
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < l % n; i++)
			dp[0][a[i] ]++;
		calcDp(l / n + 1, k, n, false);
	}
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++)
		dp[0][a[i] ]++;
	calcDp(l / n, k, n, true);

	printf("%d\n", answer);


	return 0;
}