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
int res;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		for (int j = i + 1; j < s.length(); j++)
			for (int k = j + 1; k < s.length(); k++)
				res += s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q';
	printf("%d\n", res);
	return 0;
}