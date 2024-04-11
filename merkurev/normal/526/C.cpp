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

const int MAXV = (int) 1e3 + 15;

void solveBigWX(int c, int hx, int hy, int wx, int wy)
{
	long long ans = 0;
	for (int x = 0; x * 1LL * wx <= (long long) c; x++)
	{
		int y = (c - x * wx) / wy;
		ans = max(ans, x * 1LL * hx + y * 1LL * hy);
	}
	printf("%lld\n", ans);
}

void solveX(int c, int hx, int hy, int wx, int wy)
{
	long long ans = 0;
	int maxX = c / wx;
	for (int x = max(0, maxX - MAXV * MAXV); x <= maxX; x++)
	{
		int y = (c - x * wx) / wy;
		ans = max(ans, x * 1LL * hx + y * 1LL * hy);
	}
	printf("%lld\n", ans);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int c, hx, hy, wx, wy;
	scanf("%d%d%d%d%d", &c, &hx, &hy, &wx, &wy);
	

	if (wx > MAXV)
	{
		solveBigWX(c, hx, hy, wx, wy);
		return 0;
	}
	if (wy > MAXV)
	{
		solveBigWX(c, hy, hx, wy, wx);
		return 0;
	}
	
	if (hx * 1LL * wy > hy * 1LL * wx)
	{
		solveX(c, hx, hy, wx, wy);
		return 0;
	}
	solveX(c, hy, hx, wy, wx);
	return 0;
}