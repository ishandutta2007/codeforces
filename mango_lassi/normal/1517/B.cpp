#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> res(n, vector<int>(m, -1));
	vector<pair<ll, pair<int, int>>>  vals(n * m);
	vector<vector<ll>> lens(n, vector<ll>(m, 0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> lens[i][j];
			vals[m*i + j].first = lens[i][j];
			vals[m*i + j].second = {i, j};
		}
	}
	sort(vals.begin(), vals.end());

	for (int i = 0; i < m; ++i) {
		res[vals[i].second.first][i] = vals[i].second.second;
	}

	for (int i = 0; i < n; ++i) {
		vector<bool> used(m, 0);
		for (int j = 0; j < m; ++j) {
			if (res[i][j] != -1) used[res[i][j]] = 1;
		}
		for (int j = 0; j < m; ++j) {
			if (res[i][j] == -1) {
				while(used.back()) used.pop_back();
				res[i][j] = (int)used.size() - 1;
				used.pop_back();
			}
			cout << lens[i][res[i][j]] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}