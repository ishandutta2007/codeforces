#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct ITV {
	ll ans;
	int lv, rv;
	int lc, rc;
	bool full = 0;
};

ITV mergeITV(ITV a, ITV b) {
	ITV res;
	res.ans = a.ans + b.ans;
	res.lv = a.lv;
	res.rv = b.rv;
	if (a.rv > b.lv) {
		res.lc = a.lc;
		res.rc = b.rc;
		res.full = 0;
	} else {
		res.ans += (ll)a.rc * b.lc;
		res.lc = (a.full ? a.lc + b.lc : a.lc);
		res.rc = (b.full ? a.rc + b.rc : b.rc);
		res.full = (a.full && b.full);
	}
	return res;
}

ITV makeITV(int v) {
	ITV res;
	res.ans = 1;
	res.lv = v;
	res.rv = v;
	res.lc = 1;
	res.rc = 1;
	res.full = 1;
	return res;
}

class SegTree {
	private:
		vector<ITV> seg;
		int h = 1;

		ITV recGet(int a, int b, int i, int ia, int ib) {
			if (a <= ia && ib <= b) return seg[i];
			int im = (ia + ib) >> 1;
			if (im <= a) return recGet(a, b, 2*i+1, im, ib);
			if (b <= im) return recGet(a, b, 2*i, ia, im);
			return mergeITV(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h);
		}
		void setv(int i, int v) {
			seg[i + h] = makeITV(v);
			for (i = ((i + h) >> 1); i > 0; i >>= 1) seg[i] = mergeITV(seg[2*i], seg[2*i+1]);
		}
		ll calc(int a, int b) {
			ITV res = recGet(a, b+1, 1, 0, h);
			return res.ans;
		}
};


void solve() {
	int n, q;
	cin >> n >> q;

	SegTree seg(n);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		seg.setv(i, v);
	}
	for (int qi = 0; qi < q; ++qi) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			seg.setv(x-1, y);
		} else {
			cout << seg.calc(x-1, y-1) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}