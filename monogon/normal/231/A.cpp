
#include <iostream>

int N;
int a, b, c;
int sum = 0;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a >> b >> c;
		if(a + b + c > 1) sum++;
	}
	std::cout << sum;
}