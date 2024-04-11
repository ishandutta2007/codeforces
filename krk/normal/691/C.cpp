#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char str[1000005];
string s;

int main()
{
	scanf("%s", str); s = str; s = "0" + s;
	int pnt = 0;
	while (pnt < s.length() && s[pnt] != '.') pnt++;
	if (pnt == s.length()) s += ".0";
	pnt = 0;
	while (pnt < s.length() && (s[pnt] == '0' || s[pnt] == '.')) pnt++;
	int fr = pnt;
	for (int i = pnt + 1; i < s.length(); i++)
		if (s[i] != '0' && s[i] != '.') fr = i;
	printf("%c", s[pnt]);
	if (pnt < fr) {
		printf(".");
		for (int i = pnt + 1; i <= fr; i++)
			if (s[i] != '.') printf("%c", s[i]);
	}
	int pnt2 = 0;
	while (s[pnt2] != '.') pnt2++;
	if (pnt + 1 != pnt2)
		if (pnt2 < pnt) printf("E%d", pnt2 - pnt);
		else printf("E%d", pnt2 - pnt - 1);
	printf("\n");
	return 0;
}