#include <cstdio>
#include <cstring>
#include <algorithm>
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	if(n > m) std::swap(n, m);
	if(n == 1)
	{
		int add = 0;
		if(m % 6 == 0 || m % 6 == 1 || m % 6 == 2 || m % 6 == 3) add = 0;
		if(m % 6 == 4) add = 2;
		if(m % 6 == 5) add = 4;
		printf("%d", m / 6 * 6 + add);
	}
	else if(n == 2)
	{
		if(m == 2) puts("0");
		else if(m == 3) puts("4");
		else if(m == 7) puts("12");
		else printf("%d\n", m * 2);
	}
	else
	{
		printf("%lld\n", 1ll * m * n / 2 * 2);
	}
	return 0;
}