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


const long long X = (long long) 2e9;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


	int n;
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		long long a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		a += X;
		b += X;
		c += X;
		d += X;
		int ans = (a % 2) * 2 + (b % 2) + 1;
		printf("%d\n", ans);
	}



	return 0;
}