#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, t;
string s;

void incByOne(string &s)
{
	int pnt = int(s.length()) - 1;
	while (pnt >= 0 && s[pnt] == '9')
		s[pnt--] = '0';
	if (pnt >= 0) s[pnt]++;
	else s = "1" + s;
}

int main()
{
	cin >> n >> t;
	cin >> s;
	int pos = s.find('.');
	int ind = pos + 1;
	while (ind < s.length() && s[ind] < '5') ind++;
	if (ind >= s.length()) printf("%s\n", s.c_str());
	else {
		int lst = s.length();
		while (ind > pos && s[ind] >= '5' && t) {
			if (ind - 1 == pos) {
				s = s.substr(0, pos);
				incByOne(s);
				printf("%s\n", s.substr().c_str());
				return 0;
			}
			s[ind - 1]++;
			for (int j = ind; j < lst; j++)
				s[j] = '0';
			lst = ind; ind--; t--;
		}
		lst = int(s.length()) - 1;
		while (s[lst] == '0') lst--;
		printf("%s\n", s.substr(0, lst + 1).c_str());
	}
	return 0;
}