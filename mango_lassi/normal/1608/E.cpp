#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
		ll get(int a, int b) { return get(b) - get(a-1); }

		// Assuming prefix sums are non-decreasing, finds last i s.t. get(i) <= v
		int search(ll v) {
			int res = 0;
			for (int h = 1<<30; h; h >>= 1) {
				if ((res | h) < val.size() && val[res | h] <= v) {
					res |= h;
					v -= val[res];
				}
			}
			return res - 1;
		}
};

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

template<class T>
pair<vector<int>, vector<T>> compress(const vector<T>& vec) {
	vector<T> comp = vec;
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());

	vector<int> res(vec.size());
	for (int i = 0; i < vec.size(); ++i) res[i] = bins(comp, vec[i]);
	return {res, comp};
}

int solve(vector<pair<pair<int, int>, int>> pts) {
	int n = pts.size();
	sort(pts.begin(), pts.end());
	
	Fenwick diff_y(n), ones_y(n); // diff_y(y): ones with y' <= y minus twos with y' > y
	Fenwick diff_x(n), ones_x(n); // diff_x(y): ones with x' <= x minus twos with x' > x
	for (int i = 0; i < n; ++i) {
		if (pts[i].second == 1) {
			diff_y.add(pts[i].first.second, 1);
			ones_y.add(pts[i].first.second, 1);
			diff_x.add(pts[i].first.first, 1);
			ones_x.add(pts[i].first.first, 1);
		} else if (pts[i].second == 2) {
			diff_y.add(0, -1);
			diff_y.add(pts[i].first.second, 1);
			diff_x.add(0, -1);
			diff_x.add(pts[i].first.first, 1);
		}
	}
	/*
	cerr << 0 << ":\n\t";
	for (int j = 0; j < n; ++j) cerr << ones_x.get(j) << ' '; cerr << "\n\t";
	for (int j = 0; j < n; ++j) cerr << diff_x.get(j) << ' '; cerr << '\n';
	*/

	int zc = 0, res = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && pts[j].first.first == pts[i].first.first) {
			if (pts[j].second == 0) {
				++zc;
			} else if (pts[j].second == 1) {
				diff_y.add(pts[j].first.second, -1);
				ones_y.add(pts[j].first.second, -1);
				diff_x.add(pts[j].first.first, -1);
				ones_x.add(pts[j].first.first, -1);
			} else if (pts[j].second == 2) {
				diff_y.add(0, 1);
				diff_y.add(pts[j].first.second, -1);
				diff_x.add(0, 1);
				diff_x.add(pts[j].first.first, -1);
			}
			++j;
		}
		i = j;

		int y = diff_y.search(0);
		int oc1 = ones_y.get(y);
		int tc1 = oc1 - diff_y.get(y);
		res = max(res, min(zc, min(oc1, tc1)));
		if (y + 1 < n) {
			int oc2 = ones_y.get(y + 1);
			int tc2 = oc2 - diff_y.get(y + 1);
			res = max(res, min(zc, min(oc2, tc2)));
		}

		int x = diff_x.search(0);
		oc1 = ones_x.get(x);
		tc1 = oc1 - diff_x.get(x);
		res = max(res, min(zc, min(oc1, tc1)));
		if (x + 1 < n) {
			int oc2 = ones_x.get(x + 1);
			int tc2 = oc2 - diff_x.get(x + 1);
			res = max(res, min(zc, min(oc2, tc2)));
		}

		/*
		cerr << i << ":\n\t";
		for (int j = 0; j < n; ++j) cerr << ones_x.get(j) << ' '; cerr << "\n\t";
		for (int j = 0; j < n; ++j) cerr << diff_x.get(j) << ' '; cerr << '\n';
		*/
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> xs(n), ys(n), cs(n);
	for (int i = 0; i < n; ++i) cin >> xs[i] >> ys[i] >> cs[i];
	auto tmp_x = compress(xs);
	auto tmp_y = compress(ys);
	xs = tmp_x.first;
	ys = tmp_y.first;
	int w = tmp_x.second.size();
	int h = tmp_y.second.size();

	// for (int i = 0; i < n; ++i) cerr << cs[i] << ' '; cerr << '\n';

	/*
	cerr << "Width = " << w << ": ";
	for (int x : xs) cerr << x << ' '; cerr << '\n';
	
	cerr << "Height = " << h << ": ";
	for (int y : ys) cerr << y << ' '; cerr << '\n';
	*/

	int res = 0;
	vector<pair<pair<int, int>, int>> pts(n);
	
	for (int rot = 0; rot < 4; ++rot) {
		for (int i = 0; i < n; ++i) {
			if (rot == 0) {
				pts[i].first.first = xs[i];
				pts[i].first.second = ys[i];
			} else if (rot == 1) {
				pts[i].first.first = ys[i];
				pts[i].first.second = w-1-xs[i];
			} else if (rot == 2) {
				pts[i].first.first = w-1-xs[i];
				pts[i].first.second = h-1-ys[i];
			} else if (rot == 3) {
				pts[i].first.first = h-1-ys[i];
				pts[i].first.second = xs[i];
			}
		}
		vector<int> perm = {0, 1, 2};
		do {
			for (int i = 0; i < n; ++i) pts[i].second = perm[cs[i] - 1];
			// cerr << rot << " ; " << perm[0] << ' ' << perm[1] << ' ' << perm[2] << '\n';
			res = max(res, solve(pts));
		} while (next_permutation(perm.begin(), perm.end()));
	}
	cout << 3 * res << '\n';
}