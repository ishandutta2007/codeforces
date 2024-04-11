#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	double x = 0, y = 0;
	double a = 1, b = 0;
	double len = 100;
	int n;
	scanf("%d", &n);
	if (n <= 4) return puts("No solution"), 0;
	double rad = 2 * M_PI / n;
	REP(i, 0, n)
	{
		x += a * len, y += b * len;
		if (i == n - 1) x -= y * a / b, y = 0;
		double aa, bb;
		len += 0.002;
		aa = a * cos(rad) - b * sin(rad), bb = a * sin(rad) + b * cos(rad);
		a = aa, b = bb;
		printf("%lf %lf\n", x, y);
	}
	return 0;
}