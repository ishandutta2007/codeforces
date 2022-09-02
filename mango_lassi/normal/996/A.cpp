#include <iostream>

const int N = 5;

int main() {
	long long n;
	std::cin >> n;
	long long res = 0;
	int vals[N] = {100, 20, 10, 5, 1};
	for (int i = 0; i < N; ++i) {
		res += n / vals[i];
		n %= vals[i];
	}
	std::cout << res << '\n';
}