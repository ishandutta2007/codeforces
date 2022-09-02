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

template<class T>
class RangeMin {
	private:
		vector<T> seg;
		int n;
	public:	
		RangeMin(const vector<T>& v) : n(v.size()), seg(2*v.size()) {
			for (int i = 0; i < n; ++i) seg[i+n] = v[i];
			for (int i = n-1; i > 0; --i) seg[i] = min(seg[2*i], seg[2*i+1]);
		}
		T get(int a, int b) const {
			T res = seg[a + n]; // Change to INF to allow a > b
			for (a += n, b += n+1; a < b; a=(a+1)/2, b /= 2) {
				if (a & 1) res = min(res, seg[a]);
				if (b & 1) res = min(res, seg[b-1]);
			}
			return res;
		}
};

void solve() {
	int n, m;
	cin >> n >> m;

	vector<ll> xs;
	vector<pair<ll, ll>> rain(n);
	for (int i = 0; i < n; ++i) {
		cin >> rain[i].first >> rain[i].second;
		xs.push_back(rain[i].first - rain[i].second);
		xs.push_back(rain[i].first);
		xs.push_back(rain[i].first + rain[i].second);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for (int i = 0; i < n; ++i) rain[i].first = bins(xs, rain[i].first);
	int k = xs.size();

	vector<ll> adds(k, 0);
	for (int i = 0; i < n; ++i) {
		int a = bins(xs, xs[rain[i].first] - rain[i].second);
		int b = bins(xs, xs[rain[i].first] + rain[i].second);
		adds[a] += 1;
		adds[rain[i].first] -= 2;
		adds[b] += 1;
	}

	ll cur = 0, add = 0;
	vector<ll> water(k, 0);
	int left_bad = k, right_bad = -1;
	for (int i = 0; i < k; ++i) {
		water[i] = cur;
		if (water[i] > m) {
			left_bad = min(left_bad, i);
			right_bad = max(right_bad, i);
		}
		if (i + 1 < k) {
			add += adds[i];
			cur += add * (xs[i + 1] - xs[i]);
		}
	}


	vector<ll> le_water(k), ri_water(k);
	for (int i = 0; i < k; ++i) le_water[i] = -(water[i] + xs[i]);
	for (int i = 0; i < k; ++i) ri_water[i] = -(water[i] - xs[i]);
	RangeMin<ll> le(le_water), ri(ri_water);
	
	/*
	for (int i = 0; i < k; ++i) cerr << xs[i] << "\t"; cerr << '\n';
	for (int i = 0; i < k; ++i) cerr << water[i] << "\t"; cerr << '\n';
	for (int i = 0; i < k; ++i) cerr << le_water[i] << "\t"; cerr << '\n';
	for (int i = 0; i < k; ++i) cerr << ri_water[i] << "\t"; cerr << '\n';
	cerr << left_bad << ' ' << right_bad << '\n';
	*/

	for (int i = 0; i < n; ++i) {
		int j = rain[i].first;
		int p = rain[i].second;
		int a = bins(xs, xs[j] - p);
		int b = bins(xs, xs[j] + p);
		adds[a] += 1;
		adds[j] -= 2;
		adds[b] += 1;

		ll val0 = (-xs[j] - le.get(a, b)) - p;
		ll val1 = (xs[j] - ri.get(a, b)) - p;
		if (val0 <= m && val1 <= m && left_bad >= a && right_bad <= b) cout << '1';
		else cout << '0';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}