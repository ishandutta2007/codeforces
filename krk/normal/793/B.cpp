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

const int Maxn = 1005;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n, m;
char B[Maxn][Maxn];
bool S[Maxn][Maxn], T[Maxn][Maxn];

void Go(int r, int c, int dr, int dc, bool S[][Maxn])
{
	if (r < 0 || r >= n || c < 0 || c >= m || B[r][c] == '*') return;
	S[r][c] = true;
	Go(r + dr, c + dc, dr, dc, S);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (B[i][j] == 'S')
				for (int z = 0; z < Maxd; z++)
					Go(i, j, dy[z], dx[z], S);
			else if (B[i][j] == 'T')
				for (int z = 0; z < Maxd; z++)
					Go(i, j, dy[z], dx[z], T);
	for (int i = 0; i < n; i++) {
		bool myS = false, myT = false;
		for (int j = 0; j < m; j++)
			if (B[i][j] == '*') myS = myT = false;
			else {
				myS |= S[i][j]; myT |= T[i][j];
				if (myS && myT) { printf("YES\n"); return 0; }
			}
	}
	for (int j = 0; j < m; j++) {
		bool myS = false, myT = false;
		for (int i = 0; i < n; i++)
			if (B[i][j] == '*') myS = myT = false;
			else {
				myS |= S[i][j]; myT |= T[i][j];
				if (myS && myT) { printf("YES\n"); return 0; }
			}
	}
	printf("NO\n");
	return 0;
}