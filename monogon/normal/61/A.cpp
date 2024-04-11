#include <iostream>
#include <string>

std::string str1, str2;
bool b[100];

int main() {
	std::cin >> str1 >> str2;
	for(int i = 0; i < str1.length(); i++) {
		std::cout << ((str1[i] == '1') ^ (str2[i] == '1'));
	}
}