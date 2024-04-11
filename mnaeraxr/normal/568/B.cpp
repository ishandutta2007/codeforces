#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 4010;
const int64 mod = 1000000007;

int64 dp[maxn][maxn];

int64 solve(int n, int k){
	if (k > n) return 0;
	if (n == 0 && k == 0) return 1;
	int64 &val = dp[n][k];
	if (val != -1) return val;
	val = (solve(n - 1, k - 1) + solve(n - 1, k) * k % mod) % mod;
	return val;
}

int64 fact[maxn];

int64 modexp(int64 v, int64 p){
	if (p == 0) return 1;
	int64 ans = modexp(v * v % mod, p / 2);
	if (p & 1) ans = ans * v % mod;
	return ans;
}

int64 inverse(int64 v){
	return modexp(v, mod - 2);
}

int64 comb(int64 n, int64 k){
	return fact[n] * inverse(fact[k]) % mod * inverse(fact[n - k]) % mod;
}

int64 dp1[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	memset(dp, -1, sizeof dp);

	for (int i = 1; i < n; ++i){
		for (int j = 1; j <= i; ++j){
			dp1[i] = (dp1[i] + solve(i, j)) % mod;
			// cout << i << " " << j << " " << solve(i, j) << endl;
		}
		// cout << dp1[i] << endl;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = 1LL * i * fact[i - 1] % mod;

	int64 ans = 1;

	for (int i = 1; i < n; ++i)
		ans = (ans + comb(n, i) * dp1[n, i] % mod) % mod;

	cout << ans << endl;

	return 0;
}