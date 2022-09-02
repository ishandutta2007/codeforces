#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int N = 10 + 2 * (int)1e5;
vector<ll> costs[N];

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int m;
		ll p;
		cin >> m >> p;
		costs[m].push_back(p);
	}

	ll res = 0;
	ll cou = 0;
	priority_queue<ll> act;
	for (int i = n; i >= 0; --i) {
		for (auto v : costs[i]) act.push(-v);
		cou += costs[i].size();
		costs[i].clear();
		costs[i].shrink_to_fit();

		// cou people want at least i votes, therefore we need to buy at least i+cou-n of them
		for (; i+cou-n > 0; --cou) {
			res += -act.top();
			act.pop();
		}
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}