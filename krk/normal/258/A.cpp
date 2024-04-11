#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	getline(cin, s);
	int i = 0;
	while (i < s.length() && s[i] != '0') i++;
	if (i == s.length()) i--;
	for (int j = 0; j < i; j++)
		printf("%c", s[j]);
	for (int j = i + 1; j < s.length(); j++)
		printf("%c", s[j]);
	printf("\n");
	return 0;
}