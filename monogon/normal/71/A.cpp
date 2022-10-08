
#include <iostream>
#include <string>

std::string str;
int N;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> str;
		if(str.length() <= 10)
			std::cout << str << std::endl;
		else
			std::cout << str[0] << str.length() - 2 << str[str.length() - 1] << std::endl;
	}
}