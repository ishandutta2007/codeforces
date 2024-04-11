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

const int Maxk = 31;
const int Maxn = 320;
const int Maxd = 8;
const int dy[Maxd] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[Maxd] = {1, 1, 0, -1, -1, -1, 0, 1};

int n;
int t[Maxk];
bool B[Maxn][Maxn][Maxd][Maxk];
bool mark[Maxn][Maxn];

void Breakout(int r, int c, int d, int lvl)
{
	if (B[r][c][d][lvl]) return;
	B[r][c][d][lvl] = true;
	mark[r][c] = true;
	for (int i = 0; i < t[lvl] - 1; i++) {
		r += dy[d], c += dx[d];
		mark[r][c] = true;
	}
	if (lvl < n - 1) {
		int nd = (d - 1 + Maxd) % Maxd;
		Breakout(r + dy[nd], c + dx[nd], nd, lvl + 1);
		nd = (d + 1) % Maxd;
		Breakout(r + dy[nd], c + dx[nd], nd, lvl + 1);
	}
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	fill((bool*)B, (bool*)B + Maxn * Maxn * Maxd * Maxk, false);
	Breakout(157, 157, 2, 0);
	int res = 0;
	for (int i = 0; i < Maxn; i++)
		for (int j = 0; j < Maxn; j++)
			res += mark[i][j];
	printf("%d\n", res);
    return 0;
}