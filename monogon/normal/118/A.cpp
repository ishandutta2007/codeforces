
#include <iostream>
#include <cctype>
#include <string>

std::string str;

int main() {
	std::cin >> str;
	for(int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
		switch(str[i]) {
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
			str.erase(str.begin() + i);
			i--;
			break;
		default:
			str.insert(i, ".");
			i++;
			break;
		}
	}
	std::cout << str << std::endl;
}