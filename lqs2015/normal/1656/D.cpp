#include <bits/stdc++.h>
using namespace std;
int test;
long long n, d, nn;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%lld", &n);
		d = 1;
		while(n > 1 && n % 2 == 0)
		{
			n >>= 1;
			d <<= 1;
		}
		nn = n;
		n *= d;
		d <<= 1;
		if ((d > 2e9 || d * (d + 1) / 2 > n) && (nn == 1 || (nn > 2e9 && nn * (nn + 1) / 2 > n)))
		{
			printf("-1\n");
		}
		else if (d < 2e9 && d * (d + 1) / 2 <= n)
		{
			printf("%lld\n", d);
		}
		else 
		{
			printf("%lld\n", nn);
		}
	}
	return 0;
}