#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;

int n;
map <string, ii> M;
int res = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		map <string, int> my;
		for (int j = int(s.length()) - 1; j >= 0; j--) {
			string nw = s.substr(j) + s.substr(0, j);
			my[nw] = j;
		}
		for (map <string, int>::iterator it = my.begin(); it != my.end(); it++)
			M[it->first] = ii(M[it->first].first + 1, M[it->first].second + it->second);
	}
	for (map <string, ii>::iterator it = M.begin(); it != M.end(); it++)
		if (it->second.first == n) res = min(res, it->second.second);
	if (res >= Inf) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}