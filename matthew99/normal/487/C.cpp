#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int maxn = 1e5;

int a[maxn + 5];

int fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("YES\n");
		printf("1\n");
		return 0;
	}
	if (n == 2)
	{
		printf("YES\n");
		printf("1\n");
		printf("2\n");
		return 0;
	}
	if (n == 4)
	{
		printf("YES\n");
		printf("1\n");
		printf("3\n");
		printf("2\n");
		printf("4\n");
		return 0;
	}
	int tot = 0;
	int mul = 1;
	a[tot++] = 1;
	REP(i, 1, n >> 1) 
	{
		a[tot] = (LL)fpm(mul, n - 2, n) * (i << 1 | 1) % n;
		mul = (LL)mul * a[tot++] % n;
	}
	FOR(i, 1, n >> 1) 
	{
		a[tot] = (LL)fpm(mul, n - 2, n) * (i << 1) % n;
		mul = (LL)mul * a[tot++] % n;
	}
	if (!mul)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	a[n - 1] = n;
	REP(i, 0, n) printf("%d\n", a[i]);
	return 0;
}