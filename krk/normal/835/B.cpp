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

int k;
string s;

int main()
{
	cin >> k;
	cin >> s; sort(s.begin(), s.end());
	int cur = 0;
	for (int i = 0; i < s.length(); i++)
		cur += s[i] - '0';
	int res = 0;
	while (cur < k) {
		cur += 9 - int(s[res] - '0');
		res++;
	}
	printf("%d\n", res);
	return 0;
}