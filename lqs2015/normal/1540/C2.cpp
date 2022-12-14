#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, c[111], b[111], q, x, dp[111][11111], pre[111][11111], sum[111], all, ans[333], l, r, mnl, mnr, cc;
void add(int &x, int y)
{
	x += y;
	if (x >= mod) x -= mod; 
}
int solve(int x)
{
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i <= all; i++) pre[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = sum[i - 1] + i * x; j <= all; j++)
		{
			dp[i][j] = pre[i - 1][j];
			if (c[i] < j) dp[i][j] = (dp[i][j] - pre[i - 1][j - c[i] - 1]) % mod;
		}
		pre[i][0] = dp[i][0];
		for (int j = 1; j <= all; j++) pre[i][j] = (pre[i][j - 1] + dp[i][j]) % mod; 
	}
	int res = 0;
	for (int i = 0; i <= all; i++) res = (res + dp[n][i]) % mod;
	return res;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) scanf("%d", &b[i]);
	cc = 1;
	for (int i = 1; i <= n; i++) 
	{
		cc = 1ll * cc * (c[i] + 1) % mod;
	}
	for (int i = 1; i < n; i++)
	{
		sum[i] = sum[i - 1] + b[i];
	}
	for (int i = 1; i <= n; i++) all += c[i];
	mnl = mnr = 1e9;
	for (int i = 1; i <= n; i++)
	{
		l -= sum[i - 1];
		r += (c[i] - sum[i - 1]);
		mnl = min(mnl, l / i);
		mnr = min(mnr, r / i);
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1];
	for (int i = mnl; i <= mnr; i++) ans[i - mnl] = solve(i);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &x);
		if (x > mnr) printf("0\n");
		else if (x < mnl) printf("%d\n", cc);
		else printf("%d\n", (ans[x - mnl] + mod) % mod);
	}
	return 0;
}