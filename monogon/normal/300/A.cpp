#include <bits/stdc++.h>

#define in std::cin
#define out std::cout
#define endl std::endl
#define Max(a, b) ((b) > (a) ? (b) : (a))
#define Max3(a, b, c) Max(a, Max(b, c))
#define Min(a, b) ((b) < (a) ? (b) : (a))
#define Min3(a, b, c) Min(a, Min(b, c))
#define MaxE(a, b) a = Max(a, b)
#define MinE(a, b) a = Min(a, b)
#define Getbit(a, n) ((a >> n) & 1)
#define Bitcount(a) __builtin_popcount(a)
#define S std::string
#define Ss std::stringstream
#define VI std::vector<int>
#define VS std::vector<std::string>
#define VPII std::vector<std::pair<int, int> >
#define VPSI std::vector<std::pair<std::string, int> >
#define VPIS std::vector<std::pair<int, std:;string> >
#define VPSS std::vector<std::pair<std::string, std::string> >
#define Mp(a, b) std::make_pair(a, b)
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
#define VII std::vector<int>::iterator
#define VSI std::vector<std::string>::iterator
#define VPIII std::vector<std::pair<int, int> >::iterator
#define VPISI std::vector<std::pair<int, std::string> >::iterator
#define VPSII std::vector<std::pair<std::string, int> >::iterator
#define VPSSI std::vector<std::pair<std::string, std::string> >::iterator
#define MsI std::multiset<int>
#define MsS std::multiset<std::string>
#define MsPII std::multiset<std::pair<int, int> >
#define MsPSI std::multiset<std::pair<std::string, int> >
#define MsPIS std::multiset<std::pair<int, std::string> >
#define MsPSS std::multiset<std::pair<std::string, std::string> >
#define SII std::set<int>::iterator
#define SPIII std::set<std::pair<int, int> >::iterator
#define SPSII std::set<std::pair<std::string, int> >::iterator
#define SPISI std::set<std::pair<int, std::string> >::iterator
#define SPSSI std::set<std::pair<std::string, std::string> >::iterator
#define MsII std::multiset<int>::iterator
#define MsSI std::multiset<std::string>::iterator
#define MsPIII std::multiset<std::pair<int, int> >::iterator
#define MsPSII std::multiset<std::pair<std::string, int> >::iterator
#define MsPISI std::multiset<std::pair<int, std::string> >::iterator
#define MsPSSI std::multiset<std::pair<std::string, std::string> >::iterator
#define MapII std::map<int, int>
#define MapSS std::map<std::string, std::string>
#define MapIS std::map<int, std::string>
#define MapSI std::map<std::string, int>
#define MapIII std::map<int, int>::iterator
#define MapSSI std::map<std::string, std::string>::iterator
#define MapISI std::map<int, std::string>::iterator
#define MapSII std::map<std::string, int>::iterator

int N, a, z, n, p;
VI g1, g2, g3;

int main() {
	in >> N;
	for(int i = 0; i < N; i++) {
		in >> a;
		if(a < 0) g1.push_back(a);
		if(a > 0) g2.push_back(a);
		if(a == 0) g3.push_back(a);
	}
	if(g2.size() == 0) {
		g2.push_back(g1[0]);
		g2.push_back(g1[1]);
		g1.erase(g1.begin());
		g1.erase(g1.begin());
	}
	if(g1.size() % 2 == 0) {
		g3.push_back(g1[0]);
		g1.erase(g1.begin());
	}
	out << g1.size() << " ";
	for(int i = 0; i < g1.size() - 1; i++) {
		out << g1[i] << " ";
	}
	out << g1[g1.size() - 1] << endl;
	out << g2.size() << " ";
	for(int i = 0; i < g2.size() - 1; i++) {
		out << g2[i] << " ";
	}
	out << g2[g2.size() - 1] << endl;
	out << g3.size() << " ";
	for(int i = 0; i < g3.size() - 1; i++) {
		out << g3[i] << " ";
	}
	out << g3[g3.size() - 1] << endl;
}