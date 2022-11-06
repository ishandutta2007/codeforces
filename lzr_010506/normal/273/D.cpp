#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
const int N = 210;
const int mod = 1e9 + 7;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int f[2][N][N][2][2],sum[N][N][2][2], ans;
int getsum(int x1,int y1,int x2,int y2,int a,int b)
{
	return ((ll)sum[x2][y2][a][b] - sum[x1 - 1][y2][a][b] - sum[x2][y1 - 1][a][b] + sum[x1 - 1][y1 - 1][a][b] + mod + mod) % mod;
}
int main()
{
	int n, m;
	n = read();
	m = read();
	if(n < m) swap(n, m);
	for(int i = 1; i <= n; i ++)
	{
		memset(f[i & 1], 0, sizeof(f) / 2);
		memset(sum, 0, sizeof(sum));
		for(int l = 1; l <= m; l ++)
			for(int r = l; r <= m; r ++)
				for(int j = 0; j < 2; j ++)
					for(int k = 0; k < 2; k ++)
						sum[l][r][j][k] = f[!(i & 1)][l][r][j][k];
		for(int l = 1; l <= m; l ++)
			for(int r = 1; r <= m; r ++)
				for(int j = 0; j < 2; j ++)
					for(int k = 0; k < 2; k ++)
						sum[l][r][j][k] = ((ll)sum[l][r][j][k] + sum[l - 1][r][j][k] + sum[l][r - 1][j][k] - sum[l - 1][r - 1][j][k]) % mod;

		for(int l = 1; l <= m; l ++)
			for(int r = l; r <= m; r ++)
			{
				f[i & 1][l][r][0][0] = getsum(l, l, r, r, 0, 0) % mod;
				f[i & 1][l][r][0][1] = ((ll)getsum(l, r, r, m, 0, 1) + getsum(l, r + 1, r, m, 0, 0)) % mod;
				f[i & 1][l][r][1][0] = ((ll)getsum(1, l, l, r, 1, 0) + getsum(1, l, l - 1, r, 0, 0)) % mod;
				f[i & 1][l][r][1][1] = ((ll)getsum(1, r, l, m, 1, 1) + getsum(1, r + 1, l, m, 1, 0) + getsum(1, r, l - 1, m, 0, 1) + getsum(1, r + 1, l - 1, m, 0, 0)) % mod;
			}

		for(int l = 1; l <= m; l ++)
			for(int r = l; r <= m; r ++)
			{
				f[i & 1][l][r][0][0] ++;
				f[i & 1][l][r][0][0] %= mod;
			}

		for(int l = 1; l <= m; l ++)
			for(int r = m; r >= l; r --)
				for(int j = 0; j < 2; j ++)
					for(int k = 0; k < 2; k ++)
					{
						ans += f[i & 1][l][r][j][k];
						ans %= mod;
					}
	}
	printf("%d\n",ans);
	return 0;
}