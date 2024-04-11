#include <iostream>
#include <sstream>
#include <string>

int N;
std::string str;

bool distinct(int N) {
	std::stringstream ss;
	ss << N;
	str = ss.str();
	for(int i = 0; i < str.length(); i++) {
		for(int j = 0; j < i; j++) {
			if(str[i] == str[j])
				return false;
		}
	}
	return true;
}

int main() {
	std::cin >> N;
	while(true) {
		N++;
		if(distinct(N))
			break;
	}
	std::cout << N;
}