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

const int Maxn = 300005;
const int Maxm = 605;
const int Inf = 2000000007;

int n;
int a[Maxn];
int cur, dp[2][Maxm];

int main()
{
	scanf("%d", &n);
	fill(dp[cur], dp[cur] + Maxm, Inf); dp[cur][0] = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); a[i] /= 100;
		fill(dp[!cur], dp[!cur] + Maxm, Inf);
		for (int j = 0; j < Maxm; j++) if (dp[cur][j] < Inf) {
			int tk = min(j, a[i]);
			dp[!cur][j - tk] = min(dp[!cur][j - tk], dp[cur][j] + a[i] - tk);
			if (j + a[i] / 10 < Maxm)
				dp[!cur][j + a[i] / 10] = min(dp[!cur][j + a[i] / 10], dp[cur][j] + a[i]);
		}
		cur = !cur;
	}
	int res = Inf;
	for (int i = 0; i < Maxm; i++)
		res = min(res, dp[cur][i]);
	printf("%d\n", 100 * res);
	return 0;
}