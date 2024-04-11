#include <bits/stdc++.h>
using namespace std;

set<long long> primes;

void initPrimes(int x) {
	vector<bool> prime;
	prime.resize(x+1, true);
	for (int i = 2; i <= x; i++) {
		if (prime[i]) {
			primes.insert(i*1LL);
			for (int j = i*2; j <= x; j += i) prime[j] = false;
		}
	}
}

int tc, n;

int main() {
	initPrimes(1000000);
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		long long x = *primes.lower_bound(n+1LL);
		long long y = *primes.lower_bound(n+x);
		printf("%lld\n", x*y);
	}
	return 0;
}