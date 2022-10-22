#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

string s;
string a, b;

bool checkNum(const string &s)
{
	if (s.length() == 0) return false;
	for (int i = 0; i < s.length(); i++)
		if (!isdigit(s[i])) return false;
	if (s.length() > 1 && s[0] == '0') return false;
	return true;
}

int main()
{
	cin >> s;
	int pnt = 0;
	while (pnt <= s.length()) {
		int old = pnt;
		while (pnt < s.length() && s[pnt] != ',' && s[pnt] != ';') pnt++;
		string tmp = s.substr(old, pnt - old);
		if (checkNum(tmp)) a += tmp + ",";
		else b += tmp + ",";
		pnt++;
	}
	if (a.length() == 0) printf("-\n");
	else printf("\"%s\"\n", a.substr(0, a.length() - 1).c_str());
	if (b.length() == 0) printf("-\n");
	else printf("\"%s\"\n", b.substr(0, b.length() - 1).c_str());
	return 0;
}