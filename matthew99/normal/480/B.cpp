#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 100000;

int n, l, x, y;
int a[maxn + 5];

bool f0 = 1, f1 = 1;

void init()
{
	scanf("%d%d%d%d", &n, &l, &x, &y);
	REP(i, 0, n)
	{
		scanf("%d", a + i);
		if (*lower_bound(a, a + i, a[i] - x) == a[i] - x) f0 = 0;
		if (*lower_bound(a, a + i, a[i] - y) == a[i] - y) f1 = 0;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	if (f0 && f1)
	{
		REP(i, 0, n)
			if (*lower_bound(a, a + i, a[i] + x - y) == a[i] + x - y)
			{
				if (a[i] - y >= 0) printf("1\n%d\n", a[i] - y), exit(0);
				if (a[i] + x <= l) printf("1\n%d\n", a[i] + x), exit(0);
			}
		REP(i, 0, n)
			if (*lower_bound(a, a + i, a[i] - x - y) == a[i] - x - y) printf("1\n%d\n", a[i] - x), exit(0);
	}
	printf("%d\n", f0 + f1);
	if (f0) printf("%d ", x);
	if (f1) printf("%d", y);
	return 0;
}