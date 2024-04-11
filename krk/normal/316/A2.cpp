#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

string s;
int fir, tens;
set <char> S;

int main()
{
	cin >> s;
	if (s[0] == '?') fir = 9;
	else if (isdigit(s[0])) fir = 1;
	else { fir = 9; S.insert(s[0]); }
	for (int i = 1; i < s.length(); i++)
		if (s[i] == '?') tens++;
		else if (isupper(s[i]) && !S.count(s[i])) {
			fir *= 10 - S.size(); S.insert(s[i]);
		}
	if (fir) {
		printf("%d", fir);
		for (int i = 0; i < tens; i++)
			printf("0");
		printf("\n");
	} else printf("0\n");
	return 0;
}