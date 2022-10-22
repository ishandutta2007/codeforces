#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 2005;
const int Inf = 2000000007;

int n, k, p;
int pos[Maxn], keys[Maxn];
int dp[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < n; i++)
		scanf("%d", &pos[i]);
	for (int i = 0; i < k; i++)
		scanf("%d", &keys[i]);
	sort(pos, pos + n); sort(keys, keys + k);
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) if (dp[i][j] < Inf) {
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			int cand = abs(pos[i] - keys[j]) + abs(keys[j] - p);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], cand));
		}
	int res = Inf;
	for (int j = 0; j <= k; j++)
		res = min(res, dp[n][j]);
	printf("%d\n", res);
	return 0;
}