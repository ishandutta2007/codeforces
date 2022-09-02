#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

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

int getSlot(ll w) {
	if (w == 0) return 0;
	int flog2 = 63 - __builtin_clzll(w);
	return flog2;
}

const int H = 19; // ceil(log_2(1e5)) + 2
class SegTree {
	private:
		vector<array<ll, 3>> vals;
		vector<array<ll, 3*H>> seg;
		int h = 1;

		void update(int i) {
			seg[i][0] = seg[2*i][0] + seg[2*i+1][0];
			seg[i][1] = seg[2*i][1] + seg[2*i+1][1];
			seg[i][2] = min(seg[2*i][2], seg[2*i+1][2]);
			for (int j = 3; j < 3*H; j += 3) {
				seg[i][j] = seg[2*i][j] + seg[2*i+1][j];
				seg[i][j+1] = seg[2*i][j+1] + seg[2*i+1][j+1];
				seg[i][j+2] = min(seg[2*i][j+2], seg[2*i+1][j+2] + seg[2*i][j - 3]);
			}
		}
		void recSolve(ll& c, ll& r, int i) {
			if (c == 0) return;
			int s = min(H-1, getSlot(c));

			if (i >= h) {
				array<ll, 3> el = vals[i - h];
				ll cou = min(el[2], c / el[0]);
				r += cou * el[1];
				c -= cou * el[0];
			} else if ((s > 0 && seg[i][3*(s-1)] > c) || (seg[i][3*s + 2] <= c)) {
				recSolve(c, r, 2*i);
				recSolve(c, r, 2*i+1);
			} else if (s > 0) {
				c -= seg[i][3*(s-1)];
				r += seg[i][3*(s-1) + 1];
			}
		}
	public:
		SegTree(int n) {
			while(h < n) h <<= 1;
			vals.resize(h);
			seg.resize(2*h);
			for (int i = 0; i < h; ++i) setv(i, 1, 0, 0);
		}
		void setv(int i, ll w, ll v, ll k) {
			vals[i][0] = w; vals[i][1] = v; vals[i][2] = k;
			int s = getSlot(w);
			i += h;

			for (int j = 0; j < 3*s; j += 3) {
				seg[i][j] = 0; seg[i][j+1] = 0; seg[i][j+2] = INF;
			}
			for (int j = 3*s; j < 3*H; j += 3) {
				seg[i][j] = k*w;
				seg[i][j+1] = k*v;
				seg[i][j+2] = INF;
			}
			if (k > 0) seg[i][3*s+2] = w;

			for (i >>= 1; i > 0; i >>= 1) update(i);
		}
		ll solve(ll c) {
			ll r = 0;
			recSolve(c, r, 1);
			return r;
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<ll> ori_ks(n);
	vector<pair<ll, ll>> dms(n);
	for (int i = 0; i < n; ++i) {
		cin >> ori_ks[i] >> dms[i].second >> dms[i].first;
		dms[i].first *= -1;
	}

	vector<pair<ll, ll>> ord = dms;
	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());
	
	int m = ord.size();
	
	vector<ll> ks(m, 0);
	vector<int> inds(n);
	for (int i = 0; i < n; ++i) {
		inds[i] = bins(ord, dms[i]);
		ks[inds[i]] += ori_ks[i];
	}

	SegTree seg(m);
	for (int i = 0; i < m; ++i) seg.setv(i, ord[i].second, -ord[i].first, ks[i]);

	for (int j = 0; j < q; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			ll k;
			int i;
			cin >> k >> i;

			i = inds[i - 1];
			ks[i] += k;
			seg.setv(i, ord[i].second, -ord[i].first, ks[i]);
		} else if (t == 2) {
			ll k;
			int i;
			cin >> k >> i;
			
			i = inds[i - 1];
			ks[i] -= k;
			seg.setv(i, ord[i].second, -ord[i].first, ks[i]);
		} else {
			ll c;
			cin >> c;
			cout << seg.solve(c) << '\n';
		}
	}
}