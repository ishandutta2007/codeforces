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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	Fenwick fenw(n + q);
	for (int i = 0; i < n; ++i) fenw.add(i, 1);

	const int C = 50;
	array<int, C> inds;
	for (int i = 0; i < C; ++i) inds[i] = -1;

	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		--c;

		if (inds[c] == -1) inds[c] = n-1-i;
	}
	for (int j = n; j < n + q; ++j) {
		int c;
		cin >> c;
		--c;

		int i = inds[c];
		cout << fenw.get(i, n + q - 1) << ' ';

		fenw.add(i, -1);
		fenw.add(j, 1);
		inds[c] = j;
	}
	cout << '\n';
}