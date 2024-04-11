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

const int Maxn = 55;
const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;
int B[Maxn][Maxn];
bool tk[Maxn][Maxn];

void Fill(int x, int y)
{
	if (x < 1 || x > n || y < 1 || y > n || tk[x][y] || B[x][y] != 4) return;
	tk[x][y] = true;
	for (int i = 0; i < Maxd; i++)
		Fill(x + dx[i], y + dy[i]);
}

bool Check()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int my = 0;
			if (tk[i][j]) my = 4;
			else for (int d = 0; d < Maxd; d++) {
				int nd = (d + 1) % Maxd;
				my += tk[i + dx[d]][j + dy[d]] || tk[i + dx[d] + dx[nd]][j + dy[d] + dy[nd]] || tk[i + dx[nd]][j + dy[nd]];
			}
			if (my != B[i][j]) return false;
		}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int y = n; y > 0; y--)
		for (int x = 1; x <= n; x++) {
			char ch; scanf(" %c", &ch);
			B[x][y] = ch - '0';
		}
	bool found = false;
	int r, c;
	for (int x = 1; x <= n && !found; x++)
		for (int y = 1; y <= n && !found; y++)
			if (B[x][y] == 4) { found = true; r = x, c = y; }
	if (!found) { printf("No\n"); return 0; }
	Fill(r, c);
	printf("%s\n", Check()? "Yes": "No");
	return 0;
}