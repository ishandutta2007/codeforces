#include <iostream>
#include <algorithm>

int N;
int a, b;
int max;
int passengers;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a >> b;
		passengers += b - a;
		max = std::max(max, passengers);
	}
	std::cout << max << std::endl;
}