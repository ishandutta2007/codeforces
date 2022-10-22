#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main()
{
	cin >> s;
	if (s[0] == 'f') { printf("ftp://"); s.erase(0, 3); }
	else { printf("http://"); s.erase(0, 4); }
	int p = s.find("ru", 1);
	printf("%s.ru", s.substr(0, p).c_str());
	p += 2;
	if (p < s.length()) printf("/%s", s.substr(p).c_str());
	printf("\n");
	return 0;
}