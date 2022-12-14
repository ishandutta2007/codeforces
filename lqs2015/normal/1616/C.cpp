#include <bits/stdc++.h>
using namespace std;
int test, n, a[1111], ans, cur;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		if (n <= 2)
		{
			printf("0\n");
			continue;
		}
		ans = n - 2;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				cur = 0;
				for (int k = 1; k <= n; k++)
				{
					if ((k - i) * (a[k] - a[j]) != (k - j) * (a[k] - a[i])) cur++;
				}
				ans = min(ans, cur);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}