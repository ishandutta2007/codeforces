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



const int maxn = (int) 3e5 + 100;
const int maxk = 5005;
int dp[maxk][maxk];
int a[maxn];
int d[maxn];


void upd(int &_a, int b)
{
	_a = max(_a, b);
}

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);
	
	int sumAll = 0;
	for (int i = 1; i < n; i++)
	{
		d[i] = a[i] - a[i - 1];
		sumAll += d[i];
	}

	int lenSmall = n / k;
	int cntSmall = k - n % k;
	int lenBig = lenSmall + 1;
	int cntBig = k - cntSmall;


	for (int i = 0; i < maxk; i++)
		for (int j = 0; j < maxk; j++)
			dp[i][j] = -1;
	dp[0][0] = 0;

	for (int small = 0; small <= cntSmall; small++)
		for (int big = 0; big <= cntBig; big++)
		{
			if (small + big == n)
				continue;
			int cur = dp[small][big];
			if (cur == -1)
				continue;
			if (small < cntSmall)
				upd(dp[small + 1][big], cur + d[ (small + 1) * lenSmall + big * lenBig] );
			if (big < cntBig)
				upd(dp[small][big + 1], cur + d[small * lenSmall + (big + 1) * lenBig] );
		}

	printf("%d\n", sumAll - dp[cntSmall][cntBig] );
}



int main(int, char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}