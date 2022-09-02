#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegTree {
	private:
		const ll NEUT = 0; 
		vector<ll> seg, tag, minv;
		int h = 1;

		// Returns length of interval corresponding to position i
		ll len(int i) { return h >> (31 - __builtin_clz(i)); }

		void apply(int i, ll v) {
			seg[i] += v * len(i);
			minv[i] += v;
			if (i < h) tag[i] += v;
		}
		void push(int i) {
			if (tag[i] == 0) return;
			apply(2*i, tag[i]);
			apply(2*i+1, tag[i]);
			tag[i] = 0;
		}
		ll combine(ll a, ll b) { return a + b; }

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
				minv[i] = min(minv[2*i], minv[2*i+1]);
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, NEUT);
			minv.resize(2*h, 0);
			tag.resize(h, 0);
		}
		ll rangeSum(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }

		int findFirst(int a, ll v) {
			int i = 1, ia = 0, ib = h;
			while(i < h) {
				push(i);
				int im = (ia + ib) >> 1;
				if (im <= a || minv[2*i] > v) {
					i = 2*i+1;
					ia = im;
				} else {
					i = 2*i;
					ib = im;
				}
			}
			if (minv[i] <= v) return ia;
			else return ib;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Greedy checking works
	// Operations "set range to value" and "find next value smaller than or equal to this"

	int n, q;
	cin >> n >> q;

	SegTree seg(n);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		seg.rangeAdd(i, i, a);
	}

	for (int qi = 0; qi < q; ++qi) {
		int t, x, y;
		cin >> t >> x >> y;
		--x;

		if (t == 1) {
			while(true) {
				int a = seg.findFirst(0, y-1);
				if (a > x) break;

				ll val = seg.rangeSum(a, a);
				int b = min(x, seg.findFirst(0, val - 1) - 1);
				seg.rangeAdd(a, b, y - val);
			}
		} else {
			int res = 0;
			while(true) {
				int a = seg.findFirst(x, y);
				if (a >= n) break;

				ll val = seg.rangeSum(a, a);
				int b = min((ll)n, a + y / val);

				res += b - a;
				y -= seg.rangeSum(a, b-1);
				x = b;
			}
			cout << res << '\n';
		}
	}
}