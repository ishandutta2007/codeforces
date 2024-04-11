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
char f[N][N];

int toR[N][N];
int toD[N][N];

int toRsum[N][N];
int toDsum[N][N];

int getSum(int a[N][N], int r1, int c1, int r2, int c2)
{
	return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i < h; i++)
	{
		scanf("%s", f[i + 1] + 1);
	}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			if (j < w && f[i][j] == '.' && f[i][j + 1] == '.')
				toR[i][j] = 1;
			if (i < h && f[i][j] == '.' && f[i + 1][j] == '.')
				toD[i][j] = 1;
		}

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
		{
			toRsum[i][j] = toR[i][j] + toRsum[i - 1][j] + toRsum[i][j - 1] - toRsum[i - 1][j - 1];
			toDsum[i][j] = toD[i][j] + toDsum[i - 1][j] + toDsum[i][j - 1] - toDsum[i - 1][j - 1];
	//		eprintf("");
		}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int ans = getSum(toRsum, r1, c1, r2, c2 - 1) + getSum(toDsum, r1, c1, r2 - 1, c2);
		printf("%d\n", ans);
	}

	return 0;
}