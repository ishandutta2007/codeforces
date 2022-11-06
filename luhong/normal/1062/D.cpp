#include <iostream>
#include <cstdio>
#define MN 101000

int main()
{
	int n; scanf("%d", &n);
	long long ans = 0;
	for(int i = 2; i <= n; i++)
	{
		ans += 1ll * (2 + n / i) * (n / i - 1) / 2;
	}
	printf("%lld\n", ans * 4);
	return 0;
}
//ij4