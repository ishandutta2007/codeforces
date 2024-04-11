#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;
 
const int N = (int)1e6;
ll dp[N + 1][2]; // Min cost, odd number of current twos
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	ll n, r1, r2, r3, d; // r1, r2, r3: Weak, AOE, Strong
	cin >> n >> r1 >> r2 >> r3 >> d;
 
	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	dp[0][1] = INF;
	for (int i = 0; i < n; ++i) {
		ll c1 = r1 * as[i] + r3; // Kill the boss in one attack
		ll c2 = min(r1 + r2, r1 * (as[i]+2)) + d; // Kill the boss in two attacks
		dp[i+1][0] = min(c1 + min(dp[i][0], (i == n-1 ? dp[i][1] : INF)), c2 + dp[i][1]);
		dp[i+1][1] = c2 + dp[i][0];
	}
	cout << (min(dp[n][0], dp[n][1] + d) + d*(n-1)) << '\n';
}