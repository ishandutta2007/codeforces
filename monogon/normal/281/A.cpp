#include <iostream>
#include <string>
#include <cctype>

std::string str;

int main() {
	std::cin >> str;
	str[0] = toupper(str[0]);
	std::cout << str;
}