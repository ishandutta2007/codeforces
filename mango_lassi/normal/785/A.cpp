#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;
		if (str == "Tetrahedron") {
			count += 4;
		} else if (str == "Cube") {
			count += 6;
		} else if (str == "Octahedron") {
			count += 8;
		} else if (str == "Dodecahedron") {
			count += 12;
		} else {
			count += 20;
		}
	}
	std::cout << count << '\n';
}