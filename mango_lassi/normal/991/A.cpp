#include <iostream>

int main() {
	int a, b, c, n;
	std::cin >> a >> b >> c >> n;
	int res = n - (a + b - c);
	if (c > a || c > b || res <= 0) {
		std::cout << "-1\n";
	} else {
		std::cout << res << '\n';
	}
}