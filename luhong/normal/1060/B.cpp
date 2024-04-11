#include <cstdio>
#include <iostream>

using namespace std;
int get_ans(long long x)
{
	int y = 0;
	while(x)
	{
		y += x % 10;
		x /= 10;
	}
	return y;
}
int main()
{
	long long n; scanf("%lld", &n);
	int ans = 0;
	for(long long i = 1; i <= n; i *= 10)
	{
		long long a = i - 1;
		long long b = n - a;
		ans = max(ans, get_ans(a) + get_ans(b));
	}
	printf("%d\n", ans);
	return 0;
}