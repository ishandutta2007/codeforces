#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, z;
	std::cin >> n >> m >> z;
	int c = n;
	int count = 0;
	for (int i = m; i <= z; i += m) {
		while(c < i) {
			c += n;
		}
		if (c == i) {
			++count;
		}
	}
	std::cout << count << "\n";
}