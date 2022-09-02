#include <iostream>

const int C = 26;
const int N = 4 * (int)(1e5);
int ind(char c) {
	return c - 'a';
}
int cou[C];
int rem[C];
char str[N];

int main() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		std::cin >> str[i];
		++cou[ind(str[i])];
	}
	int ci = 0;
	for (int i = 0; i < k; ++i) {
		while (cou[ci] == 0) ++ci;
		--cou[ci];
		++rem[ci];
	}
	for (int i = 0; i < n; ++i) {
		if (rem[ind(str[i])] > 0) {
			--rem[ind(str[i])];
		} else {
			std::cout << str[i];
		}
	}
	std::cout << '\n';
}