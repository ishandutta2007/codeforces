#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if(c & 1) printf("%lld\n", 1ll * a * (c / 2 + 1) - 1ll * b * (c / 2));
		else printf("%lld\n", 1ll * a * (c / 2) - 1ll * b * (c / 2));
	}
	return 0;
}