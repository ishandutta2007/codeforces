#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int N = 1000;
const int V = 1e5;
ll dp[N+1][N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) cin >> vals[i];
	sort(vals.begin(), vals.end());
	vals.push_back(MOD);

	// Answer is at most V/(k-1). +10 for insurance
	for (int i = 0; i <= n; ++i) dp[i][0] = 1;
	ll res = 0;
	ll cou = 0;
	for (int r = V/(k-1) + 10; r >= 0; --r) {
		// Count ones where answer is at least r
		int j = n;
		for (int i = n-1; i >= 0; --i) {
			while(j-1 > i && vals[j-1] >= vals[i] + r) --j;
			for (int kk = 1; kk <= k; ++kk) {
				dp[i][kk] = (dp[i+1][kk] + dp[j][kk-1]) % MOD;
			}
		}
		ll nxt_cou = dp[0][k];
		res = (res + (nxt_cou - cou) * r) % MOD;
		cou = nxt_cou;
	}
	if (res < 0) res += MOD;
	cout << res << '\n';
}