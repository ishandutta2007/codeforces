#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n; ll a, b;
	cin >> n >> a >> b;
	ll dp0 = 0;
	ll dp1 = INF;

	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) {
		ll nxt_dp0 = INF;
		ll nxt_dp1 = INF;
		if (str[i] == '0') {
			nxt_dp0 = min(dp0, dp1 + a);
			nxt_dp1 = min(dp0 + a + b, dp1 + b);
		} else {
			nxt_dp0 = INF;
			nxt_dp1 = dp1 + b;
		}
		dp0 = nxt_dp0;
		dp1 = nxt_dp1;
	}
	ll res = n*a + (n+1)*b + dp0;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}