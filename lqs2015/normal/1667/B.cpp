#include <bits/stdc++.h>
using namespace std;
map<long long, int> mp;
int a[555555], n, test, cnt, dp[555555], mn[555555], bit[1111111], sz, fm[555555];
long long pre[555555], arr[555555];
void upd(int x, int y)
{
	while(x <= sz)
	{
		bit[x] = min(bit[x], y);
		x += x & (-x);
	}
}
int query(int x)
{
	int res = 1e9;
	while(x >= 1)
	{
		res = min(res, bit[x]);
		x -= x & (-x);
	}
	return res;
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
		mp.clear();
		for (int i = 0; i <= n; i++) arr[i + 1] = pre[i];
		sort(arr + 1, arr + n + 2);
		cnt = unique(arr + 1, arr + n + 2) - arr - 1;
		for (int i = 1; i <= cnt; i++) mp[arr[i]] = i;
		for (int i = 1; i <= cnt; i++) mn[i] = fm[i] = 1e9;
		mn[mp[0]] = 0; sz = 1; fm[mp[0]] = 0;
		while(sz < cnt) sz <<= 1;
		for (int i = 1; i <= sz; i++) bit[i] = 1e9;
		upd(mp[0], 0);
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1] + 2;
			dp[i] = min(dp[i], fm[mp[pre[i]]] + i);
			dp[i] = min(dp[i], query(mp[pre[i]] - 1));
			fm[mp[pre[i]]] = min(fm[mp[pre[i]]], dp[i] - i);
			upd(mp[pre[i]], dp[i]);
		}
		printf("%d\n", n - dp[n]);
	}
	return 0;
}