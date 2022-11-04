#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n , q , c;
int f[11][101][101] , a[11][101][101] , ss[11][101][101];

int main ()
{
	int i , j , k , x , y , s , t , xx , yy , p;
	cin >> n >> q >> c;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d%d",&x,&y,&s);
		p = s;
		a[0][x][y] += p;
		for (j = 1 ; j <= c ; j++)
		{
			p++;
			if (p > c)
			    p = 0;
			a[j][x][y] += p;
		}
	}
	for (k = 0 ; k <= c ; k++)
	{
		for (i = 0 ; i <= 100 ; i++)
		{
			ss[k][i][0] = a[k][i][0];
			for (j = 1 ; j <= 100 ; j++)
			{
				ss[k][i][j] = ss[k][i][j-1]+a[k][i][j];
			}
		}
		f[k][0][0] = a[k][0][0];
		for (i = 1 ; i <= 100 ; i++)
		{
			f[k][0][i] = f[k][0][i-1]+a[k][0][i];
			f[k][i][0] = f[k][i-1][0]+a[k][i][0];
		}
		for (i = 1 ; i <= 100 ; i++)
		{
			for (j = 1 ; j <= 100 ; j++)
			{
				f[k][i][j] = f[k][i-1][j]+ss[k][i][j];
			}
		}
	}
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d%d%d",&t,&x,&y,&xx,&yy);
		t %= (c+1);
		if (x > 0 && y > 0)
		{
			printf("%d\n",f[t][xx][yy]+f[t][x-1][y-1]-f[t][x-1][yy]-f[t][xx][y-1]);
		}
		else
		{
			if (x == 0 && y == 0)
			{
				printf("%d\n",f[t][xx][yy]);
			}
			else
			{
				if (x == 0)
				{
					printf("%d\n",f[t][xx][yy]-f[t][xx][y-1]);
				}
				else
				{
					printf("%d\n",f[t][xx][yy]-f[t][x-1][yy]);
				}
			}
		}	
	}
	return 0;
}