#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 3005;

int n, m;
char b[Maxn][Maxn];
int dp[Maxn][Maxn];
int A, B;
int C, D;
int res;

void Fill(int sr, int sc)
{
	fill((int*)dp, (int*)dp + Maxn * Maxn, 0);
	if (b[sr][sc] != '#') dp[sr][sc] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (dp[i][j]) {
			if (i + 1 < n && b[i + 1][j] != '#') {
				dp[i + 1][j] += dp[i][j];
				if (dp[i + 1][j] >= mod) dp[i + 1][j] -= mod;
			}
			if (j + 1 < m && b[i][j + 1] != '#') {
				dp[i][j + 1] += dp[i][j];
				if (dp[i][j + 1] >= mod) dp[i][j + 1] -= mod;
			}
		}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", b[i]);
	Fill(0, 1); A = dp[n - 2][m - 1]; B = dp[n - 1][m - 2];
	Fill(1, 0); C = dp[n - 2][m - 1]; D = dp[n - 1][m - 2];
	res = ((ll(A) * ll(D)) % ll(mod) - ll(B) * ll(C) % ll(mod) + ll(mod)) % ll(mod);
	printf("%d\n", res);
	return 0;
}