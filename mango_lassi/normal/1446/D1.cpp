#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (int)1e9 + 7;

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

int nxt(int x, int dir, const vector<int>& xs) {
	int j = bins(xs, x+1);
	if (dir == 1) {
		if (j == xs.size()) return xs.size();
		else return j;
	} else {
		if (j == 0) return -1;
		else return j-1;
	}
}

vector<int> build(int n, int max_abs, int i, int t, int dir, const vector<int>& xs, const vector<int>& ys) {
	vector<int> res(2*max_abs + 1, -INF);
	res[max_abs] = 0;
	int sx = xs[i];

	if (dir == 1) {
		int x = xs[i];
		int j = nxt(x, 1, ys);
		int cur = max_abs;
		while(0 <= cur && cur <= 2*max_abs) {
			res[cur] = x - sx;

			if (i > t && j == ys.size()) {
				x = n-1;
				break;
			} else {
				bool move_x = 0;
				if (i <= t && j < ys.size()) {
					if (xs[i] < ys[j]) move_x = 1;
				} else if (i <= t) {
					move_x = 1;
				}

				if (move_x) {
					--cur;
					x = xs[i];
					++i;
				} else {
					x = ys[j] - 1;
					res[cur] = x - sx;
					++cur;
					++x;
					++j;
				}
			}
		}
		if (0 <= cur && cur <= 2*max_abs) res[cur] = x - sx;
	} else {
		int x = xs[i];
		int j = nxt(x, -1, ys);
		int cur = max_abs;
		while(0 <= cur && cur <= 2*max_abs) {
			res[cur] = sx - x;

			if (i < t && j == -1) {
				x = 0;
				break;
			} else {
				bool move_x = 0;
				if (i >= t && j >= 0) {
					if (xs[i] > ys[j]) move_x = 1;
				} else if (i >= t) {
					move_x = 1;
				}

				if (move_x) {
					--cur;
					x = xs[i];
					--i;
				} else {
					x = ys[j] + 1;
					res[cur] = sx - x;
					++cur;
					--x;
					--j;
				}
			}
		}
		if (0 <= cur && cur <= 2*max_abs) res[cur] = sx - x;
	}

	for (int i = 1; i <= 2*max_abs; ++i) res[i] = max(res[i-1], res[i]);
	return res;
}

int solve(int n, int ia, int ib, const vector<int>& xs, const vector<int>& ys) {
	if (ia > ib) return 0;
	int cou = ib - ia + 1;
	int mid = (ia + ib) >> 1;

	// Maximum length interval with sum <= 0 that has to include xs[mid]
	auto le = build(n, cou, mid, ia, -1, xs, ys);
	auto ri = build(n, cou, mid, ib, 1, xs, ys);

	/*
	cerr << "solve(" << n << ' ' << ia << ' ' << ib << ' ' << mid << " (";
	for (auto v : xs) cerr << v << ' '; cerr << "), (";
	for (auto v : ys) cerr << v << ' '; cerr << "))\n";

	for (auto v : le) cerr << v << ' '; cerr << '\n';
	for (auto v : ri) cerr << v << ' '; cerr << '\n';
	*/

	int res = 0;
	for (int j = 0; j <= 2*cou - 1; ++j) {
		res = max(res, le[j] + ri[(2*cou - 1) - j] + 1);
		// cerr << j << ' ' << (2*cou - 1) - j << ": " << le[j] << ' ' << ri[(2*cou - 1) - j] << ' ' << 1 << '\n';
	}
	res = max(res, solve(n, ia, mid - 1, xs, ys));
	res = max(res, solve(n, mid + 1, ib, xs, ys));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Look at entire array. Look at its unique most frequent value, say x
	// We must remove an occurrence of that value
	// We must remove enough occurrences, that the second most frequent value occurs as many times
	// -> Then, the most frequent value is not unique!

	// Loop what the second most frequent value, say y, is
	// Then, our array has 1s (at positions where x is) and -1s (at positions where y is)
	// We want to find the longest subarray with sum <= 0
	
	// Assume first that subarray crosses the middle
	// Take possible sums for left and right side, up to #-1's, then solve
	// Recursively solve for left side, right side

	vector<int> vals(n);
	for (int& v : vals) cin >> v;

	vector<int> comp = vals;
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	int m = comp.size();
	vector<vector<int>> xs(m);
	for (int i = 0; i < n; ++i) {
		vals[i] = bins(comp, vals[i]);
		xs[vals[i]].push_back(i);
	}
	
	int j = 0;
	bool uniq = 1;
	for (int i = 1; i < m; ++i) {
		if (xs[i].size() > xs[j].size()) {
			j = i;
			uniq = 1;
		} else if (xs[i].size() == xs[j].size()) {
			uniq = 0;
		}
	}

	if (! uniq) {
		cout << n << '\n';
	} else {
		vector<int> ys = xs[j];
		swap(xs[j], xs[m-1]);

		/*
		cerr << m << '\n';
		for (auto vec : xs) {
			for (auto i : vec) cerr << i << ' '; cerr << '\n';
		}
		*/

		int res = 0;
		for (int i = 0; i < m-1; ++i) res = max(res, solve(n, 0, (int)xs[i].size() - 1, xs[i], ys));
		cout << res << '\n';
	}
}