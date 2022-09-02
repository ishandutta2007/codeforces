#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<ll> as(n), bs(n), ds(n);
	for (ll& a : as) cin >> a;
	for (ll& b : bs) cin >> b;
	for (int i = 0; i < n; ++i) ds[i] = as[i] - bs[i];
	
	// Operation alternatingly adds +1 and -1 to some subset of even size
	// -> Possible IFF total interval sum 0 and no prefix sum is positive
	// -> Need at least absolute value of smallest prefix sum steps
	// -> Necessary and sufficient! Can always increment smallest prefix sum!

	vector<ll> prefs(n + 1, 0), inv_prefs(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		prefs[i] = prefs[i-1] + ds[i-1];
		inv_prefs[i] = -prefs[i];
	}

	RangeMin<ll> mins(prefs), maxs(inv_prefs);

	for (int qi = 0; qi < q; ++qi) {
		int a, b;
		cin >> a >> b;

		if (((-maxs.get(a, b - 1)) - prefs[a - 1] > 0) || (prefs[a - 1] != prefs[b])) {
			cout << -1 << '\n';
		} else {
			cout << abs(mins.get(a, b - 1) - prefs[a - 1]) << '\n';
		}
	}
}