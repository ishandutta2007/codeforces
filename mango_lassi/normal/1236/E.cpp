#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int findNext(const vector<int>& vec, int v) {
	int low = 0;
	int high = vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

// Maximum distance x can go left
vector<int> solveDir(const vector<int>& as, int n) {
	int m = as.size();
	vector<vector<int>> diags(n + m);
	for (int y = 0; y < as.size(); ++y) {
		int x = as[y];
		diags[x+y].push_back(y);
	}
	for (int i = 0; i < n + m; ++i) sort(diags[i].begin(), diags[i].end());

	vector<int> res(n, 0), path;
	for (int x = 1; x < n; ++x) {
		int cx = x;
		int cy = -1;
		vector<int> add;
		while(true) {
			int ind = findNext(diags[cx + cy], cy);
			if (ind == diags[cx + cy].size()) {
				cx = max(0, cx - (m - cy));
				res[x] = x - cx;
				break;
			}
			int ny = diags[cx + cy][ind] - 1;
			int nx = (cx - (ny - cy));

			while(! path.empty() && path.back() < ny) path.pop_back();
			if (! path.empty() && path.back() == ny) {
				res[x] = res[x-1] + 1;
				break;
			}
			add.push_back(ny);
			
			cx = nx;
			cy = ny + 1; // move along wall
		}
		while(! add.empty()) {
			path.push_back(add.back());
			add.pop_back();
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << 0 << '\n';
	} else {
		vector<int> as(m);
		for (int i = 0; i < m; ++i) {
			cin >> as[i];
			--as[i];
		}
		vector<int> le = solveDir(as, n);
		
		for (int i = 0; i < m; ++i) {
			as[i] = n-1 - as[i];
		}
		vector<int> ri = solveDir(as, n);
		reverse(ri.begin(), ri.end());

		ll res = 0;
		for (int i = 0; i < n; ++i) {
			res += le[i] + ri[i] + 1;
		}
		cout << res << '\n';
	}
}