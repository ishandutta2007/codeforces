#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 1e7 + 10, L = 720720, mod = 998244353;
ll dp[L + 10][20],pwn[20],n,k,a0,x,y,M,ans;

int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &n, &a0, &x, &y, &k, &M);
	pwn[1] = n, pwn[0] = 1;
	for (ll i = 2; i <= k; ++i) pwn[i] = pwn[i - 1] * n % mod;
	for (ll i = 0; i < n; ++i)
		dp[a0 % L][0]++, (ans += k * pwn[k - 1] % mod * (a0 / L) % mod * L % mod) %= mod,
		a0 = (a0 * x % M + y) % M;
	for (ll j = 0; j < k; ++j)
		for (ll i = 0; i < L; ++i) {
			if (!dp[i][j]) continue;
			(ans += dp[i][j] * i % mod * pwn[k - j - 1] % mod) %= mod;
			(dp[i][j + 1] += dp[i][j] * (n - 1) % mod) %= mod;
			(dp[i / (j + 1) * (j + 1)][j + 1] += dp[i][j]) %= mod;
		}
	printf("%lld\n", ans);
	return 0;
}