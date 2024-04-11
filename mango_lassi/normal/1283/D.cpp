#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	set<ll> used;
	vector<ll> xs(n);
	vector<pair<ll, int>> que;
	for (ll& x : xs) {
		cin >> x;
		used.insert(x);
		que.push_back({x-1, 1});
		que.push_back({x+1, 1});
	}

	ll res = 0;
	vector<ll> ys;
	for (int j = 0; ys.size() < m; ++j) {
		ll y = que[j].first;
		if (used.find(y) != used.end()) continue;

		int v = que[j].second;
		res += v;
		used.insert(y);
		ys.push_back(y);
		que.push_back({y-1, v+1});
		que.push_back({y+1, v+1});
	}

	cout << res << '\n';
	for (auto y : ys) cout << y << ' '; cout << '\n';
}