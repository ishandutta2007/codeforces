#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10;

// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

pair<int, array<int, N>> solve(int i, array<int, N> cur, const vector<vector<int>>& as, const vector<array<int, N>>& bans) {
	if (i == as.size()) {
		pair<int, array<int, N>> res = {0, cur};
		for (int j = 0; j < as.size(); ++j) res.first += as[j][cur[j]];
		return res;
	} else {
		pair<int, array<int, N>> res;
		res.first = -1;

		for (int j = (int)as[i].size() - 1; j >= 0; --j) {
			cur[i] = j;
			int ind = bins(bans, cur);

			bool match = 1;
			if (ind < bans.size()) {
				for (int x = 0; x <= i; ++x) {
					if (bans[ind][x] != cur[x]) match = 0;
				}
			} else match = 0;

			if (match && i + 1 == as.size()) continue;

			res = max(res, solve(i+1, cur, as, bans));
			cur[i] = 0;

			if (! match) return res;
		}
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> as(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		as[i].resize(c);
		for (int& v : as[i]) cin >> v;
	}
	
	array<int, N> cur;
	for (int j = 0; j < N; ++j) cur[j] = 0;

	int m;
	cin >> m;
	vector<array<int, N>> bans(m, cur);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> bans[i][j];
			--bans[i][j];
		}
	}
	sort(bans.begin(), bans.end());

	array<int, N> res = solve(0, cur, as, bans).second;
	for (int i = 0; i < n; ++i) cout << res[i] + 1 << ' '; cout << '\n';
}