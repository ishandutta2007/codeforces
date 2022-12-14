#include <stdio.h>
#define MAXN 1000005
int n, op[MAXN];
int main()
{
	int i, ans = 0, t;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &t);
		ans ^= t;
		op[i] = i ^ op[i - 1];
	}
	for(i = 2; i <= n; i ++)
	{
		if((n / i) % 2)
			ans ^= op[i - 1];
		ans ^= op[n % i];
	}
	printf("%d\n", ans);
	return 0;
}