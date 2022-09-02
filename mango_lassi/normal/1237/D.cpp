#include <iostream>
#include <vector>
#include <algorithm>
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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> as(n);
	vector<pair<ll, int>> ord(n);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		ord[i] = {as[i], i};
	}
	sort(ord.begin(), ord.end());
	
	if (2 * ord[0].first >= ord.back().first) {
		for (int i = 0; i < n; ++i) cout << "-1 "; cout << '\n';
	} else {
		int x = n-1;
		Fenwick fenw(n+1);
		for (int i = 0; i <= n; ++i) fenw.add(i, 1);
		
		vector<ll> dp(n, -1);
		for (int j = n-1; j >= 0; --j) {

			ll v = ord[j].first;
			int i = ord[j].second;
			while(x >= 0 && 2*ord[x].first >= v) {
				fenw.add(ord[x].second, -1);
				--x;
			}

			int t = fenw.search(fenw.get(i));
			dp[i] = t - i + 1;
			if (t == n-1) {
				t = fenw.search(0);
				dp[i] += t+1;
			}
			if (dp[t+1] != -1) dp[i] += dp[t+1];

			fenw.add(i, 1);
		}
		for (auto v : dp) cout << v << ' '; cout << '\n';
	}
}