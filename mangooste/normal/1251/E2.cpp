#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ll ans = 0;
		vector<vector<int>> events(n);

		for (int i = 0; i < n; i++) {
			int m, p;
			cin >> m >> p;
			events[m].push_back(p);
			ans += p;
		}

		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			for (auto p : events[i]) {
				pq.push(p);
			}
			if (pq.size()) {
				ans -= pq.top();
				pq.pop();
			}
		}

		cout << ans << '\n';
	}
}