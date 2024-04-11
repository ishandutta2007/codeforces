#include <iostream>
#include <set>
#include <string>
#include <cctype>

std::set<int> chars;
int N;
std::string line;
char c;

int main() {
	std::cin >> N >> line;
	for(int i = 0; i < N; i++)
		chars.insert(tolower(line[i]));
	std::cout << (chars.size() == 26 ? "YES" : "NO");
}