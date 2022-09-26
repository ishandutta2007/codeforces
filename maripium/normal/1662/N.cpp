#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<pair<int, int>> locs(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int a; cin >> a;
			--a;
			locs[a] = {i, j};
		}
	}

	vector<int> row(N), col(N);
	int64_t ans = 0;
	for (auto [i, j] : locs) {
		ans += row[i] * col[j];
		row[i] ++;
		col[j] ++;
	}

	ans = int64_t(N) * (N - 1) * (N) * (N - 1) / 2 - ans;
	cout << ans << '\n';
	return 0;
}