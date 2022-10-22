#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

map <string, set <string> > M;
int n;
string nam;
int cnt;

int main()
{
	scanf("%d", &n);
	while (n--) {
		cin >> nam >> cnt;
		for (int i = 0; i < cnt; i++) {
			string tmp; cin >> tmp;
			M[nam].insert(tmp);
		}
	}
	printf("%d\n", int(M.size()));
	for (map <string, set <string> >::iterator it = M.begin(); it != M.end(); it++) {
		set <string> S = it->second;
		for (set <string>::iterator t = S.begin(); t != S.end(); ) {
			bool ok = true;
			for (set <string>::iterator it2 = S.begin(); it2 != S.end() && ok; it2++) if (t != it2) {
				int len1 = (*t).length(), len2 = (*it2).length();
				if (len1 <= len2 && (*it2).substr(len2 - len1) == *t) ok = false;
			}
			if (ok) t++;
			else S.erase(t++);
		}
		printf("%s %d", it->first.c_str(), int(S.size()));
		for (set <string>::iterator it = S.begin(); it != S.end(); it++)
			printf(" %s", (*it).c_str());
		printf("\n");
	}
	return 0;
}