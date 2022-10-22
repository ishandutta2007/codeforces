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
int pnt;

int getNum()
{
	int res = 0;
	while (pnt < s.length() && s[pnt] != '+' && s[pnt] != '-') {
		res = 10 * res + (s[pnt] - '0'); pnt++;
	}
	return res;
}

void Print(int val)
{
	val += '0';
	while (val--) printf("+");
	printf(".");
	printf(">\n");
}

int main()
{
	cin >> s;
	int res = 0;
	res = getNum();
	while (pnt < s.length())
		if (s[pnt] == '+') { pnt++; res += getNum(); }
		else if (s[pnt] == '-') { pnt++; res -= getNum(); }
		else pnt++;
	if (res < 10) Print(res);
	else if (res < 100) { Print(res / 10); Print(res % 10); }
	else { Print(res / 100); Print(res % 100 / 10); Print(res % 10); }
	return 0;
}