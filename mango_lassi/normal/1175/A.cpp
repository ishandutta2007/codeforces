#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll n, k;
		cin >> n >> k;
		ll res = 0;
		while(n > 0) {
			if (n % k == 0) {
				n /= k;
				++res;
			} else {
				res += n % k;
				n -= n % k;
			}
		}
		cout << res << '\n';
	}
}