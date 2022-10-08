#include <iostream>
#include <string>

std::string str1, str2;

int main() {
	std::cin >> str1 >> str2;
	if(str1.length() != str2.length()) {
		std::cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < str1.length(); i++) {
		if(str1[i] != str2[str2.length() - i - 1]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}