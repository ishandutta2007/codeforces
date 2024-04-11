#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}
ll mSub(ll a, ll b) {
	return (a >= b ? a - b : a + MOD - b);
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
		ll get(int a, int b) { return mSub(get(b), get(a-1)); }
};

void solve() {
	int n;
	cin >> n;

	vector<pair<int, int>> as(n), bs(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i].first >> bs[i].first;
		as[i].second = i;
		bs[i].second = i;
	}
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());

	vector<int> a_ind(n), b_ind(n);
	for (int i = 0; i < n; ++i) {
		a_ind[as[i].second] = i;
		b_ind[bs[i].second] = i;
	}

	int q;
	cin >> q;
	vector<pair<int, int>> qs(q);
	for (int qi = 0; qi < q; ++qi) {
		cin >> qs[qi].second;
		--qs[qi].second;
		qs[qi].first = b_ind[qs[qi].second];
	}
	sort(qs.begin(), qs.end());

	Fenwick fenw(n);
	vector<ll> vals(n); // Number of teleports after encountering this task the first time to get back to it
	for (int ind = 0; ind < n; ++ind) {
		int i = bs[ind].second;
		int j = a_ind[i];

		vals[i] = mAdd(1, fenw.get(j, n-1));
		fenw.add(j, vals[i]);
	}

	fenw = Fenwick(n);
	for (int i = 0; i < n; ++i) fenw.add(b_ind[i], vals[i]);
	int safe_ind = 0;

	ll res = 0;
	while(! qs.empty()) {
		int i = qs.back().second;
		qs.pop_back();
		if (a_ind[i] < safe_ind) continue;

		res = mAdd(res, mAdd(fenw.get(b_ind[i] - 1), 1));
		while(safe_ind <= a_ind[i]) {
			int j = as[safe_ind].second;
			fenw.add(b_ind[j], mSub(0, vals[j]));
			++safe_ind;
		}
	}

	res %= MOD;
	if (res < 0) res += MOD;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}