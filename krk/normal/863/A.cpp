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

bool Palin(const string &s)
{
	int l = 0, r = int(s.length()) - 1;
	while (l < r)
		if (s[l] != s[r]) return false;
		else l++, r--;
	return true;
}

int main()
{
	string x; cin >> x;
	bool ok = Palin(x);
	for (int i = 1; i < 50 && !ok; i++)
		if (Palin(string(i, '0') + x)) ok = true;
	printf("%s\n", ok? "YES": "NO");
	return 0;
}