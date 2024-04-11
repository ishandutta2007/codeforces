#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 10 + (2e5);
const ll mod = 1e9 + 7;
ll dp[N][2];
ll val[N];
vector<int> conns[N];
ll ans = 0;

void dfs(int i, int p) {
	dp[i][0] = 1;
	dp[i][1] = 0;
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs(t, i);
		dp[i][0] += dp[t][1];
		dp[i][1] += dp[t][0];
	}
}

void dfs2(int i, int p, ll up_zero = 0, ll up_one = 0) {
	ll total_zero = up_one + dp[i][0];
	ll total_one = up_zero + dp[i][1];
	for (auto t : conns[i]) {
		if (t == p) continue;
		// Count for paths starting from this subtree
		ll oth_total = total_zero + total_one - dp[t][0] - dp[t][1];
		ans += val[i] * ((oth_total * (dp[t][1] - dp[t][0])) % mod);
		ans %= mod;
	}
	// Count for paths starting from parent
	ll oth_total = total_zero + total_one - up_zero - up_one;
	ans += val[i] * ((oth_total * (up_one - up_zero)) % mod);
	ans %= mod;
	// Count for paths starting here
	oth_total = total_zero + total_one;
	ans += (val[i] * oth_total) % mod;
	ans %= mod;
	// recurse
	for (auto t : conns[i]) {
		if (t == p) continue;
		dfs2(t, i, total_zero - dp[t][1], total_one - dp[t][0]);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> val[i];
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}
	dfs(0, 0);
	dfs2(0, 0);

	if (ans < 0) ans += mod;
	std::cout << ans << '\n';
}