#include <iostream>
#include <string>

std::string str;
char type = 0;
int total = 1;

int main() {
	std::cin >> str;
	if(str.length() < 7)
		std::cout << "NO" << std::endl;
	else {
		type = str[0];
		for(int i = 1; i < str.length(); i++) {
			if(str[i] == type)
				total++;
			else {
				type = str[i];
				total = 1;
			}
			if(total >= 7) {
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
		std::cout << "NO" << std::endl;
	}
}