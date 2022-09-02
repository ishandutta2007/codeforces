#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
using ll = long long;

template<class T>
struct SegTree {
	vector<T> seg, add;
	int h = 1;

	void apply(int i, T v) {
		seg[i] += v;
		if (i < h) add[i] += v;
	}
	void push(int i) {
		if (i < h && add[i]) {
			apply(2*i, add[i]);
			apply(2*i+1, add[i]);
			add[i] = 0;
		}
	}
	void update(int i) {
		seg[i] = max(seg[2*i], seg[2*i+1]);
	}

	SegTree(int n) {
		while(h < n) h *= 2;
		seg.resize(2*h, 0);
		add.resize(h, 0);
	}
	T recRangeMax(int a, int b, int i, int ia, int ib) {
		push(i);
		if (ib < a || b < ia) return 0;
		if (a <= ia && ib <= b) return seg[i];
		else {
			int mid = (ia + ib) >> 1;
			T res = 0;
			res = max(res, recRangeMax(a, b, 2*i, ia, mid));
			res = max(res, recRangeMax(a, b, 2*i+1, mid+1, ib));
			return res;
		}
	}
	void recRangeAdd(int a, int b, T v, int i, int ia, int ib) {
		push(i);
		if (ib < a || b < ia) return;
		if (a <= ia && ib <= b) apply(i, v);
		else {
			int mid = (ia + ib) >> 1;
			recRangeAdd(a, b, v, 2*i, ia, mid);
			recRangeAdd(a, b, v, 2*i+1, mid+1, ib);
			update(i);
		}
	}
	T rangeMax(int a, int b) {
		return recRangeMax(a, b, 1, 0, h-1);
	}
	void rangeAdd(int a, int b, T v) {
		recRangeAdd(a, b, v, 1, 0, h-1);
	}
};

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
	vector<T> coll = vec;
	sort(coll.begin(), coll.end());
	coll.erase(unique(coll.begin(), coll.end()), coll.end());

	vector<int> res(vec.size());
	for (int i = 0; i < vec.size(); ++i) res[i] = bins(coll, vec[i]);
	return {res, coll};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	r = 2*r; // r from radius to diameter

	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pts[i] = {x+y, x-y};
	}
	sort(pts.begin(), pts.end());
	// for (auto pr : pts) cerr << "{" << pr.first << ", " << pr.second << "}, "; cerr << '\n';

	vector<pair<int, int>> evs;
	vector<int> ys(n);
	for (int i = 0; i < n; ++i) {
		int x = pts[i].first;
		evs.push_back({x, i+1});
		evs.push_back({x+r+1, -(i+1)});
		ys[i] = pts[i].second;
	}
	sort(evs.begin(), evs.end());

	vector<int> ys_inds, comp_ys;
	tie(ys_inds, comp_ys) = compress(ys);

	int m = comp_ys.size();
	SegTree<ll> seg(m);

	ll res = 0;
	for (auto ev : evs) {
		int i = ev.second;
		int v;
		if (i < 0) {
			v = -1;
			i = (-i) - 1;
		} else {
			v = 1;
			i = i - 1;
		}
		int b = ys_inds[i];
		int a = bins(comp_ys, ys[i] - r);

		// cout << "rangeAdd(" << a << ' ' << b << ' ' << v << ")\n";

		seg.rangeAdd(a, b, v);
		res = max(res, seg.rangeMax(0, m-1));
	}
	cout << res << '\n';
}