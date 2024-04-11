#include <iostream>
#include <string>

std::string str;

bool inSet[26];
int count = 0;

int main() {
	std::getline(std::cin, str);
	for(int i = 0; i < str.length(); i++) {
		if(str[i] >= 'a' && str[i] <= 'z' && !inSet[str[i] - 'a']) {
			inSet[str[i] - 'a'] = 1;
			count++;
		}
	}
	std::cout << count;
}