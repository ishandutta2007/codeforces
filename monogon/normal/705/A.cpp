#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define in std::cin
#define out std::cout
#define end std::endl
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define VI std::vector<int>
#define VS std::vector<std::string>
#define PII std::pair<int, int>
#define SI std::set<int>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator

int n;

int main() {
	in >> n;
	std::cout << "I hate ";
	for(int i = 1; i < n; i++) {
		std::cout << (i % 2 ? "that I love " : "that I hate ");
	}
	std::cout << "it";
}