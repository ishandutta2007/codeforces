#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

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
	for (int i = 0; i < n; ++i) cin >> as[i];

	vector<pair<ll, int>> ord(n);
	for (int i = 0; i < n; ++i) {
		ord[i] = {as[i], -i};
	}
	sort(ord.begin(), ord.end());

	int q;
	cin >> q;
	vector<ll> ans(q, -1);
	vector<pair<pair<int, int>, int>> qrs(q);
	for (int i = 0; i < q; ++i) {
		cin >> qrs[i].first.first >> qrs[i].first.second;
		qrs[i].second = i;
	}
	sort(qrs.begin(), qrs.end());

	Fenwick fenw(n);
	int x = n;

	for (int j = 0; j < q; ++j) {
		int k = qrs[j].first.first;
		while(n-x < k) {
			--x;
			fenw.add(-ord[x].second, 1);
		}
		int ind = qrs[j].first.second - 1;
		int res = fenw.search(ind) + 1;
		ans[qrs[j].second] = as[res];
	}
	for (auto v : ans) cout << v << '\n';
}