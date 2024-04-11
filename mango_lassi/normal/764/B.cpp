#include <iostream>

const int N = 2 * 1e5;
int result[N];

int main() {
	std::ios_base::sync_with_stdio(false);	
	std::cin.tie(0);

	int n;
	std::cin >> n;
	bool swaps = true;
	for (int i = 0; i < n; ++i, swaps = ! swaps) {
		if ((!(n & 1)) && (i == n/2)) {
			swaps = ! swaps;
		}
		int c;
		std::cin >> c;
		if (swaps) {
			result[n - i - 1] = c;
		} else {
			result[i] = c;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << result[i] << " ";
	}
	std::cout << "\n";
}