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

const int Maxn = 70005;

char tmp[15];
int n;
string s[Maxn], best[Maxn];
map <string, ii> M;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Read(s[i]); best[i] = s[i];
		for (int j = 0; j < s[i].length(); j++)
			for (int l = 1; j + l <= s[i].length(); l++)
				M[s[i].substr(j, l)].second = i;
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < s[i].length(); j++)
			for (int l = 1; j + l <= s[i].length(); l++)
				M[s[i].substr(j, l)].first = i;
	for (map <string, ii>::iterator it = M.begin(); it != M.end(); it++) if (it->second.first == it->second.second) {
		int ind = it->second.first;
		if (it->first.size() < best[ind].size()) best[ind] = it->first;
	}
	for (int i = 0; i < n; i++)
		printf("%s\n", best[i].c_str());
	return 0;
}