#include <bits/stdc++.h>
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

const ll INF = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> hs(n);
	for (int& h : hs) cin >> h;

	vector<ll> bs(n);
	for (ll& b : bs) cin >> b;

	vector<int> sta = {-1};
	SegTree dp(n+1), dp_sta(n+1);
	dp_sta.rangeAdd(0, 0, INF);

	for (int i = 0; i < n; ++i) {
		while(sta.back() != -1 && hs[sta.back()] > hs[i]) {
			dp_sta.rangeAdd(sta.back() + 1, sta.back() + 1, INF);
			sta.pop_back();
		}
		ll off = -dp.rangeMin(sta.back() + 1, i) + bs[i];
		ll off2 = -dp_sta.rangeMin(0, i);
		ll val = max(off, off2);

		dp.rangeAdd(i+1, i+1, -val);
		dp_sta.rangeAdd(i+1, i+1, -val);
		sta.push_back(i);
	}
	cout << -dp.rangeMin(n, n) << '\n';
}