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

	// Done this way, the rows always have xor zero, but columns don't!
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			int xa = x % 4;
			int xb = x / 4;
			int ya = y % 4;
			int yb = y / 4;
			cout << ((xa + ya * 4) + 16*(xb + yb * (n/4))) << ' ';
		}
		cout << '\n';
	}
}