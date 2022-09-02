#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> comp(int x0, int x1, const vector<vector<ll>>& as) {
	int le = 0, ri = 0;
	for (int y = 0; y < as.size(); ++y) {
		if (as[y][x0] < as[y][x1]) ++le;
		if (as[y][x1] < as[y][x0]) ++ri;
	}
	return {le, ri};
}

void solve() {
	int h, w;
	cin >> h >> w;

	vector<vector<ll>> as(h, vector<ll>(w, 0));
	for (auto& vec : as) {
		for (ll& a : vec) cin >> a;
	}

	int f = 1, p = 0;
	for (; f < w; ++f) {
		auto cmp = comp(f - 1, f, as);
		if (cmp.second > 0) break;
		if (cmp.first > 0) p = f;
	}

	if (f == w) {
		cout << 1 << ' ' << 1 << '\n';
	} else {
		// We need to switch this column to the minimum in the suffix
		int j = f;
		for (int i = f + 1; i < w; ++i) {
			auto cmp = comp(j, i, as);
			if (cmp.first == 0) j = i;
			// if (cmp.second > 0) j = i;
		}
		for (int y = 0; y < h; ++y) swap(as[y][p], as[y][j]);
		
		bool works = 1;
		for (int x = 0; x + 1 < w; ++x) {
			auto cmp = comp(x, x + 1, as);
			if (cmp.second > 0) works = 0;
		}

		if (works) {
			cout << p + 1 << ' ' << j + 1 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}