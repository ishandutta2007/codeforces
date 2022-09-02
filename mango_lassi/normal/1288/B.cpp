#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll calc(ll x, ll d) {
	return x + (d + x) / (x + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n, m;
		cin >> n >> m;

		// Loop number of digits in b
		// a * b + a + b = a * 10^k + b
		// -> a * (b+1) = a * 10^k
		// -> b+1 = 10^k
		// Therefore this works IFF b = 10^k - 1

		ll res = 0;
		ll pw = 10;
		while(m >= pw - 1) {
			++res;
			pw *= 10;
		}
		res *= n;
		cout << res << '\n';
	}
}