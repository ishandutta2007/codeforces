#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int H = 1e9;
const int K = 1000;

// Max we can do with n
ll off(int n) {
	return (ll)(n/2) * ((n-1)/2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll m;
	cin >> n >> m;

	// 1 2 3 4 5 6
	// 1 2 3
	// 1   3 4
	// 1     4 5
	// 1       5 6
	//   2 3   5
	//   2   4   6


	// 1 2 3 4 5 8
	// 1 2 3
	// 1   3 4
	// 1     4 5
	//   2 3   5
	//     3   5 8

	// What changes when we increment last?
	// Problem: we might create more pairs
	// Solution: just increment more.
	// How to check if a new pair is form?
	// Then a + (a+1) = v
	// -> v = 2a+1 and a <= n-2

	if (m > off(n)) {
		cout << -1 << '\n';
	} else {
		vector<ll> res(n+1);
		res[n] = H;
		while(n > 0 && off(n-1) >= m) {
			res[n-1] = res[n] - 3*n - K;
			--n;
		}

		m = off(n) - m;

		for (int i = 0; i < n; ++i) res[i] = i+1;
		while(m > 0) {
			++res[n-1];
			if ((res[n-1] % 2 == 0) || (res[n-1]/2 >= n-1)) --m;
		}

		res.pop_back();
		for (auto v : res) cout << v << ' '; cout << '\n';
	}
}