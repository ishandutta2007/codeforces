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

map <long long, long long> len;

long long getLen(long long x)
{
	if (x <= 1) return 1;
	if (len.count(x) == 0)
		len[x] = 2 * getLen(x / 2) + 1;
	return len[x];
}

long long solve(long long n, long long l, long long r)
{
	l = max(l, 0LL);
	if (r < l) return 0;
	if (l >= getLen(n) ) return 0;
	
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	long long a = getLen(n / 2);
	return solve(n / 2, l, r) + solve(n % 2, l - a, r - a) + solve(n / 2, l - a - 1, r - a - 1);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	long long n;
	scanf("%lld", &n);
	long long l, r;
	scanf("%lld%lld", &l, &r);
	l--;
	r--;

	long long ans = solve(n, l, r);
	
	printf("%lld\n", ans);


	return 0;
}