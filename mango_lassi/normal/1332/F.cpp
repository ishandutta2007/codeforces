#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b < 0) b += MOD - 1;
	if (b & 1) return a * modPow(a, b-1) % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 3 * (int)1e5;
vector<int> conns[N];
ll dp[N][3]; // Count where (0) : not used; (1): used, edge to parent exists; (2): used, edge to parent doesn't exist

void dfs(int i, int p) {
	dp[i][0] = 1;
	dp[i][1] = 1;
	dp[i][2] = 0;
	ll tmp = 1; // Count where used, but vertex doesn't yet exist
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		ll mult = (2 * dp[t][0] + dp[t][2]) % MOD;
		dp[i][0] = (dp[i][0] * (mult + dp[t][1])) % MOD;
		dp[i][1] = (dp[i][1] * mult) % MOD;
		dp[i][2] = (dp[i][2] * mult + tmp * dp[t][0]) % MOD;
		tmp = (tmp * (dp[t][0] + dp[t][2])) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	dfs(0, -1);
	ll res = dp[0][0] + dp[0][2] - 1;
	if (res >= MOD) res -= MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}