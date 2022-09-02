#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = (int)1e9 + 7;

// Segment tree for range minimum, count of minimum and range addition.
class SegTree {
	private:
		struct Seg {
			int minv, cou;
			bool lz, rz;
		};
		static Seg inc(int x, Seg s) {
			s.minv += x;
			return s;
		}
		static Seg combine(Seg le, Seg ri) {
			if (le.minv < ri.minv) {
				if (! le.rz) ++le.cou;
				le.rz = 1;
				return le;
			} else if (le.minv > ri.minv) {
				ri.lz = 1;
				return ri;
			} else {
				le.cou += ri.cou;
				if (!le.rz && ri.lz) ++le.cou;
				le.rz = ri.rz;
				return le;
			}
		}

		vector<Seg> seg;
		vector<int> tag;
		int h = 1;

		void apply(int i, int v){
			seg[i] = inc(v, seg[i]);
			if (i < h) tag[i] += v;
		}
		void recApply(int a, int b, int v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = inc(tag[i], combine(seg[2*i], seg[2*i+1]));
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h);
			tag.resize(h, 0);
		}
		int get(int a, int b) const {
			return seg[1].cou;
		}
		void add(int a, int b, int v) {
			if (a <= b) recApply(a, b+1, v, 1, 0, h);
		}

		void print() {
			for (int i = 1; i < 2*h; ++i) {
				cerr << i << ": " << seg[i].minv;
				if (i < h) cerr << " + " << tag[i] << ",";
				cerr << " " << seg[i].cou << ' ' << seg[i].lz << ' ' << seg[i].rz << '\n';
			}
		}
};

int bins(const vector<int>& vec, int val) {
	int low = 0;
	int high = (int)vec.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < val) low = mid + 1;
		else high = mid;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		vector<int> comp;
		vector<pair<int, int>> itvs(n);
		for (auto& pr : itvs) {
			cin >> pr.first >> pr.second;

			pr.first = 2 * pr.first;
			pr.second = 2 * pr.second + 1;
			comp.push_back(pr.first);
			comp.push_back(pr.second);
		}
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for (auto& pr : itvs) {
			pr.first = bins(comp, pr.first);
			pr.second = bins(comp, pr.second);
		}
		int m = comp.size();

		SegTree seg(m);
		for (auto& pr : itvs) seg.add(pr.first + 1, pr.second, 1);

		int res = 0;
		for (auto& pr : itvs) {
			seg.add(pr.first + 1, pr.second, -1);
			res = max(res, seg.get(0, m-1));
			seg.add(pr.first + 1, pr.second, 1);
		}

		cout << res << '\n';
	}
}