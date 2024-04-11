#include <iostream>
#include <string>

int N, M;

int main() {
	std::cin >> N >> M;
	for(int i = 0; i < N; i++) {
		if(i % 2 == 0)
			std::cout << std::string(M, '#') << std::endl;
		else if(i % 4 == 1)
			std::cout << std::string(M - 1, '.') << '#' << std::endl;
		else
			std::cout << '#' << std::string(M - 1, '.') << std::endl;
	}
}