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

const int Maxd = 3;

int mn = 100;
string a, b;

int Sum(int x)
{
	int res = 0;
	while (x) {
		res += x % 10;
		x/= 10;
	}
	return res;
}

int Get(const string &s, int num)
{
	int res = (int(s[0] - '0') != num / 100) + (int(s[1] -'0') != num / 10 % 10) + (int(s[2] - '0') != num % 10);
	return res;
}

int main()
{
	string s; cin >> s;
	a = s.substr(0, 3); b = s.substr(3);
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++) if (Sum(i) == Sum(j))
			mn = min(mn, Get(a, i) + Get(b, j));
	printf("%d\n", mn);
	return 0;
}