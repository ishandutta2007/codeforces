#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// returns number of elements strictly smaller than v in vec
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

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] += v;
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res += val[i];
			}
			return res;
		}
		ll get(int a, int b) { return get(b) - get(a-1); }

		// Assuming prefix sums are non-decreasing, finds last i s.t. get(i) <= v
		int search(ll v) {
			int res = 0;
			for (int h = 1<<30; h; h >>= 1) {
				if ((res | h) < val.size() && val[res | h] <= v) {
					res |= h;
					v -= val[res];
				}
			}
			return res - 1;
		}
};

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

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> as(n);
	for (int& a : as) cin >> a;
	
	// Count inversions amont A
	ll res = 0;
	vector<int> ord_a = as;
	sort(ord_a.begin(), ord_a.end());
	Fenwick fenw(n);
	for (int i = 0; i < n; ++i) {
		int ind = bins(ord_a, as[i]);
		res += fenw.get(ind + 1, n-1);
		fenw.add(ind, 1);
	}

	vector<pair<int, int>> ord_as(n);
	for (int i = 0; i < n; ++i) ord_as[i] = {as[i], i};
	sort(ord_as.begin(), ord_as.end());

	vector<int> bs(m);
	for (int& b : bs) cin >> b;
	sort(bs.begin(), bs.end());
	
	SegTree seg(n + 1);
	for (int i = 0; i < n; ++i) seg.rangeAdd(i + 1, n, 1);

	int ind0 = 0, ind1 = 0;
	for (int b : bs) {
		while(ind0 < n && ord_as[ind0].first <= b) {
			int i = ord_as[ind0].second;
			seg.rangeAdd(i + 1, n, -1);
			++ind0;
		}
		while(ind1 < n && ord_as[ind1].first < b) {
			int i = ord_as[ind1].second;
			seg.rangeAdd(0, i, 1);
			++ind1;
		}
		ll minv = seg.rangeMin(0, n);
		res += minv;
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