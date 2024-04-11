#include <bits/stdc++.h>
using namespace std;
int test, n, k;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &k);
		if (k == 0)
		{
			for (int i = 0; i < n / 2; i++) printf("%d %d\n", i, n - 1 - i);
		}
		else if (k <= n - 2)
		{
			printf("%d %d\n", k, n - 1);
			printf("%d %d\n", 0, n - 1 - k);
			for (int i = 1; i < n / 2; i++) 
			{
				if (i != k && i != n - 1 - k) printf("%d %d\n", i, n - 1 - i);
			}
		}
		else
		{
			if (n == 4) printf("-1\n");
			else
			{
				printf("%d %d\n", n - 3, n - 1);
				printf("%d %d\n", 2, n - 2);
				printf("%d %d\n", 0, 1);
				for (int i = 3; i < n / 2; i++) printf("%d %d\n", i, n - 1 - i);
			}
		}
	}
	return 0;
}