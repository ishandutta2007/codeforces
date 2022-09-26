#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
		

	int N, M; cin >> N >> M;
	map<int, vector<int>> mx;
	map<int, vector<int>> my;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int a; cin >> a;
			mx[a].push_back(i);
			my[a].push_back(j);
		}
	}

	auto solve = [&](map<int, vector<int>> m) {
		int64_t ans = 0;
		for (auto [_, locs] : m) {
			sort(locs.begin(), locs.end());
			int cnt = 0;
			int64_t sum = 0;
			for (int v : locs) {
				ans += int64_t(v) * cnt - sum;
				cnt++;
				sum += v;
			}
		}
		return ans;
	};

	cout << solve(mx) + solve(my) << '\n';
	return 0;
}