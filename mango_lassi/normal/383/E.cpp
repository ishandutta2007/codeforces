#include <iostream>
#include <string>

const int C = 24;
int F [1<<C];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::string str;
		std::cin >> str;
		int a = 1<<((int)(str[0] - 'a'));
		int b = 1<<((int)(str[1] - 'a'));
		int c = 1<<((int)(str[2] - 'a'));
		// Inclusion / Exclusion
		++F[a];
		++F[b];
		++F[c];
		--F[a|b];
		--F[a|c];
		--F[b|c];
		++F[a|b|c];
	}

	for (int i = 0; i < C; ++i) {
		for (int mask = 0; mask < (1<<C); ++mask) {
			if (mask & (1<<i)) {
				F[mask] += F[mask ^ (1<<i)];
			}
		}
	}

	long long res = 0;
	for (int i = 1; i < (1<<C); ++i) {
		//std::cout << i << ' ' << F[i] << '\n';
		res ^= ((long long)F[i]) * F[i];
	}
	std::cout << res << '\n';
}