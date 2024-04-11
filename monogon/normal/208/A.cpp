#include <iostream>
#include <string>

std::string line;
std::string output;

int main() {
	std::cin >> line;
	while(line.length() >= 3 && line.substr(0, 3) == "WUB")
		line = line.substr(3);
	while(line.length() >= 3 && line.substr(line.length() - 3) == "WUB")
		line = line.substr(0, line.length() - 3);
	while(line.length() > 0) {
		if(line.length() >= 3 && line.substr(0, 3) == "WUB") {
			line = line.substr(3);
			output += " ";
		}else {
			output += line[0];
			line = line.substr(1);
		}
	}
	std::cout << output << std::endl;
}