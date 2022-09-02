#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

const int N = 3 * (int)1e5;
vector<pair<int, ll>> conns[N];
ll gas[N];
ll dp[N];
ll opt[N];

void calc(int i, int p) {
	dp[i] = gas[i];
	opt[i] = dp[i];
	for (auto ed : conns[i]) {
		int t = ed.first;
		if (t == p) continue;
		calc(t, i);

		opt[i] = max(max(opt[i], opt[t]), dp[i] + dp[t] - ed.second);
		dp[i] = max(dp[i], dp[t] - ed.second + gas[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> gas[i];
	for (int i = 0; i < n-1; ++i) {
		int a, b; ll c;
		cin >> a >> b >> c;
		--a; --b;
		conns[a].push_back({b, c});
		conns[b].push_back({a, c});
	}

	calc(0, 0);
	cout << opt[0] << '\n';
}