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

int k, r;

int main() {
	in >> k >> r;
	for(int amount = k; true; amount += k) {
		if(amount % 10 == r || amount % 10 == 0) {
			out << amount / k;
			break;
		}
	}
}