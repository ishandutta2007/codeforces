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
int cups, medals;
int a;

int main() {
	for(int i = 0; i < 3; i++) {
		in >> a;
		cups += a;
	}
	for(int i = 0; i < 3; i++) {
		in >> a;
		medals += a;
	}
	in >> n;
	out << (cups / 5 + (cups % 5 > 0) + medals / 10 + (medals % 10 > 0) <= n ? "YES" : "NO");
}