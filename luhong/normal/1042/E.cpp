#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 998244353

long long s[1010000][4], dp[1010][1010];
int b[1010000], cnt = 0;

struct xxx{
	int a, r, c;
}d[1010000];

bool cmp(xxx a, xxx b) {return a.a < b.a;}

long long qpow(long long x, int p)
{
	long long ans = 1;
	while(p)
	{
		if(p & 1) ans = ans * x % mod;
		x = x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			++cnt, scanf("%d", &d[cnt].a), b[cnt] = d[cnt].a, d[cnt].r = i, d[cnt].c = j;
	std::sort(b + 1, b + cnt + 1); cnt = std::unique(b + 1, b + cnt + 1) - b - 1;
	for(int i = 1; i <= n * m; i++)
		d[i].a = std::lower_bound(b + 1, b + cnt + 1, d[i].a) - b;
	std::sort(d + 1, d + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(d[i].a != 1)
		{
			dp[d[i].r][d[i].c] = s[d[i].a - 1][0];
			dp[d[i].r][d[i].c] = (dp[d[i].r][d[i].c] - 2 * d[i].r * s[d[i].a - 1][1] % mod + mod) % mod;
			dp[d[i].r][d[i].c] = (dp[d[i].r][d[i].c] - 2 * d[i].c * s[d[i].a - 1][2] % mod + mod) % mod;
			dp[d[i].r][d[i].c] = (dp[d[i].r][d[i].c] + s[d[i].a - 1][3] * (d[i].r * d[i].r + d[i].c * d[i].c)) % mod;
			dp[d[i].r][d[i].c] = dp[d[i].r][d[i].c] * qpow(s[d[i].a - 1][3], mod - 2) % mod;
		}
		if(d[i].a != d[i - 1].a) s[d[i].a][0] = s[d[i].a - 1][0],
								 s[d[i].a][1] = s[d[i].a - 1][1], 
								 s[d[i].a][2] = s[d[i].a - 1][2],
								 s[d[i].a][3] = s[d[i].a - 1][3];
		s[d[i].a][0] = (s[d[i].a][0] + d[i].r * d[i].r + d[i].c * d[i].c + dp[d[i].r][d[i].c]) % mod;
		s[d[i].a][1] = (s[d[i].a][1] + d[i].r) % mod;
		s[d[i].a][2] = (s[d[i].a][2] + d[i].c) % mod;
		s[d[i].a][3] = (s[d[i].a][3] + 1) % mod;
	}
	int x, y; scanf("%d%d", &x, &y);
	printf("%lld\n", dp[x][y]);
	return 0;
}
/*dp[i][j]=dp[k][l]+(i-k)^2+(j-l)^2
s[v][0]=dp[k][l]+k^2+l^2     a[k][l]<=v
s[v][1]=k    s[v][2]=l    s[v][3]=1
k=a[dp[i][j]]-1
dp[i][j]=s[k][0]-2*i*s[k][1]-2*j*s[k][2]+s[k][3]*(i*i+j*j)
dp[i][j]/=s[k][3]
*/