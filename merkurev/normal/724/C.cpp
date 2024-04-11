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


const int N = (int) 2e5 + 100;
vector <pair <int, int> > da[N], db[N];

const long long INF = (long long) 1e18;
long long ans[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < N; i++)
		ans[i] = INF;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		da[x + y].emplace_back(i, x);
		db[x - y + m].emplace_back(i, x);
	}

	int x = 0, y = 0;
	int dx = 1, dy = 1;
	long long d = 0;

	while (true)
	{
		eprintf("x = %d, y = %d, dx = %d, dy = %d, d = %lld\n", x, y, dx, dy, d);
		if (dx == dy)
		{
			for (auto p : db[x - y + m] )
				ans[p.first] = min(ans[p.first], d + abs(p.second - x) );
		}
		else
		{
			for (auto p : da[x + y] )
				ans[p.first] = min(ans[p.first], d + abs(p.second - x) );
		}
		int cur = n + m;
		if (dx == -1)
			cur = min(cur, x);
		else
			cur = min(cur, n - x);
		if (dy == -1)
			cur = min(cur, y);
		else
			cur = min(cur, m - y);

		x += dx * cur;
		y += dy * cur;
		d += cur;
		bool xb = (x == 0 || x == n);
		bool yb = (y == 0 || y == m);
		if (xb && yb) break;
		if (xb)
			dx = -dx;
		if (yb)
			dy = -dy;
	}
	for (int i = 0; i < k; i++)
	{
		if (ans[i] == INF)
			ans[i] = -1;
		printf("%lld\n", ans[i] );
	}

	return 0;
}