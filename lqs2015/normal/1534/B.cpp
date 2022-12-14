#include <bits/stdc++.h>
using namespace std;
int test, n, a[444444], pre, nxt;
long long ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			pre = (i == 1 ? 0 : a[i - 1]);
			nxt = (i == n ? 0 : a[i + 1]);
			if (a[i] > pre && a[i] > nxt)
			{
				ans += (a[i] - max(pre, nxt));
				a[i] = max(pre, nxt);
			}
		}
		ans += a[1];
		for (int i = 2; i <= n; i++) ans += abs(a[i] - a[i - 1]);
		ans += a[n];
		printf("%lld\n", ans);
	}
	return 0;
}