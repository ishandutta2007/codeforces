#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	for (int ti = 0; ti < t; ++ti) {
		int n;
		cin >> n;

		vector<int> p(n);
		for (int& x : p) {
			cin >> x;
			--x;
		}

		vector<int> cols(n);
		for (int& c : cols) {
			cin >> c;
			--c;
		}

		int res = n;
		vector<int> ts(n, -1);
		vector<int> ind(n, -1);

		int t = 0;
		for (int i = 0; i < n; ++i) {
			if (ts[i] != -1) continue;

			int t0 = t;
			for (int j = i; ts[j] == -1; j = p[j]) {
				ts[j] = t;
				ind[t] = j;
				++t;
			}

			int len = t - t0;
			for (int d = 1; d <= len && d < res; ++d) {
				if (len % d) continue;
				for (int s = 0; s < d; ++s) {
					bool works = 1;
					int c = cols[ind[t0 + s]];
					int j = t0 + s;

					do {
						if (cols[ind[j]] != c) works = 0;
						j = (j + d - t0) % len + t0;
					} while (j != t0 + s);

					if (works) {
						res = d;
						break;
					}
				}
			}
		}
		cout << res << '\n';
	}
}