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

string s;
string nw;

bool Pal(const string &s)
{
	int l = 0, r = int(s.length()) - 1;
	while (l < r)
		if (s[l] != s[r]) return false;
		else l++, r--;
	return true;
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		nw = s;
		for (char ch = 'a'; ch <= 'z'; ch++) if (ch != s[i]) {
			nw[i] = ch;
			if (Pal(nw)) { printf("YES\n"); return false; }
		}
	}
	printf("NO\n");
	return 0;
}