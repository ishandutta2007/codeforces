#include <iostream>

int main() {
	std::string str;
	std::cin >> str;
	int n = str.size();
	int ans = n;
	for (ans = n; ans > 0; --ans) {
		for (int a = 0; a + ans <= n; ++a) {
			int b = a + ans - 1;
			bool pal = true;
			for (int i = 0; i < ans / 2; ++i) {
				if (str[a + i] != str[b - i]) pal = false;
			}
			if (!pal) {
				std::cout << ans << '\n';
				return 0;
			}
		}
	}
	std::cout << 0 << '\n';
}