#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 5005;

int n, k, q;
int dp[Maxn][Maxn];
int a[Maxn];
int tims[Maxn];
int cur;

int main()
{
	scanf("%d %d %d", &n, &k, &q);
	for (int j = 1; j <= n; j++)
		dp[0][j] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
	for (int j = 1; j <= n; j++) {
		scanf("%d", &a[j]);
		for (int i = 0; i <= k; i++)
			tims[j] = (tims[j] + ll(dp[i][j]) * dp[k - i][j]) % mod;
		cur = (cur + ll(tims[j]) * a[j]) % mod;
	}
	while (q--) {
		int ind, val; scanf("%d %d", &ind, &val);
		cur = (cur - ll(tims[ind]) * a[ind] % mod + mod) % mod;
		a[ind] = val;
		cur = (cur + ll(tims[ind]) * a[ind]) % mod;
		printf("%d\n", cur);
	}
    return 0;
}