#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int64 INF = (int64)1e18;
const int N = (int)3e5 + 100;

int n;
vector<int> graph[N];
int64 s[N];

int64 dp[N][2];
int64 ans;

void dfs(int v)
{
	dp[v][0] = dp[v][1] = 0;

	for (int to : graph[v])
		dfs(to);
	
	dp[v][1] = -INF;

	for (int to : graph[v])
	{
		vector<int64> new_dp(2);
		new_dp[0] = 0;
		new_dp[1] = -INF;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int64 new_val = dp[v][i] + dp[to][j];
				//printf("i = %d j = %d new_val = %lld\n", i, j, new_val);
				new_dp[(i + j) % 2] = max(new_dp[(i + j) % 2], new_val);
			}
		}
		for (int i = 0; i < 2; i++)
			dp[v][i] = max(dp[v][i], new_dp[i]);
	}


	dp[v][1] = max(dp[v][1], dp[v][0] + s[v]);
	
	//printf("v = %d 0 = %lld 1 = %lld\n", v, dp[v][0], dp[v][1]);

	ans = max(ans, dp[v][0] + s[v]);
	ans = max(ans, dp[v][1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int p;
		scanf("%d%lld", &p, &s[i]);
		if (p != -1)
			graph[p].push_back(i);
	}

	dfs(1);

	printf("%lld\n", ans);

	return 0;
}