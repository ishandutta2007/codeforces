#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int Maxd = 10;
const int deg[Maxd][Maxd] = {{6, 2, 4, 4, 3, 4, 5, 3, 6, 5},
							 {2, 2, 1, 2, 2, 1, 1, 2, 2, 2},
							 {4, 1, 5, 4, 2, 3, 4, 2, 5, 4},
							 {4, 2, 4, 5, 3, 4, 4, 3, 5, 5},
							 {3, 2, 2, 3, 4, 3, 3, 2, 4, 4},
							 {4, 1, 3, 4, 3, 5, 5, 2, 5, 5},
							 {5, 1, 4, 4, 3, 5, 6, 2, 6, 5},
							 {3, 2, 2, 3, 2, 2, 2, 3, 3, 3},
							 {6, 2, 5, 5, 4, 5, 6, 3, 7, 6},
							 {5, 2, 4, 5, 4, 5, 5, 3, 6, 6}};
const int best = 7;

string s;
int n;
int st;

int gp(int ind) { return ind >= n? ind - n: ind + n; }

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	getline(cin, s); n = s.length() / 2;
	int i, j;
	int has;
	for (i = s.length() - 1; i >= 0; i--) {
		has = deg[s[gp(i)] - '0'][s[i] - '0'];
		for (j = s[i] - '0' + 1; j < Maxd; j++)
			if (st + deg[s[gp(i)] - '0'][j] - has > 0) break;
		if (j < Maxd) break;
		s[i] = '8'; st += deg[s[gp(i)] - '0'][8] - has;
	}
	if (i < 0) { printf("-1\n"); return 0; }
	s[i] = j + '0'; st += deg[s[gp(i)] - '0'][j] - has;
	for (i++; i < s.length(); i++) {
		has = deg[s[gp(i)] - '0'][s[i] - '0'];
		for (j = 0; j < Maxd; j++)
			if (st + deg[s[gp(i)] - '0'][j] - has > 0) break;
		s[i] = j + '0'; st += deg[s[gp(i)]- '0'][j] - has;
	}
	printf("%s\n", s.c_str());
	return 0;
}