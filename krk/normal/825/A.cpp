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

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	int res = 0;
	for (int i = 0, j; i <= s.length(); i = j + 1) {
		j = i;
		while (j < s.length() && s[j] == '1') j++;
		res = 10 * res + (j - i);
	}
	printf("%d\n", res);
	return 0;
}