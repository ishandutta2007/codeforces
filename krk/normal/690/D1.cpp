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

const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};
const int Maxn = 105;

int R, C;
char B[Maxn][Maxn];
int res;

void Fill(int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C || B[r][c] == '.') return;
	B[r][c] = '.';
	for (int i = 0; i < Maxd; i++)
		Fill(r + dy[i], c + dx[i]);
}

int main()
{
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) if (B[i][j] == 'B') {
			res++; Fill(i, j);
		}
	printf("%d\n", res);
	return 0;
}