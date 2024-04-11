#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes, vector<int>& div_ind) {
	primes.reserve(n+1);
	div_ind.resize(n+1);
	for (int i = 0; i <= n; ++i) div_ind[i] = -1;
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
}

int main() {
	int n;
	cin >> n;

	vector<int> primes;
	vector<int> div_ind;
	sieve(n, primes, div_ind);
	for (int i = 2; i <= n; ++i) cout << div_ind[i]+1 << ' '; cout << '\n';
}