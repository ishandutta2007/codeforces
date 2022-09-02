#include <iostream>

int abs(int a) {
	return a < 0 ? -a : a;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int a, b;
	std::cin >> a >> b;
	
	if (((a == 0) && (b == 0)) || (abs(a-b) > 1)) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}