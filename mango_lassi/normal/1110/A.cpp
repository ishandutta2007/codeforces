#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int b, k;
	cin >> b >> k;

	bool even = true;
	for (int i = 0; i < k; ++i) {
		int val;
		cin >> val;
		if (val % 2 != 0) {
			if (i == k-1 || (b % 2 != 0)) even ^= 1;
		}
	}
	if (even) cout << "even\n";
	else cout << "odd\n";
}