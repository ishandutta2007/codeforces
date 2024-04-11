#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	if (a < b) swap(a, b);

	int res = 0;
	while(a <= n) {
		b += a;
		swap(a, b);
		++res;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}