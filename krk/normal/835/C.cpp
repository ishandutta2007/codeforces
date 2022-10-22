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

const int Maxc = 12;
const int Maxn = 105;

int n, q, c;
int tot[Maxc][Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &q, &c);
	for (int i = 0; i < n; i++) {
		int x, y, s; scanf("%d %d %d", &x, &y, &s);
		for (int j = 0; j <= c; j++)
			tot[j][x][y] += (s + j) % (c + 1);
	}
	for (int i = 0; i <= c; i++)
		for (int j = 1; j < Maxn; j++)
			for (int k = 1; k < Maxn; k++)
				tot[i][j][k] += tot[i][j - 1][k] + tot[i][j][k - 1] - tot[i][j - 1][k - 1];
	for (int i = 0; i < q; i++) {
		int t, x1, y1, x2, y2; scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2); t %= (c + 1);
		printf("%d\n", tot[t][x2][y2] - tot[t][x1 - 1][y2] - tot[t][x2][y1 - 1] + tot[t][x1 - 1][y1 - 1]);
	}
	return 0;
}