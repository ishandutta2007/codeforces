#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string s;
int nil;
int res;

int main()
{
	getline(cin, s);
	for (int i = 0; i + 4 <= s.length(); i++)
		if (s.substr(i, 4) == "bear") {
			res += (i - nil + 1) * (s.length() - (i + 3));
			nil = i + 1;
		}
	printf("%d\n", res);
	return 0;
}