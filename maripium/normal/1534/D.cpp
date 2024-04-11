#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N; cin >> N;
	vector<vector<int>> dists(N);
	auto Ask = [&](int r) {
		if (dists[r].size()) return;
		cout << "? " << r + 1 << '\n';
		cout << flush;
		dists[r].resize(N);
		for (int &a : dists[r]) cin >> a;
		return;
	};
	Ask(0);
	array<vector<int>, 2> cols{};
	for (int i = 0; i < N; ++i) cols[dists[0][i] & 1].push_back(i);
	int c = cols[1].size() < cols[0].size();
	vector<pair<int, int>> edges;
	for (int v : cols[c]) {
		Ask(v);
		for (int u = 0; u < N; ++u) if (dists[v][u] == 1) {
			edges.emplace_back(v, u);
		}
	}
	cout << "!\n";
	for (auto [v, u] : edges) {
		cout << v + 1 << ' ' << u + 1 << '\n';
	}
	cout << flush;
	return 0;
}