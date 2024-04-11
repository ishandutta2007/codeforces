#include <iostream>

int N;
int sum = 0;
std::string line;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> line;
		if(line[1] == '+') sum++;
		else sum--;
	}
	std::cout << sum;
}