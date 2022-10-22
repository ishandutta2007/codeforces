#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 32;
const int Maxk = 52;
const int Inf = 1000000000;

int dp[Maxn][Maxn][Maxk];
int t;

int Get(int r, int c, int k)
{
	if (r > c) swap(r, c);
	if (dp[r][c][k] == -1)
		if (r * c < k) dp[r][c][k] = Inf;
		else if (k == 0 || r * c == k) dp[r][c][k] = 0;
		else {
			int res = Inf;
			for (int i = 1; i < r; i++)
				for (int j = 0; j <= k; j++)
					res = min(res, Get(i, c, j) + c * c + Get(r - i, c, k - j));
			for (int i = 1; i < c; i++)
				for (int j = 0; j <= k; j++)
					res = min(res, Get(r, i, j) + r * r + Get(r, c - i, k - j));
			dp[r][c][k] = res;
		}
	return dp[r][c][k];
}

int main()
{
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxk, -1);
	scanf("%d", &t);
	while (t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", Get(n, m, k));
	}
	return 0;
}