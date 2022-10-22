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

const int Maxd = 10;
const int Maxl = 5;

char B[Maxd][Maxd];

bool Ok(int r, int c) { return 0 <= r && r < Maxd && 0 <= c && c < Maxd; }

bool checkDiag1(int r, int c)
{
	for (int i = 0; i < Maxl; i++)
		if (!Ok(r + i, c + i) || B[r + i][c + i] != 'X') return false;
	return true;
}

bool checkDiag2(int r, int c)
{
	for (int i = 0; i < Maxl; i++)
		if (!Ok(r + i, c + Maxl - 1 - i) || B[r + i][c + Maxl - 1 - i] != 'X') return false;
	return true; 
}

bool checkRow(int r, int c)
{
	for (int i = 0; i < Maxl; i++)
		if (!Ok(r, c + i) || B[r][c + i] != 'X') return false;
	return true;
}

bool checkCol(int r, int c)
{
	for (int i = 0; i < Maxl; i++)
		if (!Ok(r + i, c) || B[r + i][c] != 'X') return false;
	return true;
}

bool Check()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			if (checkDiag1(i, j) || checkDiag2(i, j) || checkRow(i, j) || checkCol(i, j)) return true;
	return false;
}

int main()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++) if (B[i][j] == '.') {
			B[i][j] = 'X';
			if (Check()) { printf("YES\n"); return 0; }
			B[i][j] = '.';
		}
	printf("NO\n");
	return 0;
}