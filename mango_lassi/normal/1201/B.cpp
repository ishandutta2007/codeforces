#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll sum = 0;
	ll mx = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		sum += v;
		mx = max(mx, v);
	}
	if (sum % 2 == 0 && sum >= 2 * mx) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}