#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, first, last;
	std::cin >> n >> first;
	if (n != 1) {
		for (int i = 1; i < n; ++i) {
			std::cin >> last;
		}
	} else {
		last = first;
	}
	if (n & first & last & 1) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}