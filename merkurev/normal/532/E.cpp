#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxn = (int) 1e5 + 100;
char a[maxn];
char b[maxn];

int dp[maxn][4];



int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	scanf("%s%s", a, b);

	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 4; j++)
			for (int skip = 0; skip < 3; skip++)
			{
				int cur = dp[i][j];
				if (cur == 0)
					continue;
				if (j & skip)
					continue;
				int nj = j | skip;
				int sa = j & 1;
				int sb = (j >> 1);
				if (a[i - sa] == b[i - sb] && skip != 0)
					continue;
				if (a[i - sa] != b[i - sb] && skip == 0)
					continue;
				dp[i + 1][nj] += cur;
			}
	printf("%d\n", dp[n + 1][3] );

	return 0;
}