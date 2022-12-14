#include <bits/stdc++.h>
using namespace std;
int res, l, r, x, y, n, k, a[222222], test, num[222222], cur, pre[222222], cc, lst;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) num[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			num[a[i]] ++;
		}
		res = 1e9; y = 0;
		cur = -n;
		for (int i = 1; i <= n; i++)
		{
			while(y < n && cur < k)
			{
				y++;
				cur += (num[y] << 1);
			}
			if (cur >= k && y - i < res)
			{
				res = y - i;
				l = i; r = y;
			}
			if (y >= i) cur -= (num[i] << 1);
		}
		printf("%d %d\n", l, r);
		pre[0] = 0;
		for (int i = 1; i <= n; i++) 
		{
			if (a[i] >= l && a[i] <= r) pre[i] = pre[i - 1] + 1;
			else pre[i] = pre[i - 1] - 1;
		}
		cc = 1; lst = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cc == k) break;
			if (pre[i] == cc)
			{
				printf("%d %d\n", lst + 1, i);
				lst = i;
				cc++;
			}
		}
		printf("%d %d\n", lst + 1, n);
	}
	return 0;
}