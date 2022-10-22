#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string a, b;

int main()
{
	getline(cin, a, '|');
	getline(cin, b);
	char ch;
	while (scanf(" %c", &ch) == 1)
		if (a.length() <= b.length()) a += ch;
		else b += ch;
	if (a.length() == b.length())
		printf("%s|%s\n", a.c_str(), b.c_str());
	else printf("Impossible\n");
	return 0;
}