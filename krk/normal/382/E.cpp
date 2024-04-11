#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 52;
const int mod = 1000000007;
const int inv = (mod + 1) / 2;

int n, k;
int C[Maxn][Maxn];
int dp[Maxn][Maxn][3];

bool Less(int a1, int b1, int c1, int a2, int b2, int c2)
{
	if (a1 != a2) return a1 < a2;
	if (b1 != b2) return b1 < b2;
	return c1 <= c2;
}

bool Eq(int a1, int b1, int c1, int a2, int b2, int c2)
{
	return a1 == a2 && b1 == b2 && c1 == c2;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	dp[0][0][1] = dp[1][0][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1 - j; j++)
			for (int a1 = 0; a1 <= k; a1++)
				for (int a2 = 0; a2 < 3; a2++)
					for (int b1 = 0; b1 <= k; b1++)
						for (int b2 = 0; b2 < 3; b2++)
							if (Less(j, a1, a2, i - 1 - j, b1, b2)) {
								int ways = ll(C[i - 1][j]) * dp[j][a1][a2] % mod * dp[i - 1 - j][b1][b2] % mod;
								if (Eq(j, a1, a2, i - 1 - j, b1, b2)) ways = ll(ways) * inv % mod;
								int ntak1 = a1, tak1 = a1 - 1 + a2;
								int ntak2 = b1, tak2 = b1 - 1 + b2;
								int ntak = max(ntak1, tak1) + max(ntak2, tak2);
								int tak = max((j? 1: 0) + ntak1 + max(ntak2, tak2), max(ntak1, tak1) + (i - 1 - j? 1: 0) + ntak2);
								if (max(ntak, tak) > k) continue;
								int delt = tak - ntak + 1;
								dp[i][ntak][delt] = (dp[i][ntak][delt] + ways) % mod;
							}
		if (i != n)
			for (int j = 0; j <= k; j++)
				for (int a = 0; a < 3; a++) {
					dp[i][j][a] = ll(dp[i][j][a]) * i % mod;
				}
	}
	int res = 0;
	for (int j = 0; j <= k; j++)
		for (int a = 0; a < 3; a++)
			if (max(j, j - 1 + a) == k) 
				res = (res + dp[n][j][a]) % mod;
	printf("%d\n", res);
	return 0;
}