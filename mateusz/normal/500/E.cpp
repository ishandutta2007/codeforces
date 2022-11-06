#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 500005, INF = 2 * 1e9;
int n, a, b, m;
int dp[20][N];
int to[20][N];
int ind[N];
int range[20][N], size;
pair<int, int> S[N];
int p[N], l[N], mini[N];
pair<int, int> query(int a, int b)
{
	if(a > n || a == 0) return make_pair(0, 0);
	if(a == b) return make_pair(0, range[0][a]);
	if(a > b)
		return make_pair(0, 0);
	int length = b - a + 1;
	int ll = mini[length];
	if(to[ll][a] > b) {
		return make_pair(dp[ll][a], range[ll][a]);
	}
	pair<int, int> P = query(to[ll][a], b);
	int r = max(range[ll][a], P.second);
	return make_pair(dp[ll][a] + p[to[ll][a]] - range[ll][a] + P.first, r);
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d %d", &p[i], &l[i]);
	for(int i = n; i >= 1; i--)
	{
		int x = p[i] + l[i];
		while(size > 0 && S[size].first <= x)
		{
			x = max(x, S[size].second);
			size--;
		}
		range[0][i] = x;
		to[0][i] = size > 0? ind[size]: n + 1;
		S[++size] = make_pair(p[i], range[0][i]);
		ind[size] = i;
	}
	int pot = 1;
	int g = 0;
	mini[1] = g;
	for(int i = 2; i <= n; i++)
	{
		if(2 * pot == i)
		{
			pot *= 2;
			g++;
		}
		mini[i] = g;
	}
	for(int i = 1; i <= 18; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(to[i - 1][j] > j + (1 << i) - 1)
			{
				dp[i][j] = dp[i - 1][j];
				to[i][j] = max(to[i - 1][j], to[i - 1][j + (1 << (i - 1))]);
				range[i][j] = max(range[i - 1][j], range[i - 1][j + (1 << (i - 1))]);
				continue;
			}
			pair<int, int> P = query(to[i - 1][j], j + (1 << i) - 1);
			dp[i][j] = dp[i - 1][j] + p[to[i - 1][j]] - range[i - 1][j] + P.first;
			range[i][j] = max(range[i - 1][j], P.second);
			to[i][j] = to[i - 1][j + (1 << (i - 1))];
		}
	}
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b).first);
	}
}