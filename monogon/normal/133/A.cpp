#include <iostream>
#include <string>

std::string str;

int main() {
	std::cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9') {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;
}