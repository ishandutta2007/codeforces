#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

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

const int N = 1000;
vector<int> conns[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> primes, div_ind;
	tie(primes, div_ind) = sieve(5*N);

	int m = n;
	for (int i = 0; i < n; ++i) {
		int t = (i+1) % n;
		conns[i].push_back(t);
		conns[t].push_back(i);
	}

	int j1 = 0;
	int j2 = n/2;
	while((primes[div_ind[m]] != m) && (j1 < n/2)) {
		conns[j1].push_back(j2);
		conns[j2].push_back(j1);
		++j1;
		++j2;
		++m;
	}
	if (primes[div_ind[m]] != m) {
		cout << "-1\n";
	} else {
		cout << m << '\n';
		for (int i = 0; i < n; ++i) {
			for (auto t : conns[i]) {
				if (t > i) cout << (i+1) << ' ' << (t+1) << '\n';
			}
		}
	}
}