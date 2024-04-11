#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	// Need to delete some amount, and for the remaining values B[0], ..., B[m-2], B[m-1] have
	//	B[x-1] <= (B[0] + B[x]) / 2 = B[x] / 2 + (B[0] / 2)
	//	-> B[x] >= 2B[x-1] - B[0]
	// for all 2 <= x <= m-1

	// Denote R[x] = B[x] - B[0]
	// Then our condition is R[x] >= 2R[x-1]
	// Thus, we can have an unlimited amount of elements equal to the minimum,
	// But after that, at most log_2(10^9) <= 30 elements
	
	Fenwick prefs(n);
	prefs.add(0, as[0]);
	for (int i = 1; i < n; ++i) prefs.add(i, as[i] - as[i-1]);

	ll res = 0;
	for (int i = 0; i < n;) {
		int s = i + 1;
		while(s < n && as[s] == as[i]) ++s;
		
		ll off = s - i;
		for (int j = s; j < n; ++off) {
			ll r = as[j] - as[i];
			ll min_nxt = 2*r + as[i];
			j = prefs.search(min_nxt - 1) + 1;
		}
		res = max(res, off);
		i = s;
	}
	cout << n - res << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}