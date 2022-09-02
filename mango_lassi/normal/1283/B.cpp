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
		ll n, k;
		cin >> n >> k;
		ll x = k * (n/k);
		ll y = min(n-x, k/2);
		cout << x+y << '\n';
	}
}