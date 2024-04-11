#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <sstream>
using namespace std;

const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n;
string s;

int toInt(const string &s)
{
	stringstream ss(s);
	int res; ss >> res;
	return res;
}

void Print(int x)
{
	if (x < 0) return;
	Print(x / alph.size() - 1); printf("%c", alph[x % alph.size()]);
}

int main()
{
	scanf("%d", &n); getline(cin, s);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int dig = -1, C = -1;
		for (int j = 0; j < s.length(); j++)
			if (isdigit(s[j]) && dig == -1) dig = j;
			else if (s[j] == 'C' && C == -1) C = j;
		if (dig < C) {
			int r = toInt(s.substr(1, C - 1)), c = toInt(s.substr(C + 1));
			Print(c - 1); printf("%d\n", r);
		} else {
			string col = s.substr(0, dig);
			int r = toInt(s.substr(dig));
			int c = 0;
			for (int j = 0; j < col.length(); j++)
				c = 26 * c + (col[j] - 'A' + 1);
			printf("R%dC%d\n", r, c);
		}
	}
	return 0;
}