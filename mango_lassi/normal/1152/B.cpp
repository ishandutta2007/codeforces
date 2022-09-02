#include <iostream>
#include <vector>
using namespace std;

bool ispt(int v) {
	for (int j = 0; (1<<j) <= v; ++j) {
		if ((1<<j) == v) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// Set it to zero
	int x;
	cin >> x;

	// 32 16 8 4 2 1
	// 100111
	// 011001
	// 000111
	// 000001

	// 5 4 2

	vector<int> ops;
	if ((x & 1) == 0) {
		ops.push_back(0);
		x += 1;
	}
	
	for (int j = 29; j > 0; --j) {
		if (x & (1<<j)) {
			ops.push_back(j+1);
			x ^= (1<<(j+1)) - 1;
			x += 1;
		}
	}
	cout << 2 * ops.size() << '\n';
	for (auto v : ops) cout << v << ' '; cout << '\n';
}