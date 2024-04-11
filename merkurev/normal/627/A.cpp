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
	long long s, x;
	scanf("%lld%lld", &s, &x);
	long long dp0 = 1, dp1 = 0;

	bool flag = (s == x);

	while (s > 0)
	{
		int sb = (s & 1LL);
		int xb = (x & 1LL);
		s /= 2;
		x /= 2;

		long long ndp0 = 0, ndp1 = 0;
		for (int ab = 0; ab <= 1; ab++)
			for (int bb = 0; bb <= 1; bb++)
			{
				if ( (ab ^ bb) != xb) continue;
				if ( (ab + bb) % 2 == sb)
				{
					if (ab + bb == 2)
						ndp1 += dp0;
					else
						ndp0 += dp0;
				}
				else
				{
					if (ab + bb >= 1)
						ndp1 += dp1;
					else
						ndp0 += dp1;
				}
			}
		dp0 = ndp0;
		dp1 = ndp1;
	}
	
	if (flag) dp0 -= 2;
	if (x != 0)
	{
		dp0 = 0;
	}

	printf("%lld\n", dp0);


	return 0;
}