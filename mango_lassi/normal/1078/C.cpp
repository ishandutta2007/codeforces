#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD =  998244353;

const int N = 3 * (int)1e5;
ll dp[N][3]; // 0: not used, 1: used, 2: cut all children
vector<int> conns[N];

/*
ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	ll sub = modPow(a, b / 2);
	return (sub * sub) % MOD;
}
ll modInv(ll a) {
	return modPow(a, MOD-2);
}
*/

void calc(int i, int p) {

	dp[i][0] = 1;
	dp[i][1] = 0;
	dp[i][2] = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		calc(t, i);

		ll ways_cut = (dp[t][1] + dp[t][2]) % MOD;
		dp[i][2] = (dp[i][2] * ways_cut) % MOD;

		dp[i][1] = (dp[i][1] * (dp[t][1] + ways_cut)) % MOD;
		dp[i][1] = (dp[i][1] + (dp[t][0] + dp[t][2]) * dp[i][0]) % MOD;
		
		dp[i][0] = (dp[i][0] * (dp[t][1] + ways_cut)) % MOD;
	}
	dp[i][0] = (dp[i][0] - dp[i][2]) % MOD;
	if (dp[i][0] < 0) dp[i][0] += MOD;

	// cout << "calc(" << i << ' ' << p << "): " << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
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

	// Max matching cannot be unique if a node has more than two leaf children
	// Count for every node the amount of ways to make it's subtree have a maximum matching, so that it is free / it is not free.

	calc(0, 0);
	ll res = (dp[0][1] + dp[0][2]) % MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}