#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const string wovs = "AEIOUY";

string s;

int main()
{
	int lst = -1, res = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		if (wovs.find(s[i]) != string::npos) {
			res = max(res, i - lst);
			lst = i;
		}
	res = max(res, int(s.length()) - lst);
	printf("%d\n", res);
	return 0;
}