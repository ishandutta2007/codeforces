#include <iostream>
#include <string>
#include <sstream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	std::cin >> n;
	std::string a = "a";
	std::string b = "b";
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		if ((i % 4 == 0) ||(i % 4 == 1)) {
			ss << a;
		} else {
			ss << b;
		}
	}
	std::string res;
	ss >> res;
	std::cout << res << '\n';
}