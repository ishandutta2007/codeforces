#include <iostream>
#include <string>

const long long mod = 1e9 + 7;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string str;
	std::cin >> str;
	long long bs = 0;
	long long res = 0;
	for (int i = str.size() - 1; i >= 0; --i) {
		if (str[i] == 'b') {
			++bs;
		} else {
			res += bs;
			res %= mod;
			bs *= 2;
			bs %= mod;
		}
	}
	std::cout << res << '\n';
}