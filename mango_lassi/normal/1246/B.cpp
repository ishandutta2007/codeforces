#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;

tuple<vector<int>, vector<int>> sieve(int n) {
	vector<int> primes;
	vector<int> div_ind(n+1, -1);
	for (int i = 2; i <= n; ++i) {
		if (div_ind[i] == -1) {
			div_ind[i] = primes.size();
			primes.push_back(i);
		}
		for (int j = 0; j <= div_ind[i]; ++j) {
			int t = primes[j] * i;
			if (t > n) break;
			div_ind[t] = j;
		}
	}
	return {primes, div_ind};
}

const int N = 1e5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(N);

	int n, k;
	cin >> n >> k;

	vector<vector<pair<int, int>>> xs(n);
	vector<vector<pair<int, int>>> ys(n);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		while(v != 1) {
			int p = primes[div_ind[v]];
			int c = 0;
			while(v % p == 0) {
				v /= p;
				++c;
			}
			if (c % k != 0) {
				xs[i].push_back({p, c % k});
				ys[i].push_back({p, (k - c) % k});
				if (ys[i].back().second < 0) ys[i].back().second += k;
			}
		}
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	// Answer is number of equal elements
	int i = 0, j = 0;
	ll res = 0;
	while(i < n && j < n) {
		if (xs[i] < ys[j]) {
			int ni = i;
			while(ni < n && xs[ni] == xs[i]) ++ni;
			i = ni;
		} else if (xs[i] > ys[j]) {
			int nj = j;
			while(nj < n && ys[nj] == ys[j]) ++nj;
			j = nj;
		} else {
			bool oi = true;
			for (auto pr : xs[i]) {
				if (2 * pr.second % k != 0) oi = false;
			}
			int ni = i, nj = j;
			while(ni < n && xs[ni] == xs[i]) ++ni;
			while(nj < n && ys[nj] == ys[j]) ++nj;
			
			ll xc = ni - i;
			ll yc = nj - j;
			if (oi) {
				res += xc * (yc - 1);
			} else {
				res += xc * yc;
			}

			i = ni;
			j = nj;
		}
	}
	cout << res / 2 << '\n';
}