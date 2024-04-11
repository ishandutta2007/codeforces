#include <iostream>
#include <string>
#include <cctype>

std::string str;
bool change;

int main() {
	std::cin >> str;
	change = true;
	for(int i = 1; i < str.length(); i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			change = false;
			break;
		}
	}
	if(change) {
		for(int i = 0; i < str.length(); i++) {
			if(str[i] >= 'a' && str[i] <= 'z')
				std::cout << (char) toupper(str[i]);
			else
				std::cout << (char) tolower(str[i]);
		}
		std::cout << std::endl;
	}else
		std::cout << str << std::endl;
}