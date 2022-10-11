#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int n, q, c, a[105][105][15], f[105][105][15];
 
struct rect
{
    int t, x1, x2, y1, y2;
}   p[100005];
 
bool cmp(rect a, rect b)
{
    return a.t < b.t;
}
 
int main()
{
	scanf("%d%d%d", &n, &q, &c);
	int x, y, s;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &x, &y, &s);
        a[x][y][s]++;
    }
    for (int x = 1; x <= 100; x++)
        for (int y = 1; y <= 100; y++)
            for (int s = 0; s <= c; s++)
                f[x][y][s] = f[x - 1][y][s] + f[x][y - 1][s] - f[x - 1][y - 1][s] + a[x][y][s];
    for (int i = 1; i <= q; i++)
        scanf("%d%d%d%d%d", &p[i].t, &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
    for (int i = 1; i <= q; i++)
    {
        int ans = 0, x1 = p[i].x1, x2 = p[i].x2, y1 = p[i].y1, y2 = p[i].y2, t = p[i].t;
        for (int s = 0; s <= c; s++)
            ans += (f[x2][y2][s] - f[x2][y1 - 1][s] - f[x1 - 1][y2][s] + f[x1 - 1][y1 - 1][s]) * ((s + t) % (c + 1));
        printf("%d\n", ans);
    }
	return 0;
}