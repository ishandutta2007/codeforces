#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxl = 10005;

char str[Maxl];
int slen;
bool pos[Maxl][2];
set <string> S;

bool Check(int i, int len)
{
	int j = i + len;
	if (j + len - 1 >= slen) return true;
	for (int l = 0; l < len; l++)
		if (str[i + l] != str[j + l]) return true;
	return false;
}

int main()
{
	scanf("%s", str); slen = strlen(str);
	pos[slen][0] = pos[slen][1] = true;
	for (int i = slen - 1; i >= 5; i--)
		for (int j = 0; j < 2 && i + 2 + j - 1 < slen; j++) {
			bool ok = pos[i + 2 + j][1 - j];
			if (Check(i, 2 + j) && pos[i + 2 + j][j]) ok = true;
			if (ok) {
				string s;
				for (int l = 0; l < 2 + j; l++)
					s += string(1, str[i + l]);
				S.insert(s);
			}
			pos[i][j] = ok;
		}
	printf("%d\n", S.size());
	for (set <string>::iterator it = S.begin(); it != S.end(); it++)
		printf("%s\n", (*it).c_str());
	return 0;
}