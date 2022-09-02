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

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<ll> cond = as;
	sort(cond.begin(), cond.end());
	cond.erase(unique(cond.begin(), cond.end()), cond.end());
	for (ll& a : as) a = bins(cond, a);
	int k = cond.size();

	vector<int> nxt(n, n), pre(n, -1), cur(k, -1);
	for (int i = 0; i < n; ++i) {
		pre[i] = cur[as[i]];
		cur[as[i]] = i;
	}

	for (int i = 0; i < k; ++i) cur[i] = n;
	for (int i = n-1; i >= 0; --i) {
		nxt[i] = cur[as[i]];
		cur[as[i]] = i;
	}

	vector<int> ends(n, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		ends[a - 1] = max(ends[a - 1], b - 1);
	}
	for (int i = 1; i < n; ++i) ends[i] = max(ends[i], ends[i - 1]);


	int low = 0;
	int high = n;
	while(low != high) {
		int ans = (low + high) >> 1;
		for (int i = 0; i < k; ++i) cur[i] = -1;
	
		int need = 0;
		SegTree opts(n);
		for (int i = 0, r = -1; i < n; ++i) {
			while(r < ends[i]) {
				++r;
				cur[as[r]] = r;
			}
			int j = cur[as[i]];
			if (j > i) {
				int x = nxt[i];
				int y = pre[j];

				// Our interval must either cover [i, y] or [x, j]
				opts.rangeAdd(max(0, y - ans + 1), i, -1);
				opts.rangeAdd(max(i + 1, j - ans + 1), x, -1);
				--need;
			}
		}
		if (opts.rangeMin(0, n-1) != need) low = ans + 1;
		else high = ans;

		// cerr << ans << ' ' << -need << ": ";
		// for (int i = 0; i < n; ++i) cerr << -opts.rangeMin(i, i) << ' '; cerr << '\n';
	}
	cout << low << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}