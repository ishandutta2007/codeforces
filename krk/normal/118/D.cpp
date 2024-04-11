#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 100000000;
const int Maxn = 101;
const int Maxk = 11;

int n1, n2, k1, k2;
int dp[Maxn][Maxn][Maxk][Maxk];

int Get(int n1, int n2, int c1, int c2)
{
	if (!n1 && !n2) return 1;
	if (dp[n1][n2][c1][c2] == -1) {
		int res = 0;
		if (n1 && c1 + 1 <= k1) res += Get(n1 - 1, n2, c1 + 1, 0);
		if (n2 && c2 + 1 <= k2) res += Get(n1, n2 - 1, 0, c2 + 1);
		dp[n1][n2][c1][c2] = res % mod;
	}
	return dp[n1][n2][c1][c2];
}

int main()
{
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxk * Maxk, -1);
	printf("%d\n", Get(n1, n2, 0, 0));
	return 0;
}