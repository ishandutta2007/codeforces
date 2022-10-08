#include <iostream>

int n;
int a, b, sum = 1;

int main() {
	std::cin >> n;
	std::cin >> a;
	for(int i = 1; i < n; i++) {
		std::cin >> b;
		if(a != b)
			sum++;
		std::swap(a, b);
	}
	std::cout << sum << std::endl;
}