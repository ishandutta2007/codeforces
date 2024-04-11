#include <iostream>

int N;
int a;
int p[101];

int main() {
	std::cin >> N;
	for(int i = 1; i <= N; i++) {
		std::cin >> a;
		p[a] = i;
	}
	for(int i = 1; i < N; i++) {
		std::cout << p[i] << " ";
	}
	std::cout << p[N] << std::endl;
}