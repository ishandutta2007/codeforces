#include <iostream>
#include <string>

int main() {
	int n;
	std::string str;
	std::cin >> n >> std::ws;
	std::getline(std::cin, str);
	int max = 0;
	char min_cap = 'A';
	char max_cap = 'Z';
	int i = 0;
	while(i < n) {
		int offer = 0;
		while((i < n) && (str[i] != ' ')) {
			if ( (min_cap <= str[i]) && (str[i] <= max_cap) ) {
				++offer;
			}
			++i;
		}
		max = std::max(offer, max);
		++i;
	}
	std::cout << max << '\n';
}