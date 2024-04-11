#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxd = 3;
const ll Inf = 1000000000000000000ll;

int n;
ll a[Maxn][Maxd];
ll dp[Maxn][Maxd];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < n; j++)
			scanf("%I64d", &a[j][i]);
	fill((ll*)dp, (ll*)dp + Maxn * Maxd, -Inf);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i][0]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + a[i][0] + a[i][1]);
		dp[i + 1][2] = max(dp[i + 1][2], dp[i][0] + a[i][0] + a[i][1] + a[i][2]);

		dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + a[i][1] + a[i][0]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + a[i][1]);
		dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + a[i][1] + a[i][2]);

		dp[i + 1][0] = max(dp[i + 1][0], dp[i][2] + a[i][2] + a[i][1] + a[i][0]);
		dp[i + 1][1] = max(dp[i + 1][1], dp[i][2] + a[i][2] + a[i][1]);
		dp[i + 1][2] = max(dp[i + 1][2], dp[i][2] + a[i][2]);

		if (i + 2 <= n) {
			ll sum = a[i][0] + a[i + 1][0] + a[i][1] + a[i + 1][1] + a[i][2] + a[i + 1][2];
			dp[i + 2][0] = max(dp[i + 2][0], dp[i][2] + sum);
			dp[i + 2][2] = max(dp[i + 2][2], dp[i][0] + sum);
		}
	}
	printf("%I64d\n", dp[n][2]);
    return 0;
}