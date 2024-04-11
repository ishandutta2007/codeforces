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

const int maxn = 105;
char str[maxn];
long long dp[maxn][3][3];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++)
		str[i] -= 'A';

	dp[2][0][0] = dp[2][1][1] = 1;
	dp[2][1][0] = 1;
	dp[2][2][2] = 1;

	for (int i = 2; i < n; i++)
	{
		for (int l = 0; l < 3; l++)
			for (int r = 0; r < 3; r++)
			{
				long long cur = dp[i][l][r];
				if (cur == 0)
					continue;
//				eprintf("i = %d, l = %d, r = %d, cur = %lld\n", i, l, r, cur);
				for (int nr = 0; nr < 2; nr++)
				{
					int rr = r;
					if (r == 0 && nr == 1)
					{
						rr = 1;
						nr = 2;
					}
					if (rr % 2 != str[i - 1] )
						continue;
					dp[i + 1][l][nr] += cur;
				}
			}
//		eprintf("\n");
	}
	long long ans = 0;
	for (int l = 0; l < 3; l++)
		for (int r = 0; r < 3; r++)
		{
			long long cur = dp[n][l][r];
			if (cur == 0)
				continue;

//			eprintf("l = %d, r = %d, cur = %lld\n", l, r, cur);
			int ll = l;
			if (ll == 2)
				ll = 3;
			int rr = r;
			if (rr == 0 && ll == 1)
			{
				rr = 1;
				ll = 0;
			}
			if (rr % 2 == str[n - 1] && ll % 2 == str[0] )
				ans += cur; 
		}
	printf("%lld\n", ans);

	

	return 0;
}