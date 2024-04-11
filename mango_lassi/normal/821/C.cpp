#include <iostream>
#include <stack>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	std::stack<int> s;
	int any = -1;
	int c = 0;
	int ind = 1;
	for (int i = 0; i < 2 * n; ++i) {
		std::string comm;
		std::cin >> comm;
		if (comm[0] == 'a') {
			int b;
			std::cin >> b;
			s.push(b);
		} else {
			if (any == s.size()) {
				s.pop();
				--any;
			} else if (s.top() == ind) {
				s.pop();
			} else {
				s.pop();
				any = s.size();
				++c;
			}
			++ind;
		}
	}
	std::cout << c << '\n';
}