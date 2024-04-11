
#include <iostream>
#include <string>
#include <cctype>

std::string a, b;

int main() {
	std::cin >> a >> b;
	for(int i = 0; i < a.length(); i++) {
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
	}
	if(a < b) std::cout << -1 << std::endl;
	else if(a > b) std::cout << 1 << std::endl;
	else std::cout << 0 << std::endl;
}