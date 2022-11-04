#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , q , a[maxn] , jp[maxn][20] , ne[20][20] , dp[20];

int main()
{
	int i , j , k , x , y , f;
	cin >> n >> q;
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	for (j = 0 ; j < 20 ; j++)
		for (k = 0 ; k < 20 ; k++)
			ne[j][k] = n+1;
	for (i = 1 ; i <= n+1 ; i++)
		for (j = 0 ; j < 20 ; j++)
			jp[i][j] = n+1;
	for (i = n ; i >= 1 ; i--)
	{
		for (j = 0 ; j < 20 ; j++)
			for (k = 0 ; k < 20 ; k++)
				if ((a[i]&(1<<j)) && (a[i]&(1<<k))) ne[j][k] = i;
		for (j = 0 ; j < 20 ; j++)
			if (a[i]&(1<<j))
			{
				jp[i][j] = i;
				for (k = 0 ; k < 20 ; k++)
					jp[i][k] = min(jp[i][k],ne[j][k]);
			}
		for (j = 0 ; j < 20 ; j++)
			dp[j] = jp[i][j];
		for (j = 0 ; j < 20 ; j++)
			for (k = 0 ; k < 20 ; k++)
				dp[k] = min(dp[k],jp[jp[i][j]][k]);
		for (j = 0 ; j < 20 ; j++)
			jp[i][j] = dp[j];
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d",&x,&y);
		f = 0;
		for (j = 0 ; j < 20 ; j++)
			if ((a[y]&(1<<j)) && jp[x][j] <= y)
			{
				f = 1;
				break;
			}
		if (f) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}