#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;
char s[N];
vector<int> a[N], tran;
int dp[N][(1 << 4) + 5], full;
int cnt[1 << 4];
void Init()
{
	cnt[0] = 0;
	for(int i = 1; i < (1 << 4); i++) cnt[i] = cnt[i / 2] + (i & 1);
	return;
}
void solve1()
{
	int s1 = 0, s2 = 0;
	for(int i = 1; i <= n; i++)
	{
		int t = cnt[tran[i]] % 2;
		if(i & 1) s1 += t, s2 += t ^ 1;
		else s1 += t ^ 1, s2 += t;
	}
	printf("%d\n", min(s1, s2));
	return;
}
int main()
{
	Init();
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		for(int j = 0; j < m; j++)
		{
			int x = s[j] - '0';
			if(n >= 4 && m >= 4) continue;
			else if(n < m) a[i].push_back(x);
			else a[j].push_back(x);
		}
	}
	if(n >= 4 && m >= 4) return printf("-1\n"), 0;
	if(n <= 1 || m <= 1) return printf("0\n"), 0;
	if(n < m) swap(n, m);
	tran.push_back(0);
	for(int i = 0; i < n; i++)
	{
		int mas = 0;
		for(int j = 0; j < m; j++)
		{
			mas |= (1 << j) * a[j][i]; 
		}
		tran.push_back(mas);
	}
	full = (1 << m) - 1;
	if(m == 2)
	{
		solve1();
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int m1 = 0; m1 <= full; m1++)
		{
			dp[i][m1] = N * 3;
			for(int m2 = 0; m2 <= full; m2++)
			{
				int to = m1 ^ m2;
				if(cnt[to & 3] % 2 == 0 || cnt[(to >> 1) & 3] % 2 == 0) continue;
				dp[i][m1] = min(dp[i - 1][m2] + cnt[m1 ^ tran[i]], dp[i][m1]);
			}
		}
	}
	int ans = N * 3;
	for(int m1 = 0; m1 <= full; m1++) ans = min(ans, dp[n][m1]);
	printf("%d\n", ans);
	return 0;
}