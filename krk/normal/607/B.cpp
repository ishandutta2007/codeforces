#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 505;
const int Inf = 1000000000;

int n;
int c[Maxn];
int dp[Maxn][Maxn];

int Get(int l, int r)
{
	if (l > r) return 0;
	if (dp[l][r] == Inf) {
		int res = 1 + Get(l + 1, r);
		for (int i = l + 1; i <= r; i++) if (c[l] == c[i])
			res = min(res, max(1, Get(l + 1, i - 1)) + Get(i + 1, r));
		dp[l][r] = res;
	}
	return dp[l][r];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	printf("%d\n", Get(0, n - 1));
	return 0;
}