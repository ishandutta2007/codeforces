#include <iostream>

int N, T;
int a[30000];

int main() {
	std::cin >> N >> T;
	a[0] = 1;
	for(int i = 0; i < N - 1; i++) {
		std::cin >> a[i + 1];
	}
	int j;
	for(j = 0; j < T; j += a[j]);
	std::cout << (j == T ? "YES" : "NO");
}