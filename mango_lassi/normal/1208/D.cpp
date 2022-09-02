#include <iostream>
#include <vector>
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

	Fenwick fenw(n);
	for (int i = 0; i < n; ++i) fenw.add(i, i+1);

	vector<ll> sums(n);
	for (int i = 0; i < n; ++i) {
		cin >> sums[i];
	}
	vector<int> res(n);
	for (int i = n-1; i >= 0; --i) {
		res[i] = fenw.search(sums[i]) + 1;
		fenw.add(res[i], -(res[i] + 1));
	}
	for (auto v : res) cout << v+1 << ' '; cout << '\n';
}