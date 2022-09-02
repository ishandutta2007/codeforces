#include <iostream>

const int P = 22;
int F [1<<P];
const int N = 1e6;
int Q [N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cin >> Q[i];
		F[Q[i]] = Q[i];
	}
	for (int i = 0; i < P; ++i) {
		for (int mask = 0; mask < (1<<P); ++mask) {
			if ( (mask & (1<<i) ) && (F[mask ^ (1<<i)]) ) F[mask] = F[mask ^ (1<<i)];
		}
	}
	int mask = (1<<P)-1;
	for (int i = 0; i < n; ++i) {
		if (F[mask ^ Q[i]]) {
			std::cout << F[mask ^ Q[i]] << ' ';
		} else {
			std::cout << "-1 ";
		}
	}
	std::cout << '\n';
}