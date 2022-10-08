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
bool a[100];
int count = 0;
int count2 = 0;
int max = -1000;

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> a[i];
		if(a[i]) count2++;
	}
	for(int i = 0; i < n; i++) {
		count = 0;
		for(int j = i; j < n; j++) {
			if(a[j]) count--;
			else count++;
			MAXE(max, count);
		}
	}
	out << max + count2;
}