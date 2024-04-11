#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	ll low;
	if (k % 2 == 0) {
		 low = k/2 + 1;
	} else {
		low = (k+1)/2;
	}
	ll high = min(n, k-1);
	ll res = high - low + 1;
	if (res < 0) res = 0;
	cout << res << '\n';
}