#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, a[55], mn, x;
long long sum1, sum2;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n & 1)
		{
			printf("Mike\n");
			continue;
		} 
		mn = 2e9;
		for (int i = 1; i <= n; i++)
		{
			mn = min(mn, a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (mn == a[i])
			{
				x = i;
				break;
			}
		}
		if (x % 2 == 0) printf("Mike\n");
		else printf("Joe\n");
	}
	return Accepted;
}