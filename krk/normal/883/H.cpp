#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxl = 26+26+10;

int n;
string s;
int freq[Maxl];
vector <int> C;

int toInt(char ch)
{
	if (islower(ch)) return ch - 'a';
	if (isupper(ch)) return ch - 'A' + 26;
	return ch - '0' + 52;
}

char toChar(int my)
{
	if (my < 26) return my + 'a';
	else if (my < 52) return my - 26 + 'A';
	else return my - 52 + '0';
}

void Print(int len, int C)
{
	if (len == 0) {
		if (C != -1) printf("%c", toChar(C));
		return;
	} else {
		int ind = 0;
		while (freq[ind] == 0) ind++;
		freq[ind] -= 2;
		printf("%c", toChar(ind));
		Print(len - 2, C);
		printf("%c", toChar(ind));
	}
}

int main()
{
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++)
		freq[toInt(s[i])]++;
	for (int i = 0; i < Maxl; i++)
		if (freq[i] % 2) { C.push_back(i); freq[i]--; }
	if (C.empty()) {
		printf("1\n");
		Print(n, -1); printf("\n");
	} else {
		int ind = 0;
		while (n % int(C.size()) != 0 || n / int(C.size()) % 2 == 0) {
			while (freq[ind] == 0) ind++;
			C.push_back(ind); C.push_back(ind); freq[ind] -= 2;
		}
		int len = n / int(C.size());
		printf("%d\n", int(C.size()));
		for (int i = 0; i < C.size(); i++) {
			Print(len - 1, C[i]);
			printf("%c", i + 1 < C.size()? ' ': '\n');
		}
	}
	return 0;
}