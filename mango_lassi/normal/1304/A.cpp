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
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		
		ll d = y-x;
		if (d % (a+b) == 0) cout << d / (a+b) << '\n';
		else cout << -1 << '\n';
	}
	
}