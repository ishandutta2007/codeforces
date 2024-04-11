#include <iostream>

int N, M;

int main() {
	std::cin >> N >> M;
	int i;
	for(i = 1; N > 0; i++) {
		N--;
		if(i % M == 0)
			N++;
	}
	std::cout << i - 1 << std::endl;
}