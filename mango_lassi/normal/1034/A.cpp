#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 3 * (int)1e5;
const int M = 2 * (int)1e7;
int dsor[M];
int vals[N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	vector<int> primes;
	for (int i = 0; i < M; ++i) dsor[i] = -1;
	for (int i = 2; i < M; ++i) {
		if (dsor[i] == -1) {
			dsor[i] = primes.size();
			primes.push_back(i);
		}
		for (int j = 0; j < primes.size(); ++j) {
			int t = primes[j] * i;
			if (t >= M) break;

			dsor[t] = j;
			if (j == dsor[i]) break;
		}
	}
	int pc = primes.size();
	vector<int> counts(pc, 0);

	int n;
	cin >> n;

	// The gcd of the remaining integers is some prime.
	// factor all integers, increment the counters of the respective primes, QED

	int gd = 0;
	for (int i = 0; i < n; ++i) {
		cin >> vals[i];
		gd = gcd(gd, vals[i]);
	}
	
	for (int i = 0; i < n; ++i) {
		int v = vals[i] / gd;
		while(v > 1) {
			int j = dsor[v];
			++counts[j];
			while(v % primes[j] == 0) v /= primes[j];
		}
	}
	
	int best = 0;
	for (int i = 0; i < pc; ++i) {
		best = max(best, counts[i]);
	}
	
	if (best == 0) {
		cout << "-1\n";
	} else {
		cout << n-best << '\n';
	}
}