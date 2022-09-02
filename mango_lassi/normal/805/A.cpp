#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b;
	std::cin >> a >> b;
	if (a == b) {
		std::cout << a << '\n';
	} else {
		std::cout << "2\n";
	}
}