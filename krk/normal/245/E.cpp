#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int cur;
int res;

int main()
{
	cin >> s;
	for (int i = s.length() - 1; i >= 0; i--)
		if (s[i] == '+') cur = max(0, cur - 1);
		else cur++;
	res = cur;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '+') { cur++; res = max(res, cur); }
		else cur--;
	printf("%d\n", res);
	return 0;
}