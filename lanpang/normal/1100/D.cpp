#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int ax[700] , ay[700] , c1 , c2 , c3 , c4 , mc;
int x , y , dx , dy , xx , yy;
bool f[1010][1010];

int main()
{
	int i , j , k;
	cin >> x >> y;
	for (i = 1 ; i <= 666 ; i++)
	{
		cin >> ax[i] >> ay[i];
		f[ax[i]][ay[i]] = true;
	}
	while (x != 500 || y != 500)
	{
		dx = dy = 0;
		if (x > 500) dx = -1;
		if (x < 500) dx = 1;
		if (y > 500) dy = -1;
		if (y < 500) dy = 1;
		x += dx;
		y += dy;
		if (f[x][y]) x -= dx;
		cout << x << " " << y << "\n";
		fflush(stdout);
		cin >> k >> xx >> yy;
		if (k == -1) return 0;
		f[ax[k]][ay[k]] = false;
		f[xx][yy] = true;
		ax[k] = xx;
		ay[k] = yy;
	}
	for (i = 1 ; i <= 499 ; i++)
		for (j = 1 ; j <= 499 ; j++)
			if (f[i][j]) c1++;
	for (i = 1 ; i <= 499 ; i++)
		for (j = 501 ; j <= 999 ; j++)
			if (f[i][j]) c2++;
	for (i = 501 ; i <= 999 ; i++)
		for (j = 1 ; j <= 499 ; j++)
			if (f[i][j]) c3++;
	for (i = 501 ; i <= 999 ; i++)
		for (j = 501 ; j <= 999 ; j++)
			if (f[i][j]) c4++;
	mc = min(c1,min(c2,min(c3,c4)));
	if (c1 == mc)
	{
		dx = 1;
		dy = 1;
	}
	if (c2 == mc)
	{
		dx = 1;
		dy = -1;
	}
	if (c3 == mc)
	{
		dx = -1;
		dy = 1;
	}
	if (c4 == mc)
	{
		dx = -1;
		dy = -1;
	}
	while (1)
	{
		x += dx;
		y += dy;
		if (f[x][y]) x -= dx;
		cout << x << " " << y << "\n";
		fflush(stdout);
		cin >> k >> xx >> yy;
		if (k == -1) return 0;
		f[ax[k]][ay[k]] = false;
		f[xx][yy] = true;
		ax[k] = xx;
		ay[k] = yy;
	}
	return 0;
}