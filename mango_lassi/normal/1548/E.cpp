#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
//using namespace pb_ds;

typedef tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


class DSU {
	private:
		vector<int> comp, siz;
	public:
		DSU(int n) : comp(n), siz(n, 1) {
			for (int i = 0; i < n; ++i) comp[i] = i;
		}
		int getc(int i) {
			if (comp[i] != i) comp[i] = getc(comp[i]);
			return comp[i];
		}
		bool join(int a, int b) {
			a = getc(a);
			b = getc(b);
			if (a == b) return false;

			if (siz[a] < siz[b]) swap(a, b);
			siz[a] += siz[b];
			comp[b] = a;
			return true;
		}
		int compSize(int i) { return siz[getc(i)]; }
};

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;

		int recf(int a, T v) const {
			while(a < n) a = 2*a + (seg[2*a] > v);
			return a - n;
		}
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}

		// Returns smallest i >= a s.t. val[i] <= v, or n if there is none
		int search(int a, T v) const {
			int b = 2*n, r = 2*n;
			for (a += n; a < b; a=(a+1)/2, b /= 2) {
				if ((a & 1) && seg[a] <= v) return recf(a, v);
				if ((b & 1) && seg[b-1] <= v) r = b-1;
			}
			return recf(r, v);
		}
		T get(int a, int b) const {
			T res = seg[a + n]; // Change to INF to allow a > b
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
		void set(int i, T v) {
			seg[i + n] = v;
			for (i += n; i > 1; i /= 2) seg[i/2] = min(seg[i], seg[i^1]);
		}
};



void solve() {
	int h, w;
	ll t;
	cin >> h >> w >> t;

	vector<ll> as(h), bs(w);
	for (ll& a : as) cin >> a;
	for (ll& b : bs) cin >> b;

	RangeMin<ll> seg(bs);

	vector<pair<ll, int>> ord(w);
	for (int x = 0; x < w; ++x) ord[x] = {bs[x], x};
	sort(ord.rbegin(), ord.rend());

	set<int> ps;
	vector<pair<pair<ll, ll>, int>> qs;
	// First, turn to counts of bad cells on the rows
	for (auto pr : ord) {
		int x = pr.second;

		int le = -1, ri = w;
		auto it = ps.lower_bound(x);
		if (it != ps.end()) ri = (*it);
		if (it != ps.begin()) {
			--it;
			le = (*it);
		}

		int mn = seg.get(le + 1, ri - 1);
		qs.emplace_back(make_pair(mn, bs[x]), 1);
		int mx = min((le == -1 ? t + 1 : bs[le]), (ri == w ? t + 1 : bs[ri]));
		qs.emplace_back(make_pair(mn, mx), -1);
		ps.insert(x);
	}

	sort(qs.rbegin(), qs.rend());
	
	vector<pair<ll, int>> ord2(h);
	for (int y = 0; y < h; ++y) ord2[y] = {as[y], y};
	sort(ord2.begin(), ord2.end());

	ordered_set min_vals;
	vector<int> val(h, t + 1);
	DSU dsu(h);

	int j = 0;
	ll res = 0;
	for (auto pr : qs) {
		while(j < h && ord2[j].first + pr.first.first <= t) {
			int y = ord2[j].second;
			val[y] = as[y];

			if (y > 0 && val[y - 1] <= t) {
				int ind = dsu.getc(y - 1);
				min_vals.erase(make_pair(val[ind], ind));
				val[y] = min(val[y], val[ind]);
				dsu.join(y, y - 1);
			}
			if (y < h - 1 && val[y + 1] <= t) {
				int ind = dsu.getc(y + 1);
				min_vals.erase(make_pair(val[ind], ind));
				val[y] = min(val[y], val[ind]);
				dsu.join(y, y + 1);
			}

			int ind = dsu.getc(y);
			val[ind] = val[y];
			min_vals.insert(make_pair(val[ind], ind));

			++j;
		}

		/*
		cerr << pr.first.first << ' ' << pr.first.second << ' ' << pr.second << '\n';
		for (auto pr : min_vals) {
			cerr << "\t" << pr.first << ' ' << pr.second << '\n';
		}
		*/

		int add = min_vals.order_of_key(make_pair(t - pr.first.second, h + 1)) * pr.second;
		res += add;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}