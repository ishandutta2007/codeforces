#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// Segment tree for range maximum and addition.
class SegTree {
	private:
		const pair<ll, int> NEUT = {-4 * (ll)1e18, -1};
		vector<pair<ll, int>> seg;
		vector<ll> tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i].first += v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		pair<ll, int> combine(pair<ll, int> a, pair<ll, int> b) { return max(a, b); }

		pair<ll, int> recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT;
			if (a <= ia && ib <= b) return seg[i];
			push(i);
			int im = (ia + ib) >> 1;
			return combine(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
		void recApply(int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				push(i);
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = combine(seg[2*i], seg[2*i+1]);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h);
			for (int i = 0; i < h; ++i) seg[i+h] = {0, i};
			for (int i = h-1; i > 0; --i) seg[i] = combine(seg[2*i], seg[2*i+1]);
			tag.resize(h, 0);
		}
		pair<ll, int> rangeMax(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Read input
	vector<int> ys(n);
	vector<tuple<int, int, int>> points(n);
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		if (x > y) swap(x, y);
		points[i] = tie(x, y, c);
		ys[i] = y;
	}
	sort(points.begin(), points.end());

	// do coordinate compression
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	int m = ys.size();
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		tie(x, y, c) = points[i];

		int low = 0;
		int high = (int)ys.size() - 1;
		while(low != high) {
			int mid = (low + high) >> 1;
			if (ys[mid] < y) low = mid + 1;
			else high = mid;
		}
		points[i] = tie(x, low, c);
	}
	
	// Init segment tree
	SegTree seg(m);
	for (int i = 0; i < n; ++i) {
		seg.rangeAdd(i, i, -ys[i]);
	}
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		tie(x, y, c) = points[i];
		seg.rangeAdd(y, m-1, c);
	}

	// Solve
	int j = 0;
	ll res = 0;
	pair<int, int> loc = {(int)1e9 + 1, (int)1e9 + 1};
	for (int i = 0; i < n;) {
		int x = get<0>(points[i]);
		while(j < m && ys[j] < x) ++j;

		pair<ll, int> off = seg.rangeMax(j, m-1);
		off.first += x;
		if (off.first > res) {
			res = off.first;
			loc = {x, ys[off.second]};
		}

		for (; i < n && get<0>(points[i]) == x; ++i) {
			int y = get<1>(points[i]);
			int c = get<2>(points[i]);
			seg.rangeAdd(y, m-1, -c);
		}
	}

	cout << res << '\n';
	cout << loc.first << ' ' << loc.first << ' ' << loc.second << ' ' << loc.second << '\n';
}