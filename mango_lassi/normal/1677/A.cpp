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
};

void solve() {
	int n;
	cin >> n;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	ll res = 0;
	Fenwick fenw(n + 1);
	for (int b = 0; b < n; ++b) {
		ll cur = 0;
		for (int d = b + 1; d < n; ++d) {
			if (as[b] > as[d]) res += cur;
			cur += fenw.get(as[d]);
		}
		fenw.add(as[b], 1);
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