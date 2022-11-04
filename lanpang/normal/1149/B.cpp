#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5+10;
const LL mod = 1e9+7;

int n , q , dp[260][260][260] , jp[maxn][26] , la[26] , l[4];
char a[maxn] , b[10] , a1[maxn] , a2[maxn] , a3[maxn];

int main()
{
	int i , j , k;
	cin >> n >> q;
	scanf("%s",a+1);
	for (i = 0 ; i < 26 ; i++)
		la[i] = n+1;
	for (i = n+1 ; i >= 0 ; i--)
	{
		for (j = 0 ; j < 26 ; j++)
			jp[i][j] = la[j];
		if (1 <= i && i <= n) la[a[i]-'a'] = i;
	}
	for (i = 0 ; i <= 250 ; i++)
		for (j = 0 ; j <= 250 ; j++)
			for (k = 0 ; k <= 250 ; k++)
				dp[i][j][k] = n+1;
	dp[0][0][0] = 0;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%s",b);
		scanf("%s",b+2);
		if (b[0] == '-')
		{
			if (b[2] == '1')
			{
				for (j = 0 ; j <= l[2] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
						dp[l[1]][j][k] = n+1;
				l[1]--;
			}
			if (b[2] == '2')
			{
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
						dp[j][l[2]][k] = n+1;
				l[2]--;
			}
			if (b[2] == '3')
			{
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[2] ; k++)
						dp[j][k][l[3]] = n+1;
				l[3]--;
			}
		}
		else
		{
			scanf("%s",b+4);
			if (b[2] == '1')
			{
				for (j = 0 ; j <= l[2] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
						dp[l[1]+1][j][k] = jp[dp[l[1]][j][k]][b[4]-'a'];
				a1[++l[1]] = b[4];
				for (j = 0 ; j <= l[2] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
					{
						if (j < l[2]) dp[l[1]][j+1][k] = min(dp[l[1]][j+1][k],jp[dp[l[1]][j][k]][a2[j+1]-'a']);
						if (k < l[3]) dp[l[1]][j][k+1] = min(dp[l[1]][j][k+1],jp[dp[l[1]][j][k]][a3[k+1]-'a']);
					}
			}
			if (b[2] == '2')
			{
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
						dp[j][l[2]+1][k] = jp[dp[j][l[2]][k]][b[4]-'a'];
				a2[++l[2]] = b[4];
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[3] ; k++)
					{
						if (j < l[1]) dp[j+1][l[2]][k] = min(dp[j+1][l[2]][k],jp[dp[j][l[2]][k]][a1[j+1]-'a']);
						if (k < l[3]) dp[j][l[2]][k+1] = min(dp[j][l[2]][k+1],jp[dp[j][l[2]][k]][a3[k+1]-'a']);
					}
			}
			if (b[2] == '3')
			{
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[2] ; k++)
						dp[j][k][l[3]+1] = jp[dp[j][k][l[3]]][b[4]-'a'];
				a3[++l[3]] = b[4];
				for (j = 0 ; j <= l[1] ; j++)
					for (k = 0 ; k <= l[2] ; k++)
					{
						if (j < l[1]) dp[j+1][k][l[3]] = min(dp[j+1][k][l[3]],jp[dp[j][k][l[3]]][a1[j+1]-'a']);
						if (k < l[2]) dp[j][k+1][l[3]] = min(dp[j][k+1][l[3]],jp[dp[j][k][l[3]]][a2[k+1]-'a']);
					}
			}
		}
		if (dp[l[1]][l[2]][l[3]] <= n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}