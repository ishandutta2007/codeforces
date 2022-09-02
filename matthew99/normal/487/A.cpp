#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int xa, xb, xc, ya, yb, yc, pa, pb, pc;
	scanf("%d%d%d%d%d%d%d%d%d", &xa, &xb, &xc, &ya, &yb, &yc, &pa, &pb, &pc);
	int Min = -1;
	FOR(i, 0, 200)
		FOR(j, 0, 100)
		{
			int atk = xb + i, def = xc + j;
			if (atk <= yc) continue;
			int yyt = atk - yc;
			yyt = (ya + yyt - 1) / yyt * max(0, yb - def);
			int tmp = 0;
			tmp = i * pb + j * pc + max(0, yyt + 1 - xa) * pa;
			if (Min == -1) Min = tmp;
			else Min = min(Min, tmp);
		}
	printf("%d\n", Min);
	return 0;
}