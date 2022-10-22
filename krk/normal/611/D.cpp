#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int mod = 1000000007;

int dp[Maxn][Maxn];
int n;
char S[Maxn];
int sam[Maxn][Maxn];

int Get(int l, int r)
{
	if (r >= n) return 0;
	if (dp[l][r] == -1) {
		int res = 0;
		if (r == n - 1) res = 1;
		else {
			res = Get(l, r + 1);
			if (S[r + 1] != '0') {
				int k = sam[l][r + 1];
				if (l + k >= r + 1) res = (res + Get(r + 1, r + 1 + (r - l + 1))) % mod;
				else if (r + 1 + k < n)
						if (S[l + k] < S[r + 1 + k]) res = (res + Get(r + 1, r + 1 + (r - l))) % mod;
						else res = (res + Get(r + 1, r + 1 + (r - l + 1))) % mod;
			}
		}
		dp[l][r] = res;
	}
	return dp[l][r];
}

int main()
{
	fill((int*)dp, (int*)dp + Maxn * Maxn, -1);
	scanf("%d", &n);
	scanf("%s", S);
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			sam[i][j] = S[i] != S[j]? 0: 1 + sam[i + 1][j + 1];
	printf("%d\n", Get(0, 0));
	return 0;
}