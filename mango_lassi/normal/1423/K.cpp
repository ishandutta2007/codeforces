#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6;
bool prime[N+1];
int res[N+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// A and B are NOT FRIENDS if either
	//	1. gcd(a, b)^2 >= a + b
	//	2. a >= gcd(a, b)^2 + b
	//	3. b >= gcd(a, b)^2 + a

	// Calculate first friend for every number?
	//	The first friend of prime P is P^2
	//	The first friend of PV, V > P is P(V-1)
	//	1 has no friends

	res[1] = 1;
	for (int i = 2; i <= N; ++i) {
		prime[i] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		if (prime[i]) {
			res[i] += 1;
			ll t = (ll)i*i;
			if (t <= N) {
				res[t] -= 1;
				for (; t <= N; t += i) prime[t] = 0;
			}
		}
		res[i] += res[i-1];
	}
	
	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) {
		int n;
		cin >> n;
		cout << res[n] << '\n';
	}
}