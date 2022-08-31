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


const long long INF = (long long) 1e18;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	long long add = 0;
	long long l = -INF, r = INF;
	for (int i = 0; i < n; i++)
	{
		int c, d;
		scanf("%d%d", &c, &d);
		if (d == 1)
		{
			l = max(l, 1900 - add);
		}
		else if (d == 2)
		{
			r = min(r, 1899 - add);
		}
		else throw;
		add += c;
	}
	if (l > r)
	{
		printf("Impossible\n");
		return 0;
	}
	if (r == INF)
	{
		printf("Infinity\n");
		return 0;
	}
	printf("%lld\n", r + add);



	return 0;
}