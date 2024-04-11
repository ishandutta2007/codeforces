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

int n, a, b, c;
int t[4001];

int main() {
	in >> n >> a >> b >> c;
	for(int i = 1; i <= n; i++) {
		if((a < i && t[i - a] > 0) || a == i)
			MAXE(t[i], 1 + t[i - a]);
		if((b < i && t[i - b] > 0) || b == i)
			MAXE(t[i], 1 + t[i - b]);
		if((c < i && t[i - c] > 0) || c == i)
			MAXE(t[i], 1 + t[i - c]);
	}
	out << t[n];
}