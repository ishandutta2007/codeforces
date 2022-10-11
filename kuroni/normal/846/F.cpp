#include <iostream>
#include <cstdio>

int a, i, n, cur[1000005];
long long sum[1000005], ans = 0;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum[i] = sum[i - 1] + i - cur[a];
		ans += sum[i];
		cur[a] = i;
	}
	printf("%.6f", (ans * 2.0 - n) / n / n);
}