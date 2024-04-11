#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int K = 60;
ll fib[K];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i < K; ++i) {
		for (int j = 0; j < i; ++j) fib[i] += fib[j];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll a, b, m;
		cin >> a >> b >> m;

		// Loop number of terms.
		bool fail = true;
		for (int k = 1; k <= K; ++k) {
			vector<ll> res(k);
			res[0] = a;

			ll tar = b - fib[k-1] * a;
			for (int i = 1; i < k; ++i) {
				tar -= fib[k-1-i];
			}
			if (tar < 0) break;

			for (int i = 1; i < k; ++i) {
				ll v = min(m-1, tar / fib[k-1-i]);
				tar -= v * fib[k-1-i];
				res[i] = v+1;
			}
			if (tar == 0) {
				cout << k << " ";
				for (int i = 1; i < k; ++i) {
					for (int j = 0; j < i; ++j) res[i] += res[j];
				}
				for (auto v : res) cout << v << ' '; cout << '\n';

				fail = false;
				break;
			}
		}
		if (fail) {
			cout << "-1\n";
		}
	}
}