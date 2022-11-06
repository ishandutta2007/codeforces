#include <bits/stdc++.h>
#define db double
using namespace std;
const db inf = 1e10;

int n;
double l = 0, r = inf;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
    n = read();
    db x1 = (db)read();
    db y1 = (db)read();
   	db x2 = (db)read();
    db y2 = (db)read();
    for(int i = 0; i < n; i ++)
	{
		db x = (db)read();
		db y = (db)read();
		db vx = (db)read();
		db vy = (db)read();
        double u = 0, v = 0;
        if(!vx)
        {
            if(x1 < x && x < x2) u = 0, v = inf;
            else
			{
                puts("-1");
                return 0;
            }
        }
        else
		{
            u = (x1 - x) / vx;
            v = (x2 - x) / vx;
            if(u > v) swap(u, v);
        }
        l = max(l, u), r = min(r, v);
        if(!vy)
        {
            if(y1 < y && y < y2) u = 0, v = inf;
            else
			{
                puts("-1");
                return 0;
            }
        }
        else
		{
            u = (y1 - y) / vy;
            v = (y2 - y) / vy;
            if(u > v) swap(u, v);
        }
        l = max(l, u);
        r = min(r, v);
    }
    if(l >= r) puts("-1");
    else printf("%.10lf", l);
    return 0;
}