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

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

char a[20][20] , c;
int b[10][10] , x , y , xx , yy;

int main ()
{
	int i , j;
	for (i = 1 ; i <= 9 ; i++)
	{
		for (j = 1 ; j <= 9 ; j++)
		{
			a[i][j] = getchar();
			if (j%3==0) c = getchar();
		}
		if (i == 3 || i == 6) c = getchar(); 
	}
	cin >> x >> y;
	x %= 3;
	if (x == 0) x = 3;
	y %= 3;
	if (y == 0) y = 3;
	for (i = 1 ; i <= 9 ; i++)
	{
		for (j = 1 ; j <= 9 ; j++)
		{
			if (a[i][j] == '.')
			{
				xx = (i+2)/3;
				yy = (j+2)/3;
				b[xx][yy]++;
			}
		}
	}
	if (b[x][y] > 0)
	{
		for (i = 1 ; i <= 9 ; i++)
		{
			for (j = 1 ; j <= 9 ; j++)
			{
				if (a[i][j] == '.')
				{
					xx = (i+2)/3;
					yy = (j+2)/3;
					if (xx == x && yy == y) a[i][j] = '!';
				}
			}
		}
	}
	else
	{
		for (i = 1 ; i <= 9 ; i++)
		{
			for (j = 1 ; j <= 9 ; j++)
			{
				if (a[i][j] == '.')
				{
					a[i][j] = '!';
				}
			}
		}
	}
	for (i = 1 ; i <= 9 ; i++)
	{
		for (j = 1 ; j <= 9 ; j++)
		{
			printf("%c",a[i][j]);
			if (j == 3 || j == 6) cout << ' ';
			if (j == 9) cout << "\n";
		}
		if (i == 3 || i == 6) cout << "\n";
	}
	//system("PAUSE");
	return 0;
}