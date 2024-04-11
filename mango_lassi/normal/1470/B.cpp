#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function for precalculating primes and prime divisors
pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> div_ind(n+1, -1), primes;
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

int pack(int v, const vector<int>& primes, const vector<int>& div_ind) {
	int res = 1;
	while(v != 1) {
		int j = div_ind[v];
		v /= primes[j];

		if (v != 1 && div_ind[v] == j) {
			v /= primes[j];
		} else {
			res *= primes[j];
		}
	}
	return res;
}

void solve(const vector<int>& primes, const vector<int>& div_ind) {
	int n;
	cin >> n;

	vector<int> vals(n);
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		int r = pack(v, primes, div_ind);
		vals[i] = r;
	}
	sort(vals.begin(), vals.end());

	// lcm(x, y) = xy / gcd(x, y)
	// -> xy / gcd(x, y)^2 is a perfect square
	// -> xy is a perfect square

	// Multiply by all adjacent elements ->
	//	even number of adjancent elements: replaced by arbitrary adjacent element
	// 	odd number of adjacent elements: becomes a perfect square
	// Adjacent IFF copies of eachother

	int ans0 = 0;
	int sq1 = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && vals[j] == vals[i]) ++j;
		int cou = (j - i);

		ans0 = max(ans0, cou);
		if ((vals[i] == 1) || (cou % 2 == 0)) sq1 += cou;
		i = j;
	}

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		ll w;
		cin >> w;
		if (w >= 1) cout << max(ans0, sq1) << '\n';
		else cout << ans0 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int H = 1e6;
	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(H+1);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve(primes, div_ind);
}