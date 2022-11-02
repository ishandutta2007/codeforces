#include <bits/stdc++.h>
using namespace std;
int n, m, k[200005], to[200005], cnt[200005], tot, res, ans, l, r;
int main()
{
#ifdef _noname
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(cnt, 0, sizeof cnt);
	tot = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", k + i);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", to + i);
		tot += to[i];
	}
	for (int i = 1; i <= tot; i++) cnt[k[i]]++;
	for (int i = 1; i <= m; i++) res += (cnt[i] < to[i]);
	if (!res) ans = 0;
	else ans = -1;
	l = 1, r = tot;
	while (r <= n)
	{
		if (res)
		{
			if (r == n) break;
			r++;
			cnt[k[r]]++;
			if (cnt[k[r]] == to[k[r]]) res--;
		}
		else
		{
			ans = (ans == -1? r - l + 1 - tot : min(ans, r - l + 1 - tot));
			if (cnt[k[l]] == to[k[l]]) res++;
			cnt[k[l]]--;
			l++;
		}
	}
	printf("%d\n", ans);
	return 0;
}