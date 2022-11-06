#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 51

int f[MN][MN][MN][MN];
char c[MN][MN];
int s[MN][MN];

int S(int a, int b, int c, int d) {return s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];}

int DP(int a, int b, int c, int d)
{
	if(f[a][b][c][d] != -1) return f[a][b][c][d]; 
	if(!S(a, b, c, d)) {f[a][b][c][d] = 0; return 0;}
	f[a][b][c][d] = std::max(c - a + 1, d - b + 1);
	for(int i = a; i < c; i++)
		f[a][b][c][d] = std::min(f[a][b][c][d], DP(a, b, i, d) + DP(i + 1, b, c, d));
	for(int i = b; i < d; i++)
		f[a][b][c][d] = std::min(f[a][b][c][d], DP(a, b, c, i) + DP(a, i + 1, c, d));
	return f[a][b][c][d];
}

int main()
{
	memset(f, -1, sizeof(f));
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s", c[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (c[i][j] == '#');	
	printf("%d\n", DP(1, 1, n, n));
}