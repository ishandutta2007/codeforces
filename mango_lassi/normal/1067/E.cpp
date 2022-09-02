#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

const int N = 5 * (int)1e5;
vector<int> conns[N];

ll res = 0;
ll dp[N]; // Probability that we have edge to parent from here (priority to parent is lowest)

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	return modPow(a*a % MOD, b / 2);
}

ll modInv(ll v) {
	return modPow(v, MOD - 2);
}

void solve(int i, int p) {
	ll pc = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		solve(t, i);
		pc = (pc * (1 - dp[t])) % MOD;
	}
	res = (res + (1 - pc)) % MOD;
	dp[i] = (modInv(2) * pc) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Rank of adjancency matrix equals pairing number
	// What is the expected pairing number?

	// Calculate expected pairing number for every subtree if the edge to it is removed, and if it's not removed	

	int n;
	cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b),
		conns[b].push_back(a);
	}

	solve(0, 0);
	for (int i = 0; i < n; ++i) res = (res * 2) % MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}