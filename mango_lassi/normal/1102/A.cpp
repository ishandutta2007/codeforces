#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// 1
	// -> 1 (4) is 1
	// 1 | 2
	// -> 2 (4) is 1
	// 1 2 | 3
	// -> 3 (4) is 0
	// 1 4 | 2 3
	// -> 0 (4) is 0
	
	if (n % 4 == 1 || n % 4 == 2) {
		cout << 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
}