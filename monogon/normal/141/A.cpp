#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string str1, str2, str3;
std::vector<char> names, box;

int main() {
	std::cin >> str1 >> str2 >> str3;
	for(int i = 0; i < str1.length(); i++)
		names.push_back(str1[i]);
	for(int i = 0; i < str2.length(); i++)
		names.push_back(str2[i]);
	for(int i = 0; i < str3.length(); i++)
		box.push_back(str3[i]);
	std::sort(names.begin(), names.end());
	std::sort(box.begin(), box.end());
	if(names.size() != box.size())
		std::cout << "NO";
	else if(names == box)
		std::cout << "YES";
	else
		std::cout << "NO";
}