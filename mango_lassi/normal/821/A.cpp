#include <iostream>

const int N = 50;
int num[N][N];

int main() {

	int n;
	std::cin >> n;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			std::cin >> num[x][y];
		}
	}

	bool fail = false;
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			bool found = false;
			if (num[x][y] == 1) continue;
			for (int s = 0; s < n; ++s) {
				for (int e = 0; e < n; ++e) {
					if (num[x][s] + num[e][y] == num[x][y]) {
						found = true;
					}
				}
			}
			if (! found) {
				fail = true;
			}
		}
	}
	if (fail) {
		std::cout << "No\n";
	} else {
		std::cout << "Yes\n";
	}
}