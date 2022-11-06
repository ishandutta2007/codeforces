#include <bits/stdc++.h>
using namespace std;

char s[100010], t[100010];
int p[100010], nxt[100010], is[100010];
int dp[100010], Dp[100010];
int main()
{
	scanf("%s%s", s, t);
	int ans = 0;
	int n = strlen(s);
	int m = strlen(t);
	p[0] = p[1] = 0;
	for(int i = 1; i < m; i ++)
	{
		int j = p[i];
		while(j && t[i] != t[j]) j = p[j];
		if(t[i] == t[j]) p[i + 1] = j + 1;
		else p[i + 1] = 0;
	}
	int num = m - p[m];
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m && i + j < n; j ++)
		{
			if(s[i + j] == '?' || s[i + j] == t[j]) is[i] ++;
			else break;
		}
	for(int i = n - 1; i >= 0; i --)
	{
		dp[i] = dp[i + 1];
		if(is[i] == m)
		{
			for(int j = m; p[j]; j = p[j])
				if(i + m - p[j] < n) Dp[i] = max(Dp[i], Dp[i + m - p[j]] + 1);
			Dp[i] = max(Dp[i], dp[i + m] + 1);
			dp[i] = max(dp[i], Dp[i]);
			ans = max(ans, dp[i]);
		}
	}
	printf("%d",ans);
	return 0;
}