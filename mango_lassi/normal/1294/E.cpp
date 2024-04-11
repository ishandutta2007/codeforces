#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& col, int a, int b) {
	int n = col.size();
	vector<int> ans(n, n);
	for (int i = 0; i < n; ++i) {
		if (col[i] % b != a) continue;
		int t = col[i] / b;
		int ind = (t <= i ? i-t : n + i-t);
		if (t < n) --ans[ind];
	}
	int res = n;
	for (int i = 0; i < n; ++i) res = min(res, ans[i] + i);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	vector<vector<int>> dat(w, vector<int>(h));
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			cin >> dat[x][y];
			--dat[x][y];
		}
	}
	
	int res = 0;
	for (int x = 0; x < w; ++x) {
		res += solve(dat[x], x, w);
	}
	cout << res << '\n';
}