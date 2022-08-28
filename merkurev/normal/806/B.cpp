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



const int K = 5;
const int N = 120;

int a[N][K];
int cnt[K];
int cur[K];
bool suc[K];

int score(int n, int id)
{
	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		if (a[id][i] == -1) continue;
		int full = 3000;
		int rat = 32;
		while (rat >= 2 && cur[i] * rat > n)
		{
			full -= 500;
			rat /= 2;
		}
		int ccur = full * (250 - a[id][i] ) / 250;
//		eprintf("%d, %d: %d, %d : %d : %d\n", i, cur[i], rat, full, a[id][i], ccur);
		ans += ccur;
	}
//	eprintf("\n");
	return ans;
}

bool good(int n)
{
//	eprintf("-----\n");
	int v = score(n, 0);
	int p = score(n, 1);
//	eprintf("n = %d, v = %d, p = %d\n", n, v, p);
	return v > p;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &a[i][j] );
			if (a[i][j] != -1) cnt[j]++;
		}
	for (int i = 0; i < K; i++)
	{
		if (a[0][i] == -1) suc[i] = false;
		else if (a[1][i] == -1) suc[i] = false;
		else suc[i] = (a[0][i] > a[1][i] );
//		eprintf("%d - %d\n", i, suc[i] );
	}

	for (int add = 0; add < (int) 1e6; add++)
	{
		for (int i = 0; i < 5; i++)
			cur[i] = cnt[i] + add * suc[i];
		if (good(n + add) )
		{
			printf("%d\n", add);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}