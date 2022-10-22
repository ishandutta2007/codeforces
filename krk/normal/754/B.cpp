#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxd = 4;

char B[Maxd][Maxd];

bool Won()
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < Maxd; j++)
			if (B[i][j] == 'x' && B[i + 1][j] == 'x' && B[i + 2][j] == 'x') return true;
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < 2; j++)
			if (B[i][j] == 'x' && B[i][j + 1] == 'x' && B[i][j + 2] == 'x') return true;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (B[i][j] == 'x' && B[i + 1][j + 1] == 'x' && B[i + 2][j + 2] == 'x' ||
				B[i][j + 2] == 'x' && B[i + 1][j + 1] == 'x' && B[i + 2][j] == 'x') return true;
	return false;
}

int main() 
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			scanf(" %c", &B[i][j]);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			if (B[i][j] == '.') {
				B[i][j] = 'x';
				if (Won()) { printf("YES\n"); return 0; }
				B[i][j] = '.';
			}
	printf("NO\n");
    return 0;
}