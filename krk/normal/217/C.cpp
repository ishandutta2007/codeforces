#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int n;
string s;

ii getRes(const string &s, int &pnt)
{
	char c = s[pnt++];
	if (c == '0') return ii(0, 1);
	if (c == '1') return ii(1, 1);
	if (c == '?') return ii(2, 2);
	ii p1 = getRes(s, pnt);
	c = s[pnt++];
	ii p2 = getRes(s, pnt);
	pnt++;
	ii res;
	if (c == '^') {
		if (p1 > p2) swap(p1, p2);
		if (p2.first < 2) return ii(p1.first ^ p2.first, 1);
		if (p1.first < 2) return ii(2, p2.second);
		if (p1.second == 3 || p2.second == 3) return ii(2, 3);
		if (p1.second != p2.second) return ii(2, 2);
		return ii(2, 1);
	}
	if (c == '&') {
		if (p1 > p2) swap(p1, p2);
		if (p2.first < 2) return ii(p1.first & p2.first, 1);
		if (p1.first == 0) return ii(0, 1);
		if (p1.first == 1) return ii(2, p2.second);
		return ii(2, p1.second | p2.second | 1);
	}
	if (c == '|') {
		if (p1 > p2) swap(p1, p2);
		if (p2.first < 2) return ii(p1.first | p2.first, 1);
		if (p1.first == 0) return ii(2, p2.second);
		if (p1.first == 1) return ii(1, 1);
		return ii(2, p1.second | p2.second | 1);
	}
}

int main()
{
	cin >> n >> s;
	int pnt = 0;
	ii res = getRes(s, pnt);
	printf("%s\n", res.second & 2? "YES": "NO");
	return 0;
}