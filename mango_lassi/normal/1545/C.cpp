#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

void dfs(int i, vector<int>& state, const vector<vector<int>>& g) {
	for (int t : g[i]) {
		if (state[t] == 0) {
			state[t] = -state[i];
			dfs(t, state, g);
		}
	}
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> perms(2*n, vector<int>(n));
	for (int i = 0; i < 2*n; ++i) {
		for (int& v : perms[i]) {
			cin >> v;
			--v;
		}
	}

	vector<vector<int>> cou(n, vector<int>(n, 0));
	vector<vector<vector<int>>> apps(n, vector<vector<int>>(n));

	// Find rows that must be used and that cannot be used
	vector<int> que;
	vector<int> state(2*n, 0);
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < 2*n; ++i) {
			apps[j][perms[i][j]].push_back(i);
			++cou[j][perms[i][j]];
		}
		for (int i = 0; i < 2*n; ++i) {
			if (cou[j][perms[i][j]] == 1) {
				state[i] = 1;
				que.push_back(i);
			}
		}
	}
	while(! que.empty()) {
		int i = que.back();
		que.pop_back();
		for (int j = 0; j < n; ++j) {
			int c = perms[i][j];
			if (state[i] == 1) {
				for (int i2 : apps[j][c]) {
					if (i2 == i || state[i2]) continue;
					state[i2] = -1;
					que.push_back(i2);
				}
				apps[j][c].clear();
				cou[j][c] = 0;
			} else {
				--cou[j][c];
				if (cou[j][c] == 1) {
					for (int i2 : apps[j][c]) {
						if (state[i2]) continue;
						state[i2] = 1;
						que.push_back(i2);
					}
					apps[j][c].clear();
					cou[j][c] = 0;
				}
			}
		}
	}

	vector<vector<int>> g(2*n);
	for (int j = 0; j < n; ++j) {
		for (int c = 0; c < n; ++c) {
			if (cou[j][c] == 2) {
				int i = -1;
				for (int i2 : apps[j][c]) {
					if (state[i2] == 0) {
						if (i == -1) i = i2;
						else {
							g[i].push_back(i2);
							g[i2].push_back(i);
						}
					}
				}
			}
		}
	}

	ll ways = 1;
	vector<int> res;
	for (int i = 0; i < 2*n; ++i) {
		if (state[i] == 0) {
			ways = (2 * ways % MOD);
			state[i] = 1;
			dfs(i, state, g);
		}
		if (state[i] == 1) res.push_back(i);
	}

	cout << ways << '\n';
	for (int i : res) cout << i + 1 << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}