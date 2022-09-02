#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> vals(n);
	for (int i = 0; i < n; ++i) {
		cin >> vals[i].first;
		vals[i].second = i;
	}
	sort(vals.begin(), vals.end());
	vector<pair<pair<int, int>, pair<int, int>>> segs;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while(j+1 < n && vals[j+1].first == vals[i].first) ++j;
		if (j > i) {
			segs.push_back({{vals[i].second, vals[j-1].second}, {vals[i+1].second, vals[j].second}});
			i = j;
		}
	}
	sort(segs.begin(), segs.end());
	int m = segs.size();

	if (m == 0) {
		cout << 0 << '\n';
	} else {
		int res = n;
		for (int a = 0; a <= m; ++a) {
			int x = n;
			int y = -1;
			for (int b = 0; b < a; ++b) {
				x = min(x, segs[b].second.first);
				y = max(y, segs[b].second.second);
			}
			for (int b = a; b < m; ++b) {
				x = min(x, segs[b].first.first);
				y = max(y, segs[b].first.second);
			}
			int len = max(0, y-x+1);
			res = min(res, len);
		}
		cout << res << '\n';
	}
}