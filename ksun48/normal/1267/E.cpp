#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> results(N, vector<int>(M));

	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			cin >> results[i][j];
		}
	}

	vector<int> ans(M);
	iota(ans.begin(), ans.end(), 0);

	for (int i = 0; i < N-1; i++) {
		vector<pair<int, int>> diffs;
		for (int j = 0; j < M; j++) {
			diffs.push_back({results[i][j] - results[N-1][j], j});
		}
		sort(diffs.begin(), diffs.end());
		int v = 0;
		while (!diffs.empty() && v + diffs.back().first >= 0) {
			v += diffs.back().first;
			diffs.pop_back();
		}
		vector<int> cnd;
		for (auto it : diffs) cnd.push_back(it.second);
		if (cnd.size() < ans.size()) ans = cnd;
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < int(ans.size()); i++) {
		cout << ans[i]+1 << " \n"[i+1==int(ans.size())];
	}

	return 0;
}