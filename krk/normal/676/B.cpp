#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 12;
const int fillc = 1 << 10;

int n, t;
int has[Maxn][Maxn];
int res;

void Fill(int r, int c, int val)
{
	if (r > n) return;
	has[r][c] += val;
	if (has[r][c] > fillc) {
		int lft = has[r][c] - fillc; has[r][c] = fillc;
		Fill(r + 1, c, lft / 2); Fill(r + 1, c + 1, lft / 2);
	}
}

int main()
{
	scanf("%d %d", &n, &t);
	while (t--) {
		Fill(1, 1, fillc);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			res += has[i][j] == fillc;
	printf("%d\n", res);
	return 0;
}