#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 10005;

int n, W, B, X;
int cost[Maxn];
int m;
int id[Maxn];
ll dp[2][Maxn];
int cur;

int main()
{
	scanf("%d %d %d %d", &n, &W, &B, &X);
	for (int i = 0; i < n; i++) {
		int cap; scanf("%d", &cap);
		while (cap--) id[m++] = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	fill((ll*)dp, (ll*)dp + 2 * Maxn, -Inf);
	dp[cur][0] = W;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) if (dp[cur][j] >= 0) {
			ll curcap = W + ll(j) * B;
			ll val = min(dp[cur][j], curcap);
			ll add = i + 1 < m? ll(id[i + 1] - id[i]) * X: 0;
			dp[!cur][j] = max(dp[!cur][j], val + add);
			if (cost[id[i]] <= val)
				dp[!cur][j + 1] = max(dp[!cur][j + 1], val - cost[id[i]] + add);
			dp[cur][j] = -Inf;
		}
		cur = !cur;
	}
	int tot = m;
	while (dp[cur][tot] < 0) tot--;
	printf("%d\n", tot);
	return 0;
}