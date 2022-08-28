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


long long gcd(long long a, long long b)
{
	return ( (b == 0) ? a : gcd(b, a % b) );
}

void fixRat(long long &x, long long &y)
{
	long long g = gcd(x, y);
	x /= g;
	y /= g;
}

long long dup(long long x, long long y)
{
	return (x + y - 1) / y;
}

void solve()
{
	long long x, y;
	long long p, q;
	scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
	fixRat(p, q);

	if (p == q && x != y)
	{
		printf("-1\n");
		return;
	}
	if (p == 0 && x != 0)
	{
		printf("-1\n");
		return;
	}
	if (x * q == y * p)
	{
		printf("0\n");
		return;
	}

	long long need1 = dup(x * q - p * y, p);
	long long need2 = dup(p * y - q * x, q - p);


	long long add = max(need1, need2);
	long long rem = (y + add) % q;

//	eprintf("need1 = %lld, need2 = %lld, add = %lld, rem = %lld\n",
//			need1, need2, add, rem);

	if (rem != 0) add += q - rem;
	printf("%lld\n", add);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();




	return 0;
}