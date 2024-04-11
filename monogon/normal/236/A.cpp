#include <iostream>
#include <string>

std::string str;

int main() {
	std::cin >> str;
	for(int i = 0; i < str.length(); i++) {
		for(int j = 0; j < i; j++) {
			if(str[i] == str[j]) {
				str.erase(str.begin() + i);
				i--;
				break;
			}
		}
	}
	std::cout << (str.length() % 2 ? "IGNORE HIM!" : "CHAT WITH HER!") << std::endl;
}