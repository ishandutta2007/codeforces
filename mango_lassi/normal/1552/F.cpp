#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mAdd(ll a, ll b) {
	if (a + b >= MOD) return a + b - MOD;
	else return a + b;
}
ll mSub(ll a, ll b) {
	if (a < b) return a + MOD - b;
	else return a - b;
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> xs(n), ys(n), ss(n), y_ind(n);
	for (int i = 0; i < n; ++i) cin >> xs[i] >> ys[i] >> ss[i];
	for (int i = 0; i < n; ++i) y_ind[i] = bins(xs, ys[i]);
	
	for (int i = 0; i < n; ++i) {
		xs[i] %= MOD;
		ys[i] %= MOD;
	}
	ll res = (xs[n-1] + 1) % MOD;

	vector<ll> dp(n);
	Fenwick dp_sum(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = mAdd(mSub(xs[i], ys[i]), dp_sum.get(y_ind[i], i - 1));
		dp_sum.add(i, dp[i]);
		if (ss[i]) res = mAdd(res, dp[i]);
	}

	res = (res % MOD);
	if (res < 0) res += MOD;
	cout << res << '\n';
	

}