#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	char ch = 'a';
	for (int i = 0; i < s.length() && ch <= 'z'; i++)
		if (s[i] <= ch) { s[i] = ch; ch++; }
	if (ch <= 'z') printf("-1\n");
	else printf("%s\n", s.c_str());
	return 0;
}