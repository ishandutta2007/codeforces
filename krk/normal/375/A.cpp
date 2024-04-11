#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int Maxd = 10;
const string bymod[] = {"1869", "1968", "1689", "6198", "1698", "1986", "1896"};

string s;
int md, nnum;
bool er[Maxd];

int main()
{
	getline(cin, s);
	er[1] = er[6] = er[8] = er[9] = true;
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '0') nnum++;
		else if (er[s[i] - '0']) er[s[i] - '0'] = false;
			 else {
			 	md = (10 * md + (s[i] - '0')) % 7;
			 	printf("%c", s[i]);
			 }
	for (int i = 0; i < 7; i++)
		if ((md * 10000 + i) % 7 == 0) { printf("%s", bymod[i].c_str()); break; }
	while (nnum--) printf("0");
	printf("\n");
	return 0;
}