#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s;
int val;

int main()
{
	cin >> s >> val;
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	for (int i = 0; i < s.length(); i++)
		printf("%c", s[i] < val + 97? toupper(s[i]): tolower(s[i]));
	printf("\n");
	return 0;
}