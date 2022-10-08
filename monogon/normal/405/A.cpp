#include <iostream>
#include <algorithm>

int N;
int a[100];

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a + N);
	for(int i = 0; i < N; i++) {
		std::cout << a[i] << " ";
	}
}