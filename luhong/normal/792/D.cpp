#include <cstdio>
#include <cstring>

char s[101000];
int main()
{
	long long n; int q; scanf("%lld%d", &n, &q);
	for(int i = 1; i <= q; i++)
	{
		long long x; scanf("%lld", &x);
		int len;
		scanf("%s", s);
		len = strlen(s);
		for(int j = 0; j < len; j++)
		{
			long long u = x & (-x);
			if(s[j] == 'U' && x != (n / 2 + 1)) x -= x & -x, x |= (u << 1);
			if(s[j] == 'L' && u != 1) x |= u >> 1, x ^= u;
			if(s[j] == 'R' && u != 1) x |= u >> 1; 
		}
		printf("%lld\n", x);
	}
	return 0;
}