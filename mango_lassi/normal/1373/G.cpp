#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

// Segment tree for range minimum and addition.
class SegTree {
	private:
		const ll NEUT = 4 * (ll)1e18; 
		vector<ll> seg, tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] += v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		ll combine(ll a, ll b) { return min(a, b); }

		ll recGet(int a, int b, int i, int ia, int ib) {
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
			seg.resize(2*h, 0);
			tag.resize(h, 0);
		}
		ll rangeMin(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k, q;
	cin >> n >> k >> q;

	// First move everything to special column, then declump
	// ans = max_{i : cou_after_i > 0}(i + cou_after_i)
	// -> range-add range-max segment tree!

	SegTree seg(2*n);
	for (int i = 0; i < 2*n; ++i) seg.rangeAdd(i, i, -i);

	multiset<pair<int, int>> acts;
	multiset<int> inds;
	
	for (int qi = 0; qi < q; ++qi) {
		int x, y;
		cin >> x >> y;
		
		int ry = y-1 + abs(x - k);

		auto it = acts.find(make_pair(x, y));
		if (it != acts.end()) {
			acts.erase(it);
			auto it2 = inds.find(ry);
			inds.erase(it2);

			seg.rangeAdd(0, ry, 1);
		} else {
			acts.insert(make_pair(x, y));
			inds.insert(ry);
			seg.rangeAdd(0, ry, -1);
		}

		if (inds.empty()) cout << 0 << '\n';
		else {
			auto it3 = inds.end();
			--it3;
			int max_y = *it3;
			
			int off = -seg.rangeMin(0, max_y);

			// cerr << max_y << ' ' << off << '\n';
			cout << max(0, off - n) << '\n';
		}
	}
}