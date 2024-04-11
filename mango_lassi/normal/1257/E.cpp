#include <iostream>
#include <vector>
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
		int recFind(int a, int b, ll v, int i, int ia, int ib) {
			if (seg[i] > v) return b;
			if (b <= ia || ib <= a) return b;
			if (ib == ia + 1) return ia;

			push(i);
			int im = (ia + ib) >> 1;
			int off = recFind(a, b, v, 2*i, ia, im);
			if (off < b) return off;
			else return recFind(a, b, v, 2*i+1, im, ib);
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, 0);
			tag.resize(h, 0);
		}
		ll rangeMin(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeAdd(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
		int findNext(int a, int b, ll v) { return recFind(a, b+1, v, 1, 0, h); }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	int n = k1 + k2 + k3;

	vector<int> v1(k1), v2(k2), v3(k3);
	for (int i = 0; i < k1; ++i) cin >> v1[i];
	for (int i = 0; i < k2; ++i) cin >> v2[i];
	for (int i = 0; i < k3; ++i) cin >> v3[i];

	vector<int> inv(n);
	for (auto v : v1) inv[v-1] = 1;
	for (auto v : v2) inv[v-1] = 2;
	for (auto v : v3) inv[v-1] = 3;

	SegTree seg(n+1);
	seg.rangeAdd(0, n, k3);
	for (int i = 1; i <= n; ++i) {
		if (inv[n-i] == 3) seg.rangeAdd(i, n, -1);
		else if (inv[n-i] == 2) seg.rangeAdd(i, n, 1);
	}

	ll cur = k1;
	ll res = n;
	for (int x = 0; x <= n; ++x) {
		ll off = cur + seg.rangeMin(0, n - x);
		res = min(res, off);

		if (x < n) {
			if (inv[x] != 1) {
				++cur;
				if (inv[x] == 3) seg.rangeAdd(0, n, -1); // k3 decreases by 1
			} else {
				--cur; // one more item we don't need to send away
			}
		}
	}
	cout << res << '\n';
}