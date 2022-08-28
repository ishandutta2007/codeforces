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


const int X = (int) 2e3;
int cnt[2][X];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t = 0, nt = 1;
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		cnt[t][a]++;
	}

	for (int it = 0; it < k; it++)
	{
		memset(cnt[nt], 0, sizeof cnt[nt] );
		int sh = 0;
		for (int i = 0; i < X; i++)
		{
			cnt[nt][i] += (cnt[t][i] + sh) / 2;
			cnt[nt][i ^ x] += (cnt[t][i] + 1 - sh) / 2;
			sh = (sh + cnt[t][i] ) % 2;
		}
		swap(t, nt);
	}

	int mn = X, mx = 0;
	for (int i = 0; i < X; i++)
		if (cnt[t][i] )
		{
			mn = min(mn, i);
			mx = max(mx, i);
		}

	printf("%d %d\n", mx, mn);
	return 0;
}