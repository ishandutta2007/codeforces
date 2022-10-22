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

string heidi = "heidi";
string s;

int main()
{
	cin >> s;
	int p = 0;
	for (int i = 0; i < s.length(); i++)
		if (p < heidi.length() && s[i] == heidi[p]) p++;
	printf("%s\n", p >= heidi.length()? "YES": "NO");
	return 0;
}