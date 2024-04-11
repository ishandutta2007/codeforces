#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int Maxn = 10005;
const int Maxd = 3;

int n;
char B[Maxd][Maxn];
int ways[Maxn][1 << Maxd][2];

int Get2(int c, int r, int mask, int flag);

int Get(int c, int mask, int flag)
{
	if (c == n) return flag == 1;
	if (ways[c][mask][flag] == -1)
		ways[c][mask][flag] = Get2(c, 0, mask, flag);
	return ways[c][mask][flag];
}

bool Empty(int r, int c)
{
	return 0 <= r && r < Maxd && 0 <= c && c < n && B[r][c] == 'O';
}

int Get2(int c, int r, int mask, int flag)
{
	if (r == Maxd) return Get(c + 1, mask, flag);
	if (mask & 1 << r) return Get2(c, r + 1, mask ^ 1 << r, flag);
	if (B[r][c] != '.') return Get2(c, r + 1, mask, flag);
	int res = 0;
	if (r + 1 < Maxd && !(mask & 1 << r + 1) && B[r + 1][c] == '.') {
		int nflag = flag || Empty(r - 1, c) || Empty(r + 2, c);
		res = (res + Get2(c, r + 2, mask, nflag)) % mod;
	}
	if (c + 1 < n && B[r][c + 1] == '.') {
		int nflag = flag || Empty(r, c - 1) || Empty(r, c + 2);
		res = (res + Get2(c, r + 1, mask | 1 << r, nflag)) % mod;
	}
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &B[i][j]);
	fill((int*)ways, (int*)ways + Maxn * (1 << Maxd) * 2, -1);
	printf("%d\n", Get(0, 0, 0));
	return 0;
}