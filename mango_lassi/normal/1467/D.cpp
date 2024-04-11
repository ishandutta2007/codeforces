#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7;

ll mAdd(ll a, ll b) {
	ll res = (a + b);
	if (res >= MOD) res -= MOD;
	return res;
}

class Fenwick {
	private:
		vector<ll> val;
	public:
		Fenwick(int n) : val(n+1, 0) {}

		// Adds v to index i
		void add(int i, ll v) {
			for (++i; i < val.size(); i += i & -i) {
				val[i] = mAdd(val[i], v);
			}
		}

		// Calculates prefix sum up to index i
		ll get(int i) {
			ll res = 0;
			for (++i; i > 0; i -= i & -i) {
				res = mAdd(res, val[i]);
			}
			return res;
		}
};

const int N = 5000;
const int K = 5000;
ll ins[N][K+1];
ll tot[N];

void solve() {
	int n, k, q;
	cin >> n >> k >> q;

	for (int i = 0; i < n; ++i) ins[i][0] = 1;
	for (int t = 1; t <= k; ++t) {
		for (int j = 0; j < n; ++j) {
			if (j > 0) ins[j][t] = mAdd(ins[j][t], ins[j-1][t-1]);
			if (j+1 < n) ins[j][t] = mAdd(ins[j][t], ins[j+1][t-1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int t = 0; t <= k; ++t) {
			tot[i] = mAdd(tot[i], ins[i][t] * ins[i][k-t] % MOD);
		}
	}

	Fenwick fenw(n);
	vector<ll> as(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		fenw.add(i, as[i] * tot[i] % MOD);
	}

	for (int qi = 0; qi < q; ++qi) {
		int i;
		ll x;
		cin >> i >> x;
		--i;

		ll d = tot[i] * (x - as[i]) % MOD;
		as[i] = x;

		if (d < 0) d += MOD;
		fenw.add(i, d);

		cout << fenw.get(n-1) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}