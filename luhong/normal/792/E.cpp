#include <cstdio>
#include <cstring>
#include <algorithm>

int a[550], n;
long long ans = 1e18;

void check(int x)
{
	if(x == 0) return;
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] / x < a[i] % x) return;
		sum += a[i] / (x + 1) + (a[i] % (x + 1) > 0);
	}
	ans = std::min(ans, sum);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 1; i * i <= a[1]; i++)
	{
		check(i);
		check(i - 1);
		check(i + 1);
		check(a[1] / i);
		check(a[1] / i - 1);
		check(a[1] / i + 1);
	}
	printf("%lld\n", ans);
	return 0;
}