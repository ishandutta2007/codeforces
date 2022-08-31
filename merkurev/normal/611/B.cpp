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




int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	long long a, b;
	scanf("%lld%lld", &a, &b);
	int ans = 0;
	for (int cnt = 2; cnt <= 60; cnt++)
	{
		long long x = (1LL << cnt) - 1;
		for (int pos = 0; pos < cnt - 1; pos++)
		{
			long long y = x ^ (1LL << pos);
			if (a <= y && y <= b)
				ans++;
		}
	}
	printf("%d\n", ans);




	return 0;
}