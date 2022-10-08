#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

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
std::string str1, str2;
int total;

int main() {
	in >> n >> str1 >> str2;
	for(int i = 0; i < n; i++) {
		total += std::min(((str2[i] - str1[i]) % 10 + 10) % 10, ((str1[i] - str2[i]) % 10 + 10) % 10);
	}
	std::cout << total;
}