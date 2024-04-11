#include <iostream>

int N;
bool lucky[1001];

bool isLucky(int num) {
	if(num == 4 || num == 7)
		return true;
	if(num == 0)
		return false;
	return (num % 10 == 4 || num % 10 == 7) && isLucky(num / 10);
}

int main() {
	std::cin >> N;
	for(int i = 0; i < 1000; i++) {
		if(isLucky(i)) {
			for(int j = 1; i * j <= 1000; j++) {
				lucky[i * j] = true;
			}
		}
	}
	std::cout << (lucky[N] ? "YES" : "NO") << std::endl;
}