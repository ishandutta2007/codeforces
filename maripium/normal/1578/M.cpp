#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	auto choose = [&](int n, int k) {
		if (k == 0) return int64_t(1);
		else if (k == 1) return int64_t(n);
		else if (k == 2) return int64_t(n) * int64_t(n-1) / 2;
		else return int64_t(n) * int64_t(n-1) * int64_t(n-2) / 6;
	};
	int N; double _P; cin >> N >> _P; int P = int(_P * 10000);
	int lo = 0, hi = N-1;
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		// check mi
		int64_t tot = 0;
		int a = mi;
		int b = N - mi;
		for (int x = 1; x <= 3; ++x) {
			int64_t prob = choose(a, x) * choose(b, 3 - x);
			if (x == 3) tot += 2 * prob;
			else if (x == 2) tot += 2 * prob;
			else tot += prob;
		}
		if (tot * 10000 >= choose(N, 3) * 2 * P) {
			hi = mi;
		} else {
			lo = mi + 1;
		}
	}
	cout << lo << '\n';
	return 0;
}