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

const int N = 3 * (int)1e5;
vector<pair<int, int>> que[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	for (int qi = 0; qi < q; ++qi) {
		int x, y;
		cin >> x >> y;
		y = n-1-y;
		que[y].emplace_back(x, qi);
	}

	// Maintain how many we can delete if first k are made into n+1
	// Binary search the point where we can delete the current element

	Fenwick fenw(n);
	vector<int> res(q, -1);
	for (int i = 0; i < n; ++i) {
		int k = i+1 - as[i];
		int j = min(i, fenw.search(-k));
		if (k >= 0 && j >= 0) {
			fenw.add(0, -1);
			fenw.add(j+1, 1);
		}
		for (auto pr : que[i]) {
			res[pr.second] = -fenw.get(pr.first);
		}
	}
	for (int v : res) cout << v << '\n';
}