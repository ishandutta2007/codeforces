#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int k = 1;
	while((1<<k) < n) ++k;

	vector<ll> as;
	bool app = false;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		if (a == -1) app = true;
		else as.push_back(app ? a : 0);
	}
	--n;

	ll rems = n;
	vector<ll> dp(n, 0);
	for (int d = 0; d < k; ++d) {
		rems -= (1<<d);
		int a = n - rems - 1;

		// First round: Any
		// Second round: Any but two worst

		//         z
		//       y   y
		//      x x x x

		ll off = (d == 0 ? 0 : INF);
		vector<ll> nxt(n, INF);
		for (int i = 0; i < a; ++i) off = min(off, dp[i]);

		for (int b = a; b < n; ++b) {
			nxt[b] = off + as[b];
			off = min(off, dp[b]);
		}
		dp = nxt;
	}
	cout << dp.back() << '\n';
}