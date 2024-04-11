#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<array<int, 2>> ch; ch.push_back({});
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		int v = 0;
		for (int i = K - 1; i >= 0; --i) {
			int c = a >> i & 1;
			if (!ch[v][c]) {
				ch[v][c] = ch.size();
				ch.push_back({});
			}
			v = ch[v][c];
		}
	}

	int V = int(ch.size());
	vector<vector<int>> lo(V);
	vector<vector<int>> hi(V);
	vector<vector<int>> diff(V);
	auto dfs = [&](auto self, int v, int k) -> void {
		if (k == -1) {
			lo[v] = {0};
			hi[v] = {0};
			diff[v] = {1 << K};
			return;
		}
		for (int c = 0; c < 2; ++c) {
			if (ch[v][c]) self(self, ch[v][c], k - 1);
		}
		lo[v].assign(1 << (k + 1), 1 << K);
		hi[v].assign(1 << (k + 1), -1);
		diff[v].assign(1 << (k + 1), 1 << K);
		for (int i = 0; i < (1 << k+1); ++i) {
			int cc = i >> k & 1;
			int ni = i & ((1 << k) - 1);
			for (int c = 0; c < 2; ++c) if (ch[v][c]) {
				lo[v][i] = min(lo[v][i], lo[ch[v][c]][ni] | ((c ^ cc) << k));
				hi[v][i] = max(hi[v][i], hi[ch[v][c]][ni] | ((c ^ cc) << k));
				diff[v][i] = min(diff[v][i], diff[ch[v][c]][ni]);
			}
			if (ch[v][0] && ch[v][1]) {
				int l = ch[v][cc];
				int r = ch[v][cc ^ 1];
				diff[v][i] = min(diff[v][i], (1 << k) + lo[r][ni] - hi[l][ni]);
			}
		}
	};
	dfs(dfs, 0, K - 1);
	for (int a : diff[0]) {
		cout << a << '\n';
	}
	return 0;
}