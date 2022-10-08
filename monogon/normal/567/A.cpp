#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <numeric>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <iterator>

#define in std::cin
#define out std::cout
#define endl std::endl
#define MAX(a, b) std::max(a, b)
#define MAX3(a, b, c) std::max(a, std::max(b, c))
#define MIN(a, b) std::min(a, b)
#define MIN3(a, b, c) std::min(a, std::min(b, c))
#define MAXE(a, b) a = std::max(a, b)
#define MINE(a, b) a = std::min(a, b)
#define GETBIT(a, n) ((a >> n) & 1)
#define BITCOUNT(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define MP(a, b) std::make_pair(a, b)
#define PII std::pair<int, int>
#define PSI std::pair<std::string, int>
#define PIS std::pair<int, std::string>
#define PSS std::pair<std::string, std::string>
#define SI std::set<int>
#define SS std::set<std::string>
#define SPII std::set<std::pair<int, int> >
#define SPSI std::set<std::pair<std::string, int> >
#define SPIS std::set<std::pair<int, std::string> >
#define SPSS std::set<std::pair<std::string, std::string> >
#define MSI std::multiset<int>
#define MSS std::multiset<std::string>
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MSIII std::multiset<int>::iterator
#define MSSI std::multiset<std::string>::iterator
#define MAPII std::map<int, int>
#define MAPSS std::map<std::string, std::string>
#define MAPIS std::map<int, std::string>
#define MAPSI std::map<std::string, int>

int n, a;
SPII cities; //city pos, index
int min[100000];
int max[100000];

bool forAdjacent(PII a, PII b) {
	MINE(min[a.second], b.first - a.first);
	MINE(min[b.second], b.first - a.first);
	return false;
}
void forEach(PII p) {
	MAXE(max[p.second], p.first - (*cities.begin()).first);
	MAXE(max[p.second], (*(--cities.end())).first - p.first);
}

int main() {
	in >> n;
	for(int i = 0; i < n; i++)
		min[i] = 2e9;
	for(int i = 0; i < n; i++) {
		in >> a;
		cities.insert(MP(a, i));
	}
	std::adjacent_find(cities.begin(), cities.end(), forAdjacent);
	std::for_each(cities.begin(), cities.end(), forEach);
	for(int i = 0; i < n; i++) {
		out << min[i] << " " << max[i] << endl;
	}
}