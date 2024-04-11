#include <iostream>
#include <vector>
using namespace std;

const int N = 10 + (1e6);
int divs[N];

int main() {
	vector<int> primes;
	for (int i = 2; i < N; ++i) {
		if (divs[i] == 0) {
			primes.push_back(i);
			divs[i] = primes.size();
		}	
		for (int j = 0; j < primes.size(); ++j) {
			int p = primes[j];
			int t = p * i;
			if (t >= N) break;
			divs[t] = j+1;
			if (divs[i] == j+1) break;
		}
	}

	int x2;
	cin >> x2;
	int tmp = x2;
	int minx1 = x2;
	int maxx1 = x2;
	while(tmp > 1) {
		int p = primes[divs[tmp]-1];
		minx1 = min(minx1, x2-p+1);
		tmp /= p;
	}
	// cout << minx1 << ' ' << maxx1 << '\n';
	int minx0 = x2;
	for (int i = minx1; i <= maxx1; ++i) {
		tmp = i;
		while(tmp > 1) {
			int p = primes[divs[tmp]-1];
			if (p != i) minx0 = min(minx0, i-p+1);
			tmp /= p;
		}
	}
	cout << minx0 << '\n';
}