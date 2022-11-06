#include <iostream>
#include <cstdio>

int a[201000], b[201000], ans = 0;
int main()
{
	int n, h; scanf("%d%d", &n, &h);
	int r = 1;
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		while(r < n)
		{
			if(sum + a[r + 1] - b[r] >= h) break;
			sum += a[r + 1] - b[r]; r++;
		}
		ans = std::max(ans, b[r] - a[i] + h - sum);
		sum -= a[i + 1] - b[i];
	}
	printf("%d\n", ans);
	return 0;
}