#include <iostream>
#include <string>

std::string line;
int count[4];

int main() {
	std::cin >> line;
	for(int i = 0; i < line.length(); i++) {
		if(line[i] != '+')
			count[line[i] - '0']++;
	}
	for(int i = 1; i <= 3; i++) {
		while(count[i]-- > 0) {
			std::cout << i;
			if(count[1] > 0 || count[2] > 0 || count[3] > 0)
				std::cout << "+";
		}
	}
	std::cout << std::endl;
}