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

	int ones = 0;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v == 1) ++ones;
	}
	int twos = n - ones;

	if (twos > 0) {
		cout << 2 << ' ';
		--twos;
	}
	if (ones > 0) {
		cout << 1 << ' ';
		--ones;
	}
	while(true) {
		if (twos > 0) {
			cout << 2 << ' ';
			--twos;
		} else if (ones > 0) {
			cout << 1 << ' ';
			--ones;
		} else {
			break;
		}
	}
	cout << '\n';
}