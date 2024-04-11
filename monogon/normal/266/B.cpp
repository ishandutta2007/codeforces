#include <iostream>
#include <string>

int N, t;
std::string str;

int main() {
	std::cin >> N >> t >> str;
	for(int j = 0; j < t; j++) {
		for(int i = 0; i < N - 1; i++) {
			if(str[i] == 'B' && str[i + 1] == 'G') {
				str[i] = 'G';
				str[++i] = 'B';
			}
		}
	}
	std::cout << str << std::endl;
}