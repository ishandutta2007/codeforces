#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
using namespace std;

string s;
bool a, b, c, d;

int main()
{
	cin >> s;
	a = s.length() >= 5;
	for (int i = 0; i < s.length(); i++) {
		b |= isupper(s[i]);
		c |= islower(s[i]);
		d |= isdigit(s[i]);
	}
	printf("%s\n", a && b && c && d? "Correct": "Too weak");
	return 0;
}