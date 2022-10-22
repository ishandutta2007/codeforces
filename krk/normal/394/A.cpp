#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string a, b, c;

void Print(int a, int b, int c)
{
	printf("%s+%s=%s\n", string(a, '|').c_str(), string(b, '|').c_str(), string(c, '|').c_str());
}

int main()
{
	getline(cin, a, '+'); getline(cin, b, '='); getline(cin, c);
	if (a.length() + b.length() == c.length()) Print(a.length(), b.length(), c.length());
	else if (a.length() + b.length() - 1 == c.length() + 1) 
			if (a.length() >= b.length()) Print(a.length() - 1, b.length(), c.length() + 1);
			else Print(a.length(), b.length() - 1, c.length() + 1);
	else if (a.length() + 1 + b.length() == c.length() - 1) Print(a.length() + 1, b.length(), c.length() - 1);
	else printf("Impossible\n");
	return 0;
}