#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define MN 101000

int main()
{
	int n; scanf("%d", &n);
	long long lst = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		long long x; scanf("%lld", &x);
		long long M = std::min(x / 2, lst);
		ans += M;
		lst -= M; x -= 2 * M;
		ans += x / 3;
		x = x % 3;
		lst += x;
	}
	printf("%lld\n", ans);
}