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

const int maxn = 2005;
char s[maxn], p[maxn];
int _dp[maxn * maxn * 2];
int ans[maxn];

int ls, lp;

int& dp(int poss, int posp, int alrp)
{
	return _dp[poss * 2 * maxn + alrp * lp + posp];
}

void updDp(int a, int b, int c, int d)
{
	int &x = dp(a, b, c);
	if (x == -1 || x > d)
	{
		x = d;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%s", s);
	scanf("%s", p);
	ls = strlen(s);
	lp = strlen(p);

	memset(_dp, -1, sizeof _dp);
	dp(0, 0, 0) = 0;

	int maxIn = ls / lp + 1;

	for (int i = 0; i < ls; i++)
		for (int j = 0; j < lp; j++)
			for (int alr = 0; alr < maxIn; alr++)
			{
				int cur = dp(i, j, alr);
				if (cur == -1)
					continue;
				if (s[i] == p[j] )
				{
					int ni = i + 1;
					int nj = j + 1;
					int nalr = alr;
					if (nj == lp)
					{
						nj = 0;
						nalr++;
					}
					updDp(ni, nj, nalr, cur);
				}
				if (j == 0)
				{
					int ni = i + 1;
					int nj = 0;
					int nalr = alr;
					updDp(ni, nj, nalr, cur);
				}
				int ni = i + 1;
				int nj = j;
				int nalr = alr;
				updDp(ni, nj, nalr, cur + 1);

			}
	for (int cnt = 0; cnt < maxIn; cnt++)
	{
		int minDel = dp(ls, 0, cnt);
		if (minDel == -1)
			continue;
		int maxDel = ls - cnt * lp;
		for (int i = minDel; i <= maxDel; i++)
			ans[i] = max(ans[i], cnt);
	}
	for (int i = 0; i <= ls; i++)
	{
		printf("%d ", ans[i] );
	}


	return 0;
}