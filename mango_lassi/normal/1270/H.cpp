#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <vector>
using namespace std;

class SegTree {
	private:
		const int INF = 2 * (int)1e9; 
		vector<pair<int, int>> seg;
		vector<int> tag;
		int h = 1;

		static pair<int, int> combine(int x, const pair<int, int>& a, const pair<int, int>& b) {
			auto res = min(a, b);
			res.first += x;
			if (a.first == b.first) res.second += max(a, b).second;
			return res;
		}
		void apply(int i, int v) {
			seg[i].first += v;
			if (i < h) tag[i] += v;
		}
		void recApply(int a, int b, int v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = combine(tag[i], seg[2*i], seg[2*i+1]);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, {0, 0});
			tag.resize(h, 0);
			for (int i = 0; i < n; ++i) seg[i+h].second = 1;
			for (int i = h-1; i > 0; --i) seg[i].second = seg[2*i].second + seg[2*i+1].second;
		}
		void add(int a, int b, int v) { recApply(a, b+1, v, 1, 0, h); }
		pair<int, int> get() const { return seg[1]; }
};

class RangeMin {
	private:
		const int INF = 2 * (int)1e9;
		vector<int> seg;
		int n;

		int recf(int a, int v) const {
			while(a < n) a = 2*a + (seg[2*a] > v);
			return a - n;
		}
	public:	
		RangeMin(int nn) : n(nn), seg(2*nn) {}

		// Returns smallest i >= a s.t. val[i] <= v, or n if there is none
		int search(int a, int v) const {
			int b = 2*n, r = 2*n;
			for (a += n; a < b; a=(a+1)/2, b /= 2) {
				if ((a & 1) && seg[a] <= v) return recf(a, v);
				if ((b & 1) && seg[b-1] <= v) r = b-1;
			}
			return recf(r, v);
		}
		void set(int i, int v) {
			seg[i + n] = v;
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};

class Solver {
	private:
		const int INF = 2 * (int)1e9;
		RangeMin mins, maxs;
		SegTree seg;
		vector<int> itv_min, itv_max;
		vector<pair<int, int>> itv_pre;
		int n, h;

		void update(int a, bool q) {
			int i = a+h;
			for (int k = 1; i > 1; k *= 2) {
				i /= 2;
				int left_min = itv_min[2*i];
				int right_max = itv_max[2*i+1];
				itv_min[i] = min(left_min, itv_min[2*i+1]);
				itv_max[i] = max(itv_max[2*i], right_max);

				if (a & k) {
					a -= k;
					if (q) return;
				}
				int m = a+k;
				int b = min(m+k, n);
				if (m < n) {
					int le = mins.search(a, right_max);
					int ri = (n-1) - maxs.search((n-1)-(b-1), -left_min);
					seg.add(itv_pre[i].first + 1, itv_pre[i].second, -1);
					itv_pre[i] = {le, ri};
					seg.add(itv_pre[i].first + 1, itv_pre[i].second, 1);
				}
			}
		}
	public:
		Solver(const vector<int>& as) : n(as.size()), mins(as.size()), maxs(as.size()), seg(as.size()) {
			for (int i = 0; i < n; ++i) {
				mins.set(i, as[i]);
				maxs.set(n-1-i, -as[i]);
			}

			for (h = 1; h < n;) h <<= 1;
			itv_min.resize(2*h, INF);
			itv_max.resize(2*h, -INF);
			itv_pre.resize(h, {-1, -1});

			for (int i = n-1; i >= 0; --i) {
				itv_min[i+h] = as[i];
				itv_max[i+h] = as[i];
				update(i, 1);
			}
		}
		int set(int i, int v) {
			mins.set(i, v);
			maxs.set(n-1-i, -v);
			itv_min[i+h] = v;
			itv_max[i+h] = v;
			update(i, 0);
			return seg.get().second;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// O((n + q log n) log n) solution
	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];
	Solver solver(as);
	
	for (int i = 0; i < q; ++i) {
		int x, v;
		cin >> x >> v;
		int res = solver.set(x-1, v);
		cout << res << '\n';
	}
}