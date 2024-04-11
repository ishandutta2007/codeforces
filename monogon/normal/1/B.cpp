#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>

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

int n;
S s;
int changes;
int id[4];

S toRC() {
	Ss ss(s.substr(id[1]));
	int row = 0;
	ss >> row;
	int col = 0;
	S first = s.substr(0, id[1]);
	for(unsigned int i = 0; i < first.length(); i++) {
		col += (first[i] - 'A' + 1) * round(pow(26, first.length() - i - 1));
	}
	ss.clear();
	ss << "R" << row << "C" << col;
	return ss.str();
}
S toA1() {
	Ss ss;
	ss << s.substr(id[1], id[2] - id[1]) << " " << s.substr(id[3]);
	int row = 0;
	int col = 0;
	ss >> row >> col;
	ss.str(""); ss.clear();
	while(col > 0) {
		ss << (char) (((--col) % 26) + 'A');
		col /= 26;
	}
	S res;
	ss >> res;
	ss.str(""); ss.clear();
	std::reverse(res.begin(), res.end());
	ss << res << row;
	return ss.str();
}

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> s;
		changes = 0;
		for(unsigned int j = 1; j < s.length(); j++) {
			if((s[j] >= 'A' && s[j] <= 'Z') != (s[j - 1] >= 'A' && s[j - 1] <= 'Z')) {
				changes++;
				id[changes] = j;
			}
		}
		if(changes == 1) {
			out << toRC() << endl;
		}else
			out << toA1() << endl;
	}
}