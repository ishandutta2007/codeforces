#include <iostream>
#include <string>

std::string str;
std::string hello = "hello";
int index = 0;

int main() {
	std::cin >> str;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == hello[index])
			index++;
		if(index == hello.length())
			break;
	}
	std::cout << (index == hello.length() ? "YES" : "NO") << std::endl;
}