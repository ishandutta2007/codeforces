#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxd = 4;
const int R[Maxd] = {0, 0, 1, 1};
const int C[Maxd] = {0, 1, 1, 0};
const int Maxn = 2;

char B[Maxn][Maxn];
set <string> S;

void Read()
{
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++)
			scanf(" %c", &B[i][j]);
}

int main()
{
	Read();
	for (int i = 0; i < Maxd; i++) {
		string cur;
		for (int j = 0; j < Maxd; j++) {
			int ind = (i + j) % Maxd;
			if (B[R[ind]][C[ind]] != 'X') cur += string(1, B[R[ind]][C[ind]]);
		}
		S.insert(cur);
	}
	Read();
	string my;
	for (int j = 0; j < Maxd; j++)
		if (B[R[j]][C[j]] != 'X') my += string(1, B[R[j]][C[j]]);
	if (S.find(my) != S.end()) printf("YES\n");
	else printf("NO\n");
	return 0;
}