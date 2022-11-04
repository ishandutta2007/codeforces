#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , a[55][55] , f[55][55];

int query(int x , int y , int xx , int yy)
{
	printf("? %d %d %d %d\n",x,y,xx,yy);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

void swp()
{
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= n ; j++)
			if ((i+j)%2) a[i][j] = 1-a[i][j];
}

void prt()
{
	printf("!\n");
	for (int i = 1 ; i <= n ; i++)
	{
		for (int j = 1 ; j <= n ; j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}

void dfs(int x , int y)
{
	if (x > 1 && y > 1 && !f[x-1][y-1])
	{
		a[x-1][y-1] = (1-query(x-1,y-1,x,y))^a[x][y];
		f[x-1][y-1] = 1;
		dfs(x-1,y-1);
	}
	if (x < n && y < n && !f[x+1][y+1])
	{
		a[x+1][y+1] = (1-query(x,y,x+1,y+1))^a[x][y];
		f[x+1][y+1] = 1;
		dfs(x+1,y+1);
	}
	if (x > 2 && !f[x-2][y])
	{
		a[x-2][y] = (1-query(x-2,y,x,y))^a[x][y];
		f[x-2][y] = 1;
		dfs(x-2,y);
	}
	if (y > 2 && !f[x][y-2])
	{
		a[x][y-2] = (1-query(x,y-2,x,y))^a[x][y];
		f[x][y-2] = 1;
		dfs(x,y-2);
	}
	if (x <= n-2 && !f[x+2][y])
	{
		a[x+2][y] = (1-query(x,y,x+2,y))^a[x][y];
		f[x+2][y] = 1;
		dfs(x+2,y);
	}
	if (y <= n-2 && !f[x][y+2])
	{
		a[x][y+2] = (1-query(x,y,x,y+2))^a[x][y];
		f[x][y+2] = 1;
		dfs(x,y+2);
	}
}

int main()
{
	int i , j , k;
	cin >> n;
	a[1][1] = 1;
	for (k = 4 ; k <= n*2-2 ; k += 2)
	{
		for (i = 1 ; i < k ; i++)
		{
			j = k-i;
			if (i > n || j > n) continue;
			if (i > 2) a[i][j] = (1-query(i-2,j,i,j))^a[i-2][j];
			else if (j > 2) a[i][j] = (1-query(i,j-2,i,j))^a[i][j-2];
			else a[i][j] = (1-query(i-1,j-1,i,j))^a[i-1][j-1];
		}
	}
	a[1][2] = 1;
	f[1][2] = 1;
	dfs(1,2);
	for (i = 1 ; i < n ; i++)
	{
		for (j = 2 ; j <= n ; j++)
		{
			if (a[i][j] != a[i+1][j-1])
			{
				if (j < n)
				{
					if ((1-query(i,j-1,i+1,j+1))^a[i][j-1]^a[i+1][j+1]) swp();
				}
				else
				{
					if ((1-query(i,j-2,i+1,j))^a[i][j-2]^a[i+1][j]) swp();
				}
				prt();
				return 0;
			}
		}
	}
	for (i = 3 ; i <= n ; i++)
	{
		if (a[i][i] != a[i-1][i-1] && a[i-1][i-1] == a[i-2][i-2])
		{
			int x = query(i-2,i-2,i-1,i);
			int y = query(i-1,i-2,i,i);
			if (!x && !y)
			{
				if (a[i-1][i] == a[i-1][i-1]) swp();
			}
			if (x)
			{
				if (a[i-1][i-2] != a[i-1][i-1]) swp();
			}
			if (y)
			{
				if (a[i-1][i] != a[i-1][i-1]) swp();
			}
			prt();
			return 0;
		}
		if (a[i][i] == a[i-1][i-1] && a[i-1][i-1] != a[i-2][i-2])
		{
			int x = query(i-2,i-2,i-1,i);
			int y = query(i-1,i-2,i,i);
			if (!x && !y)
			{
				if (a[i-1][i-2] == a[i-1][i-1]) swp();
			}
			if (x)
			{
				if (a[i-1][i-2] != a[i-1][i-1]) swp();
			}
			if (y)
			{
				if (a[i-1][i] != a[i-1][i-1]) swp();
			}
			prt();
			return 0;
		}
	}
	prt();
	return 0;
}