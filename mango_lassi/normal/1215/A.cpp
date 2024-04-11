#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a1, a2, n;
	int k1, k2;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	
	// Minimum
	int r = n - a1 * (k1 - 1) - a2 * (k2 - 1);
	cout << max(r, 0) << ' ';

	// Maximum
	if (k2 < k1) {
		swap(a1, a2);
		swap(k1, k2);
	}
	int out = 0;
	int cou = min(a1, n / k1);
	out += cou;
	n -= k1 * cou;

	cou = min(a2, n / k2);
	out += cou;
	n -= k2 * cou;

	cout << out << '\n';
}