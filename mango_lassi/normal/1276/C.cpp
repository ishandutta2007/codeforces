#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// mx[x]: maximum divisor at most sqrt(x)
	vector<int> mx(n+1, 1);
	for (int v = 2; v <= n; ++v) {
		for (ll t = (ll)v*v; t <= n; t += v) {
			mx[t] = max(mx[t], v);
		}
	}

	vector<int> vals(n);
	for (int& v : vals) cin >> v;
	sort(vals.begin(), vals.end());

	vector<pair<int, int>> counts = {{0, vals[0]}};
	for (auto v : vals) {
		if (v == counts.back().second) ++counts.back().first;
		else counts.push_back({1, v});
	}
	sort(counts.begin(), counts.end());
	reverse(counts.begin(), counts.end());

	// Can take m iff can take m s.t. no number occurs more than mx[m] times
	int cur = 0;
	int act = 1;
	int mx_cou = counts[0].first;
	for (int m = n; m >= 1; --m) {
		if (mx[m] >= mx_cou) {
			sort(counts.begin(), counts.end());
			reverse(counts.begin(), counts.end());

			int h = mx[m];
			int w = m / mx[m];
			vector<vector<int>> res(h);
			for (int y = 0; y < h; ++y) res[y].resize(w, -1);

			cout << m << '\n';
			cout << h << ' ' << w << '\n';

			int x = 0, y = 0;
			for (int j = 0; j < counts.size(); ++j) {
				int cou = counts[j].first;
				int val = counts[j].second;
				for (; cou > 0; --cou) {
					res[y][x] = val;
					x = (x + 1) % w;
					y = (y + 1) % h;
					if (y == 0) {
						x = (x - h + 1) % w;
						if (x < 0) x += w;
					}
				}
			}

			for (y = 0; y < h; ++y) {
				for (x = 0; x < w; ++x) cout << res[y][x] << ' '; cout << '\n';
			}

			break;
		} else {
			--counts[cur].first;
			if (cur+1 < act) ++cur;
			else if (act < counts.size() && counts[act].first == mx_cou) {
				++cur;
				++act;
			} else {
				cur = 0;
				--mx_cou;
			}
		}
	}
}