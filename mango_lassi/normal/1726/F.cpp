#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

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

// Segment tree for range minimum and range capping
class SegTree {
	private:
		const ll NEUT = 4 * (ll)1e18;
		vector<ll> seg, tag;
		int h = 1;

		void apply(int i, ll v) {
			seg[i] = min(seg[i], v);
			if (i < h) tag[i] = min(tag[i], v);
		}
		ll recGet(int a, int b, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return NEUT;
			if (a <= ia && ib <= b) return seg[i];
			int im = (ia + ib) >> 1;
			return min(tag[i], min(
				recGet(a, b, 2*i, ia, im),
				recGet(a, b, 2*i+1, im, ib)));
		}
		void recApply(int a, int b, ll v, int i, int ia, int ib) {
			if (ib <= a || b <= ia) return;
			if (a <= ia && ib <= b) apply(i, v);
			else {
				int im = (ia + ib) >> 1;
				recApply(a, b, v, 2*i, ia, im);
				recApply(a, b, v, 2*i+1, im, ib);
				seg[i] = min(tag[i], min(seg[2*i], seg[2*i+1]));
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h *= 2;
			seg.resize(2*h, NEUT);
			tag.resize(h, NEUT);
		}
		ll rangeMin(int a, int b) { return recGet(a, b+1, 1, 0, h); }
		void rangeCap(int a, int b, ll v) { recApply(a, b+1, v, 1, 0, h); }
};

ll getWait(ll a, ll b, ll t) {
	return (a < b ? b-a : b+t - a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll t;
	cin >> n >> t;
	
	vector<ll> gs(n), cs(n), ds(n, 0), comp = {0ll, t-1};
	for (int i = 0; i < n; ++i) cin >> gs[i] >> cs[i];

	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cin >> ds[i];
			ds[i] += ds[i-1];
		}
		cs[i] = (cs[i] + ds[i]) % t;
		cs[i] = (t - cs[i]) % t; // Time the light turns green mod t

		comp.push_back(cs[i]);				// Turns green
		comp.push_back((cs[i] + gs[i] + t-1) % t);	// Last second while green
		comp.push_back((cs[i] + gs[i]) % t);		// Turns red
		comp.push_back((cs[i] + t-1) % t);		// Last second while red
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	int k = comp.size();

	vector<ll> dp(n, INF);
	SegTree seg(k);
	seg.rangeCap(0, k-1, n);

	for (int i = n-1; i >= 0; --i) {
		// Calculate DP
		int ind = bins(comp, cs[i]);
		int j = seg.rangeMin(ind, ind);
		if (j == n) dp[i] = 0;
		else dp[i] = dp[j] + getWait(cs[i], cs[j], t);

		// Update red lights
		ll a = (cs[i] + gs[i]) % t;
		ll b = (cs[i] + t-1) % t;

		// cerr << i << ": mark range " << a << ' ' << b << " red\n";
		if (a <= b) {
			int ind0 = bins(comp, a);
			int ind1 = bins(comp, b);
			seg.rangeCap(ind0, ind1, i);
		} else {
			int ind0 = bins(comp, a);
			int ind1 = bins(comp, t-1);
			int ind2 = bins(comp, 0ll);
			int ind3 = bins(comp, b);
			seg.rangeCap(ind0, ind1, i);
			seg.rangeCap(ind2, ind3, i);
		}
	}

	ll res = INF;
	for (int ind = 0; ind < k; ++ind) {
		int j = seg.rangeMin(ind, ind);

		ll off = INF;
		if (j == n) off = ds[n-1];
		else off = ds[n-1] + dp[j] + getWait(comp[ind], cs[j], t);
		res = min(res, off);

		// cerr << comp[ind] << ": " << j << ' ' << dp[j] << " -> " << off << '\n';
	}
	cout << res << '\n';
}