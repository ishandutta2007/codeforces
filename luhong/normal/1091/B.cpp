#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int n;

int main()
{
	long long x = 0, y = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n + n; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		x += a; y += b;
	}
	printf("%lld %lld", x / n, y / n);
}