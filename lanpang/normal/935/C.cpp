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

double xx , yy , xxx , yyy , r , rr , dx , dy , l , d , x , y;

int main()
{
	cin >> r >> xx >> yy >> xxx >> yyy;
	dx = xx-xxx;
	dy = yy-yyy;
	if (dx == 0 && dy == 0)
	{
		printf("%.7lf %.7lf %.7lf\n",xx+r/2,yy,r/2);
	}
	else
	{
		l = dx*dx+dy*dy;
		l = sqrt(l);
		if (l >= r) printf("%.7lf %.7lf %.7lf\n",xx,yy,r);
		else
		{
			rr = l+r;
			rr /= 2;
			d = rr/l;
			x = xxx+dx*d;
			y = yyy+dy*d;
			printf("%.7lf %.7lf %.7lf\n",x,y,rr);
		}
	}
	return 0;
}