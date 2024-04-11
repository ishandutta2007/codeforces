#include <cstdio>

int main()
{
	puts("YES");
	long long l, r; scanf("%lld%lld", &l, &r);
	for(long long i = l; i <= r; i += 2)
	{
		printf("%lld %lld\n", i, i + 1);
	}
	return 0;
}