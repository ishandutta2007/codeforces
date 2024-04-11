#include <bits/stdc++.h>
using namespace std;
int test, n, m, a[333333], c[333333], pos, cur;
long long ans, pre[333333], nw;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &c[i]);
		}
		cur = 1e9;pos = 1;
		for (int i = 1; i <= m; i++) pre[i] = pre[i-1] + c[i];
		nw = 0;
		for (int i = 1; i <= n; i++) 
		{
			nw += c[a[i]];
		}
		ans = nw;
		for (int i = n; i >= 1; i--)
		{
			cur = min(cur - 1, a[i] - 1);
			if (cur < 0) break;
			nw -= c[a[i]];
			ans = min(ans, pre[n - i + 1] + nw);
		}
		printf("%lld\n", ans);
	}
	return 0;
}