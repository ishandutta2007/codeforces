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

int n, m, k, count;
S s[500];

int parent[250000];
VI children[250000];
std::queue<int> q;

int dijkstra(int a) {
	std::queue<int> pq;
	for(int i = 0; i < n * m; i++) {
		parent[i] = -1;
	}
	pq.push(a);
	while(pq.size()) {
		int p = pq.front();
		pq.pop();
		//for each neightbor q
		int X = p % m;
		int Y = p / m;
		if(X > 0 && s[Y][X - 1] == '.' && parent[Y * m + X - 1] == -1 && Y * m + X - 1 != a) {
			parent[Y * m + X - 1] = p;
			pq.push(Y * m + X - 1);
		}
		if(X < m - 1 && s[Y][X + 1] == '.' && parent[Y * m + X + 1] == -1 && Y * m + X + 1 != a) {
			parent[Y * m + X + 1] = p;
			pq.push(Y * m + X + 1);
		}
		if(Y > 0 && s[Y - 1][X] == '.' && parent[(Y - 1) * m + X] == -1 && (Y - 1) * m + X != a) {
			parent[(Y - 1) * m + X] = p;
			pq.push((Y - 1) * m + X);
		}
		if(Y < n - 1 && s[Y + 1][X] == '.' && parent[(Y + 1) * m + X] == -1 && (Y + 1) * m + X != a) {
			parent[(Y + 1) * m + X] = p;
			pq.push((Y + 1) * m + X);
		}
	}
	return INT_MAX;
}

int main() {
	in >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		in >> s[i];
	}
	for(int i = 0; i < n * m; i++) {
		if(s[i / m][i % m] == '.') {
			dijkstra(i);
			break;
		}
	}
	for(int i = 0; i < n * m; i++) {
		if(parent[i] != -1) {
			children[parent[i]].push_back(i);
		}
	}
	for(int i = 0; i < n * m; i++) {
		if(s[i / m][i % m] == '.' && children[i].size() == 0) {
			q.push(i);
		}
	}
	while(count < k && q.size()) {
		int i = q.front();
		q.pop();
		count++;
		s[i / m][i % m] = 'X';
		if(parent[i] != -1) {
			children[parent[i]].erase(std::find(children[parent[i]].begin(), children[parent[i]].end(), i));
			if(children[parent[i]].size() == 0)
				q.push(parent[i]);
			parent[i] = -1;
		}
	}
	for(int i = 0; i < n; i++) {
		out << s[i] << endl;
	}
}