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
	if (a >= MOD)
		a -= MOD;
}

const int K = 20;
const int MASK = (1 << K);
const int N = 80;

char s[N];
int dp[N][MASK];
int nx[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s", s);
	nx[n] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		nx[i] = nx[i + 1];
		if (s[i] == '1')
			nx[i] = i;
	}
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;

	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
//		eprintf("\n");
		for (int mask = 0; mask < MASK; mask++)
		{
			int cur = dp[i][mask];
			if (cur == 0) continue;
			if (mask != 0 && (mask & (mask + 1) ) == 0) sadd(ans, cur);
//			eprintf("i = %d, mask = %d, cur = %d\n", i, mask, cur);
			int x = 0;
			int ni = nx[i];
			for (int j = 0; j < 5 && ni + j < n; j++)
			{
				x = (x << 1) + (s[ni + j] - '0');
//				eprintf("j = %d, x = %d\n", j, x);
				if (x > K) break;
				sadd(dp[ni + j + 1][mask | (1 << (x - 1) )], cur);
			}
		}
	}
	printf("%d\n", ans);


	return 0;
}