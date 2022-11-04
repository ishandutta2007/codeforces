#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n = 200 , a[210][210] , b[210][210];

void liana(int x , int y , int xx , int yy)
{
	int dx , dy , dd;
	dx = xx-x;
	dy = yy-y;
	dd = max(fabs(dx),fabs(dy));
	dx /= dd;
	dy /= dd;
	for (int i = 0 ; i <= dd ; i++)
	{
		a[x][y] = 1;
		x += dx;
		y += dy;
	}
}

void lianb(int x , int y , int xx , int yy)
{
	int dx , dy , dd;
	dx = xx-x;
	dy = yy-y;
	dd = max(fabs(dx),fabs(dy));
	dx /= dd;
	dy /= dd;
	for (int i = 0 ; i <= dd ; i++)
	{
		b[x][y] = 1;
		x += dx;
		y += dy;
	}
}

void dfsa(int x , int y)
{
	if (a[x][y]) return;
	a[x][y] = 1;
	if (x-1 >= 0) dfsa(x-1,y);
	if (x+1 <= 200) dfsa(x+1,y);
	if (y-1 >= 0) dfsa(x,y-1);
	if (y+1 <= 200) dfsa(x,y+1);
}

void dfsb(int x , int y)
{
	if (b[x][y]) return;
	b[x][y] = 1;
	if (x-1 >= 0) dfsb(x-1,y);
	if (x+1 <= 200) dfsb(x+1,y);
	if (y-1 >= 0) dfsb(x,y-1);
	if (y+1 <= 200) dfsb(x,y+1);
}

int main()
{
	int i , j , x[10] , y[10] , sx , sy;
	sx = 0;
	sy = 0;
	for (i = 1 ; i <= 4 ; i++)
	{
		cin >> x[i] >> y[i];
		x[i] += 100;
		y[i] += 100;
		sx += x[i];
		sy += y[i];
		if (i >= 2) liana(x[i],y[i],x[i-1],y[i-1]);
	}
	liana(x[1],y[1],x[4],y[4]);
	dfsa(sx/4,sy/4);
	sx = 0;
	sy = 0;
	for (i = 1 ; i <= 4 ; i++)
	{
		cin >> x[i] >> y[i];
		x[i] += 100;
		y[i] += 100;
		sx += x[i];
		sy += y[i];
		if (i >= 2) lianb(x[i],y[i],x[i-1],y[i-1]);
	}
	lianb(x[1],y[1],x[4],y[4]);
	dfsb(sx/4,sy/4);
	for (i = 0 ; i <= 200 ; i++)
	{
		for (j = 0 ; j <= 200 ; j++)
		{
			if (a[i][j] && b[i][j])
			{
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}