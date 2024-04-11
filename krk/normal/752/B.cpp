#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxl = 26;

set <char> C[Maxl];
bool ok[Maxl];
string s, t;

int main()
{
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++) if (s[i] != t[i]) {
		C[s[i] - 'a'].insert(t[i]);
		C[t[i] - 'a'].insert(s[i]);
	} else ok[s[i] - 'a'] = true;
	int cnt = 0;
	for (int i = 0; i < Maxl; i++) {
		if (C[i].size() + ok[i] > 1) { printf("-1\n"); return 0; }
		cnt += C[i].size();
	}
	printf("%d\n", cnt / 2);
	for (int i = 0; i < Maxl; i++)
		for (set <char>::iterator it = C[i].begin(); it != C[i].end(); it++)
			if ('a' + i < *it) printf("%c %c\n", 'a' + i, *it);
	return 0;
}