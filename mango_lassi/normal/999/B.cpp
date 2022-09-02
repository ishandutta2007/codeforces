#include <iostream>

const int N = 100;
char arr[N];

void flip(int k) {
	for (int i = 0; i <= k-i-1; ++i) {
		std::swap(arr[i], arr[k-i-1]);
	}
}

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) flip(i);
	}
	for (int i = 0; i < n; ++i) std::cout << arr[i]; std::cout << '\n';
}