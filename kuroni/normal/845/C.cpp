#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

pair <int, int>	a[400005];
int i, n, cnt = 0;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[2 * i - 1].first, &a[2 * i].first);
		a[2 * i - 1].second = -1;
		a[2 * i].second = 1;
	}
	sort(a + 1, a + 2 * n + 1);
	for (i = 1; i <= 2 * n; i++)
	{
		cnt -= a[i].second;
		if (cnt > 2)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}