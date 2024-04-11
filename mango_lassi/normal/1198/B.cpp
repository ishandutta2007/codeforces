#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

struct SegTree {
	vector<ll> seg;
	vector<ll> tag;
	int h = 1;

	void apply(int i, ll v) {
		seg[i] = max(seg[i], v);
		if (i < h) tag[i] = max(tag[i], v);
	}
	void push(int i) {
		apply(2*i, tag[i]);
		apply(2*i+1, tag[i]);
		tag[i] = 0;
	}

	SegTree(const vector<ll>& vals) {
		int n = vals.size();
		while(h < n) h *= 2;

		seg.resize(2*h, 0);
		tag.resize(h, 0);
		for (int i = 0; i < n; ++i) apply(i+h, vals[i]);
	}

	void recSetVal(int ind, ll v, int i, int ia, int ib) {
		if (ib < ind || ind < ia) return;
		if (ia == ib) {
			seg[i] = v;
		} else {
			push(i);
			int im = (ia + ib) >> 1;
			recSetVal(ind, v, 2*i, ia, im);
			recSetVal(ind, v, 2*i+1, im+1, ib);
		}
	}
	ll recGetVal(int ind, int i, int ia, int ib) {
		if (ib < ind || ind < ia) return 0;
		if (ia == ib) {
			return seg[i];
		} else {
			push(i);
			int im = (ia + ib) >> 1;
			ll res = 0;
			res += recGetVal(ind, 2*i, ia, im);
			res += recGetVal(ind, 2*i+1, im+1, ib);
			return res;
		}
	}

	void applyMin(ll v) {
		apply(1, v);
	}
	void setVal(int ind, ll v) {
		recSetVal(ind, v, 1, 0, h-1);
	}
	ll getVal(int ind) {
		return recGetVal(ind, 1, 0, h-1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	for (int i = 0; i < n; ++i) cin >> as[i];

	SegTree seg(as);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, x;
			cin >> p >> x;
			seg.setVal(p-1, x);
		} else if (t == 2) {
			int x;
			cin >> x;
			seg.applyMin(x);
		}
	}
	for (int i = 0; i < n; ++i) cout << seg.getVal(i) << ' '; cout << '\n';
}