#include <iostream>
#include <string>

int main() {
	std::string a;
	std::string b;
	std::cin >> a >> b;
	if (a.size() == b.size()) {
		bool same = true;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) {
				same = false;
				break;
			}
		}
		if (same) {
			std::cout << "-1\n";
		} else {
			std::cout << a.size() << "\n";
		}
	} else {
		if (a.size() > b.size()) {
			std::cout << a.size() << "\n";
		} else {
			std::cout << b.size() << "\n";
		}
	}
}