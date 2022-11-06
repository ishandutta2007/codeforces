#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 1e9;
char ch[20][110];
int b[20], a[20][110], dp[110][110];

int daijia1(int k)
{
	int w = 0, pos = 0;
	for(int i = 2; i < m; i ++)
        if(a[k][i] == 1) pos = i - 1;
	return pos * 2;
}

int daijia2(int k)
{
	int w = 0, pos = m;
	for(int i = m - 1; i >= 2; i --)
        if(a[k][i] == 1) pos = i;
	return (m - pos) * 2;
}

int main()
{
	scanf("%d%d", &n, &m);
	m += 2;
	for(int i = n; i >= 1; i --) scanf("%s", ch[i] + 1);
	for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            a[i][j] = ch[i][j] - '0';
	dp[1][0] = daijia1(1);
	dp[1][1] = m - 1;
	for(int i = 2; i <= n; i ++)
	{
		dp[i][0] = min(dp[i - 1][1] + 1 + m - 1, dp[i - 1][0] + 1 + daijia1(i));
		dp[i][1] = min(dp[i - 1][1] + 1 + daijia2(i), dp[i-1][0] + 1 + m - 1);
	}
	for(int i = n; i >= 1; i --)
	{
		int now = 0;
		for(int j = 1; j <= m; j ++) now += a[i][j];
		if(now == 0) continue;
		if(i == 1) printf("%d",daijia1(1) / 2);
		else printf("%d", min(dp[i - 1][1] + 1 + daijia2(i) / 2, dp[i - 1][0] + 1 + daijia1(i) / 2));
		return 0;
	}
	printf("0");
	return 0;
}