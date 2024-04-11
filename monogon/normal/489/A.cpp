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

//int n, a[3001], map[3001], map2[3001];
//VPII s;
//VPII swaps;

int n, a[3000];
VPII swaps;

int main() {
	in >> n;
	for(int i = 0; i < n; i++) {
		in >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int min = 1e9 + 1;
		int idx = i;
		for(int j = i; j < n; j++) {
			if(a[j] < min) {
				min = a[j];
				idx = j;
			}
		}
		if(idx != i) {
			std::swap(a[i], a[idx]);
			swaps.push_back(Mp(i, idx));
		}
	}
	out << swaps.size() << endl;
	for(int i = 0; i < swaps.size(); i++) {
		out << swaps[i].first << " " << swaps[i].second << endl;
	}
//	in >> n;
//	for(int i = 0; i < n; i++) {
//		map[i] = map2[i] = i;
//		in >> a[i];
//		s.push_back(Mp(a[i], i));
//	}
//	std::sort(s.begin(), s.end());
//	for(int i = 0; i < n; i++) {
//		if(s[i].first != a[i]) {
//			swaps.push_back(Mp(i, map2[s[i].second]));
//			std::swap(a[i], a[map2[s[i].second]]);
//			std::swap(map[i], map[map2[s[i].second]]);
//			std::swap(map2[map[i]], map2[map[map2[s[i].second]]]);
//		}
//	}
//	out << swaps.size() << endl;
//	for(int i = 0; i < swaps.size(); i++) {
//		out << swaps[i].first << " " << swaps[i].second << endl;
//	}
}