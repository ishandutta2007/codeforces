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

const int Maxl = 26;
const string vows = "aeiou";

bool cons[Maxl];
string s;
bool was;

void Print(const string &s)
{
	if (was) printf(" ");
	was = true;
	printf("%s", s.c_str());
}

int main()
{
	fill(cons, cons + Maxl, true);
	for (int i = 0; i < vows.size(); i++)
		cons[vows[i] - 'a'] = false;
	cin >> s;
	int tot = 0, wh = -1;
	string pr = "";
	for (int i = 0; i < s.length(); i++) {
		if (cons[s[i] - 'a']) {
			tot++;
			if (wh == -1) wh = s[i] - 'a';
			if (tot >= 3 && wh != s[i] - 'a') {
				Print(pr); pr = string(1, s[i]);
				tot = 1; wh = s[i] - 'a';
			} else {
				pr += string(1, s[i]);
				if (wh != s[i] - 'a') wh = -2;
			}
		} else { tot = 0; wh = -1; pr += string(1, s[i]); }
	}
	if (pr.size() > 0) Print(pr);
	printf("\n");
	return 0;
}