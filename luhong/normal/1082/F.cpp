#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 510

const int INF = 1e9;
int ch[MN][11], tot = 1;
int dp[MN][MN][12];
int dep[MN], cnt[MN], K;

void build(char *s, int m)
{
	int len = strlen(s);
	int now = 1;
	for(int i = 0; i < len; i++)
	{
		if(!ch[now][s[i] - '0']) ch[now][s[i] - '0'] = ++tot;
		now = ch[now][s[i] - '0'];
	}
	cnt[now] += m;
}

void dfs(int x, int d)
{
	if(!x) return;
	dep[x] = d;
	for(int i = 0; i < 10; i++)
		dfs(ch[x][i], d + 1);
}

void solve(int x)
{
	for(int j = 1; j <= dep[x]; j++)
	{
		for(int k = 0; k <= K; k++) dp[x][j][k] = INF;
		dp[x][j][1] = (dep[x] - j) * cnt[x];
	}
	for(int i = 0; i < 10; i++)
	{
		if(ch[x][i])
		{
			solve(ch[x][i]);
			for(int j = 1; j <= dep[x]; j++)
			{
				for(int k = K; k >= 1; k--)
				{
					int Min = 1e9;
					for(int l = 1; l <= k; l++)
					{
						Min = std::min(Min, dp[ch[x][i]][j][l] + dp[x][j][k - l + 1]);
						Min = std::min(Min, dp[ch[x][i]][dep[ch[x][i]]][l] + dp[x][j][k - l]);
					}
					dp[x][j][k] = Min;
				}
			}
		}
	}
}

char c[555];
int main()
{
	int n; scanf("%d%d", &n, &K); K++;
	for(int i = 1; i <= n; i++)
	{
		int m;
		scanf("%s%d", c, &m);
		build(c, m);
	}
	dfs(1, 1);
	solve(1);
	int ans = INF;
	for(int j = 1; j <= K; j++) ans = std::min(ans, dp[1][1][j]);
	printf("%d\n", ans);
	return 0;
}

/*
dp[i][j][k]iijk 

dp[i][j][k] = dp[son][j][l] + dp[i][j][k - l + 1]
            = dp[son][son][l] + dp[i][j][k - l]

dp[i][j][k] += (dep[i] - j) * cnt[i]
*/