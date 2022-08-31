#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 1050;
const int INF = (int)1e9;

int n, T;
int t[N], q[N];
int pow2[N];
int dp[N][N];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &t[i], &q[i]);

	pow2[0] = 1;
	for (int i = 1; i < N; i++)
		pow2[i] = min(n, pow2[i - 1] * 2);

	vector<pair<int, int> > list;
	for (int i = 0; i < n; i++)
	{
		int cur_h = T - t[i];
		if (cur_h < 0)
			continue;
		list.push_back({cur_h, q[i]});
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = -INF;

	if (list.empty())
	{
		printf("0\n");
		return 0;
	}
	
	int ans = 0;
	dp[0][pow2[list[0].first]] = 0;
	for (int pos = 0; pos <= (int)list.size(); pos++)
	{
		for (int num_v = 0; num_v <= n; num_v++)
		{
			if (pos == (int)list.size())
			{
				ans = max(ans, dp[pos][num_v]);
				continue;
			}
			if (dp[pos][num_v] == -INF)
				continue;

			int dh = 0;
			if (pos + 1 < (int)list.size())
				dh = list[pos + 1].first - list[pos].first;

			int val1 = dp[pos][num_v];
			int num_v1 = min(n, num_v * pow2[dh]);

			dp[pos + 1][num_v1] = max(dp[pos + 1][num_v1], val1);

			if (num_v != 0)
			{
				int val2 = dp[pos][num_v] + list[pos].second;
				int num_v2 = min(n, (num_v - 1) * pow2[dh]);
				dp[pos + 1][num_v2] = max(dp[pos + 1][num_v2], val2);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}