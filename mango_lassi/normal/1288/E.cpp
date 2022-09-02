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
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Last position: Update whenever we move forward and at the end
	// First position: Update whenever we move forward and at the beginning
	// -> We only need to be able to simulate the process

	int n, q;
	cin >> n >> q;
	
	Fenwick fenw(n + q);
	vector<int> p(n), lst(n);
	for (int i = 0; i < n; ++i) {
		p[i] = i;
		lst[p[i]] = q + i;
		fenw.add(q + i, 1);
	}
	vector<int> rmin = p, rmax = p;

	for (int t = q-1; t >= 0; --t) {
		int i;
		cin >> i;
		--i;

		int dep = fenw.get(lst[i]);
		rmax[i] = max(rmax[i], dep - 1);
		rmin[i] = min(rmin[i], 0);

		fenw.add(lst[i], -1);
		fenw.add(t, 1);
		lst[i] = t;
	}
	for (int i = 0; i < n; ++i) {
		int dep = fenw.get(lst[i]);
		rmax[i] = max(rmax[i], dep - 1);
		cout << rmin[i] + 1 << ' ' << rmax[i] + 1 << '\n';
	}
}