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
		int a, b, n;
		cin >> a >> b >> n;
		if (n % 3 == 0) cout << a << '\n';
		else if (n % 3 == 1) cout << b << '\n';
		else cout << (a^b) << '\n';
	}
}