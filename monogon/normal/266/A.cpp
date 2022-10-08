#include <iostream>
#include <string>

int N;
std::string str;
int sum;

int main() {
	std::cin >> N >> str;
	for(int i = 0; i < N - 1; i++) {
		if(str[i] == str[i + 1])
			sum++;
	}
	std::cout << sum;
}