#include <iostream>

int num[4];
int N;
int sum = 0;

int main() {
	std::cin >> num[0] >> num[1] >> num[2] >> num[3] >> N;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 4; j++) {
			if(i % num[j] == 0) {
				sum++;
				break;
			}
		}
	}
	std::cout << sum;
}