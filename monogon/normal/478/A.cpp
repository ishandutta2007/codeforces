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

int x[5];
int tot;

int main() {
	for(int i = 0; i < 5; i++) {
		std::cin >> x[i];
		tot += x[i];
	}
	if(tot > 0 && tot % 5 == 0)
		std::cout << tot / 5;
	else
		std::cout << -1;
}