#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct person {
	int cost, k, mask;

	person(int cost = 0, int k = 0, int mask = 0) :
		cost(cost), k(k), mask(mask)
	{}
};

const ll INF = 3e18;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m, b;
	cin >> n >> m >> b;
	vector<person> all(n);
	for (int i = 0; i < n; i++) {
		int mi;
		cin >> all[i].cost >> all[i].k >> mi;
		for (int j = 0; j < mi; j++) {
			int num;
			cin >> num;
			num--;
			all[i].mask |= (1 << num);
		}
	}
	sort(all.begin(), all.end(), [](person &a, person &b) {
		return a.k > b.k;
	});

	vector<ll> dp(1 << m, INF);
	for (auto now : all) {
		for (int mask = (1 << m) - 1; mask; mask--)
			if (dp[mask] != INF)
				dp[mask | now.mask] = min(dp[mask | now.mask], dp[mask] + now.cost);

		dp[now.mask] = min(dp[now.mask], (ll) b * now.k + now.cost);
	}
	cout << (dp.back() == INF ? -1 : dp.back()) << '\n';
}