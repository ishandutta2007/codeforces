#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		ll a, b;
		cin >> a >> b;
		ll d = abs(b-a);

		// Can make equal with k operations if we have correct parity and the sum of the values is at least the difference
		ll low = 0;
		ll high = d;
		while(low != high) {
			ll mid = (low + high) >> 1;
			ll off = mid * (mid + 1) / 2;
			if (off < d) low = mid + 1;
			else high = mid;
		}
		while(true) {
			ll off = low * (low + 1) / 2;
			if ((a + b + off) & 1) ++low;
			else break;
		}
		cout << low << '\n';
	}
}