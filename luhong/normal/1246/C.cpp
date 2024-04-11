#include <iostream>
#include <cstdio>
#define MN 2010
#define mod 1000000007

int f[MN][MN][2];
int n, m;
int sr[MN][MN], sc[MN][MN];
int gr[MN], gc[MN];
int br[MN][MN], bc[MN][MN];
char s[MN][MN];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
		
	if(n == 1 && m == 1) return 0 * puts("1");
	
	for(int i = 1; i <= n; i++)
		gr[i] = 1;
	for(int j = 1; j <= m; j++)
		gc[j] = 1;
		
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
		{
			br[i][j] = br[i][j + 1] + (s[i][j] == 'R');
			bc[i][j] = bc[i + 1][j] + (s[i][j] == 'R');
		}
			
	f[1][1][0] = f[1][1][1] = sr[1][1] = sc[1][1] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(i == 1 && j == 1) continue;
			while(gr[i] < j && br[i][gr[i] + 1] > m - j) gr[i]++;
			f[i][j][0] = (sr[i][j - 1] - sr[i][gr[i] - 1] + mod) % mod;
			
			while(gc[j] < i && bc[gc[j] + 1][j] > n - i) gc[j]++;
			f[i][j][1] = (sc[i - 1][j] - sc[gc[j] - 1][j] + mod) % mod;
		
			sr[i][j] = (sr[i][j - 1] + f[i][j][1]) % mod;
			sc[i][j] = (sc[i - 1][j] + f[i][j][0]) % mod;
		}
	
	printf("%d\n", (f[n][m][0] + f[n][m][1]) % mod);
}