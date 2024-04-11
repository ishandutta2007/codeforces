#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// Segment tree for range addition and range sum. It is also easy to modify:
// just change NEUT, apply, and combine to what you need, and rename rangeSum, rangeAdd
class SegTree {
	private:
		vector<ll> seg;
		int h = 1;

		ll recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return 0;
			if (a <= ia && ib <= b) return seg[i];
			int im = (ia + ib) >> 1;
			return gcd(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib));
		}
	public:
		SegTree(const vector<ll>& as) {
			int n = as.size();
			while(h < n) h *= 2;
			seg.resize(2*h, 0);
			for (int i = 0; i < n; ++i) seg[i + h] = as[i];
			for (int i = h - 1; i > 0; --i) seg[i] = gcd(seg[2*i], seg[2*i+1]);
		}
		ll rangeGcd(int a, int b) { return recGet(a, b+1, 1, 0, h); }
};


void solve() {
	int n;
	cin >> n;
	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<ll> ds(n - 1);
	for (int i = 0; i < n - 1; ++i) ds[i] = abs(as[i + 1] - as[i]);
	SegTree seg(ds);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int low = i;
		int high = n - 1;
		while(low != high) {
			int mid = (low + high + 1) >> 1;
			if (seg.rangeGcd(i, mid - 1) != 1) low = mid;
			else high = mid - 1;
		}
		res = max(res, low - i + 1);
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}