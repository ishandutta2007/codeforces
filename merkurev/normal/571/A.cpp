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

int a[3];

long long triangle(long long x)
{
	if (x < 0)
		return 0;
	return x * (x + 1) / 2;
}

long long cntWays(int minSum, int maxA, int maxB, int maxSum)
{
	if (minSum > maxA + maxB || minSum > maxSum)
		return 0;
	maxA = min(maxA, maxSum);
	maxB = min(maxB, maxSum);
	long long ans = (maxA + 1) * 1LL * (maxB + 1);
	ans -= triangle(minSum);
	ans -= triangle(maxA + maxB - maxSum);

	return ans;
}

long long solve(int _a, int b, int c, int _l)
{
	a[0] = _a;
	a[1] = b;
	a[2] = c;
	int l = _l;
	long long ans = 0;

	for (int mx = 0; mx < 3; mx++)
	{
		long long cur = 0;
		for (int add = 0; add <= l; add++)
		{
			int sz = a[mx] + add;
			if (sz < a[0] || sz < a[1] || sz < a[2] )
				continue;
			int need = sz + a[mx] - a[0] - a[1] - a[2] + 1;
			need = max(0, need);
			int mxA, mxB;
			if (mx == 0)
			{
				mxA = sz - a[1];
				mxB = sz - a[2];
			}
			if (mx == 1)
			{
				mxA = sz - a[0] - 1;
				mxB = sz - a[2];
			}
			if (mx == 2)
			{
				mxA = sz - a[0] - 1;
				mxB = sz - a[1] - 1;
			}
//			eprintf("add = %d, need = %d, mxA = %d, mxB = %d, max = %d\n", add, need, mxA, mxB, l - add);
			long long x = cntWays(need, mxA, mxB, l - add);
//			eprintf("x = %lld\n", x);
			cur += x;
		}
//		eprintf("%lld\n", cur);
		ans += cur;
	}
	printf("%lld\n", ans);
	return ans;
}

void solve()
{
	int _l;
	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i] );
	scanf("%d", &_l);
	solve(a[0], a[1], a[2], _l);
}

int slow(int a, int b, int c, int l)
{
	int ans = 0;
	for (int aa = 0; aa <= l; aa++)
		for (int bb = 0; bb <= l; bb++)
			for (int cc = 0; cc <= l; cc++)
			{
				if (aa + bb + cc > l)
					continue;
				int ax = a + aa;
				int bx = b + bb;
				int cx = c + cc;
				if (ax >= bx + cx || bx >= ax + cx || cx >= ax + bx)
					continue;
				ans++;
			}
	return ans;
}

void stress()
{
	for (int a = 1; a <= 10; a++)
		for (int b = 1; b <= 10; b++)
			for (int c = 1; c <= 10; c++)
				for (int l = 1; l <= 10; l++)
				{
					int x = solve(a, b, c, l);
					int y = slow(a, b, c, l);
					if (x != y)
						throw 42;
				}
}

int main(int, char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

//	stress();

	solve();

	return 0;
}