#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , m , a[101][101];
int row[101] , col[101];

int main ()
{
	int i , j , x=1 , y=1 , c=0 , t=0;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= m ; j++)
		{
			scanf("%d",&a[i][j]);
			if (i > 1 || j > 1)
			{
				if (a[x][y] > a[i][j])
				{
					x = i;
					y = j;
				}
			}
		}
	}
	if (a[x][y] > 0)
	{
		if (n <= m) 
		{
			row[x] += a[x][y];
			t += a[x][y];
			for (i = 1 ; i <= m ; i++)
			{
				if (i != y)
				{
					col[i] += a[x][i]-row[x];
					t += a[x][i]-row[x];
				}
			}
			for (i = 1 ; i <= n ; i++)
			{
				if (i != x)
				{
					row[i] += a[i][y];
					t += a[i][y];
				}
			}
		}
		else
		{
			col[y] += a[x][y];
			t += a[x][y];
			for (i = 1 ; i <= n ; i++)
			{
				if (i != x)
				{
					row[i] += a[i][y]-col[y];
					t += a[i][y]-col[y];
				}
			}
			for (i = 1 ; i <= m ; i++)
			{
				if (i != y)
				{
					col[i] += a[x][i];
					t += a[x][i];
				}
			}
		}
	}
	else
	{
		for (i = 1 ; i <= m ; i++)
		{
			if (i != y)
			{
				col[i] += a[x][i];
				t += a[x][i];
			}
		}
		for (i = 1 ; i <= n ; i++)
		{
			if (i != x)
			{
				row[i] += a[i][y];
				t += a[i][y];
			}
		}
	}
	for (i = 1 ; i <= n && c == 0 ; i++)
	{
		for (j = 1 ; j <= m && c == 0 ; j++)
		{
			if (a[i][j] != (row[i]+col[j]))
			{
				c = -1;
			}
		}
	}
	if (c == -1)
	{
		cout << "-1\n";
	}
	else
	{
		cout << t << "\n";
		for (i = 1 ; i <= n ; i++)
		{
			for (j = 1 ; j <= row[i] ; j++)
			{
				printf("row %d\n",i);
			}
		}
		for (i = 1 ; i <= m ; i++)
		{
			for (j = 1 ; j <= col[i] ; j++)
			{
				printf("col %d\n",i);
			}
		}
	}
	//system("PAUSE");
	return 0;
}