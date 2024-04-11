#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	cin >> n;
	int res = 0;

	while(n > 0) {
		int r = n % 10;
		n /= 10;
		if (n > 0) {
			if (r == 9) {
				res += 9;
			} else {
				res += 10 + r;
				--n;
			}
		} else {
			res += r;
		}
	}
	cout << res << '\n';
}