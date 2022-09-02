#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> query(int r, int n) {
	cout << "? " << r+1 << endl;
	vector<int> res(n);
	for (int& d : res) cin >> d;
	return res;
}
void answer(const vector<pair<int, int>>& res) {
	cout << "!" << endl;
	for (auto pr : res) {
		cout << pr.first + 1 << ' ' << pr.second + 1 << endl;
	}
}

void solve() {
	int n;
	cin >> n;

	// Ask at node
	// Then, either ask at all nodes at odd depth, or all nodes at even depth, whichever there are less of
	// -> 1 + floor((n-1) / 2) = floor((n+1)/2) = ceil(n/2) ops

	auto dist = query(0, n);
	
	int cou0 = 0, cou1 = 0;
	vector<pair<int, int>> res;
	for (int i = 1; i < n; ++i) {
		if (dist[i] & 1) ++cou1;
		else ++cou0;

		if (dist[i] == 1) res.emplace_back(0, i);
	}

	for (int i = 1; i < n; ++i) {
		if (dist[i] & 1) {
			if (cou1 > cou0) continue;
		} else {
			if (cou0 >= cou1) continue;
		}

		auto adj = query(i, n);
		for (int t = 0; t < n; ++t) {
			if (adj[t] == 1) res.emplace_back(min(i, t), max(i, t));
		}
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	answer(res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}