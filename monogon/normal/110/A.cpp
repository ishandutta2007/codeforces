#include <iostream>
#include <string>

std::string str;
int count;

bool isLucky(int num) {
	if(num == 4 || num == 7)
		return true;
	else if(num == 0)
		return false;
	return (num % 10 == 4 || num % 10 == 7) && isLucky(num / 10);
}

int main() {
	std::cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == '4' || str[i] == '7')
			count++;
	}
	std::cout << (isLucky(count) ? "YES" : "NO") << std::endl;
}