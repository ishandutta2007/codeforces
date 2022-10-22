#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxl = 27;
const int Maxn = 13;

string s;
int freq[Maxl];
char B[2][Maxn];
int r, c;

void Next()
{
	if (r == 0) {
		c++;
		if (c >= Maxn) { r = 1; c = Maxn - 1; }
	} else {
		c--;
		if (c < 0) { r = 0; c = 0; }
	}
}

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		freq[s[i] - 'A']++;
	int ind = 0;
	while (freq[ind] != 2) ind++;
	int val[2] = {-1, -1};
	for (int i = 0; i < s.length(); i++)
		if (s[i] - 'A' == ind)
			if (val[0] == -1) val[0] = i;
			else val[1] = i;
	int dif = val[1] - val[0] - 1;
	if (dif == 0) { printf("Impossible\n"); return 0; }
	r = 0, c = Maxn - dif / 2 - 1;
	B[r][c] = 'A' + ind;
	for (int i = val[0] + 1; i < val[1]; i++) {
		Next();
		B[r][c] = s[i];
	}
	for (int i = val[1] + 1; i < s.length(); i++) {
		Next();
		B[r][c] = s[i];
	}
	for (int i = 0; i < val[0]; i++) {
		Next();
		B[r][c] = s[i];
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < Maxn; j++)
			printf("%c", B[i][j]);
		printf("\n");
	}
	return 0;
}