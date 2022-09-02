#include <iostream>
#include <vector>
using namespace std;

const int N = 150000;
int vals[N][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> vals[i][0] >> vals[i][1];
	}
	// Answer has to be some prime dividing a1 or b1. A number <= 2 * 10^9 can have at most 10 or so prime divisors.
	vector<int> primes;
	for (int j = 0; j < 2; ++j) {
		for (int i = 2; i * i <= vals[0][j]; ++i) {
			if (vals[0][j] % i == 0) {
				primes.push_back(i);
				while(vals[0][j] % i == 0) {
					vals[0][j] /= i;
				}
			}
		}
		if (vals[0][j] > 1) {
			primes.push_back(vals[0][j]);
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < primes.size(); ++j) {
			int p = primes[j];
			if (vals[i][0] % p != 0 && vals[i][1] % p != 0) {
				primes[j] = primes.back();
				primes.pop_back();
				--j;
			}
		}
	}

	if (primes.empty()) {
		cout << "-1\n";
	} else {
		cout << primes.back() << '\n';
	}
}