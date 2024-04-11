#include <iostream>
#include <algorithm>

int N;
int a[100];
int sum;
int total;
int coins;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a[i];
		total += a[i];
	}
	std::sort(a, a + N);
	for(int i = N - 1; i >= 0; i--) {
		if(sum <= total / 2) {
			coins++;
			sum += a[i];
		}
	}
	std::cout << coins << std::endl;
}