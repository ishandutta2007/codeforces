#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

string s;
int cnt;

int main()
{
	cin >> s;
	int i = 0;
	while (i < s.length() && s[i] != '1') i++;
	for (int j = i; j < s.length(); j++)
		cnt += s[j] == '0';
	if (cnt >= 6) printf("yes\n");
	else printf("no\n");
	return 0;
}