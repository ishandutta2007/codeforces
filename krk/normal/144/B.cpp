#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int x1, y1, x2, y2;
int n;
int x[Maxn], y[Maxn], r[Maxn];
int res;

bool Need(int gx, int gy)
{
     for (int i = 0; i < n; i++)
         if ((gx - x[i]) * (gx - x[i]) + (gy - y[i]) * (gy - y[i]) <= r[i] * r[i]) return false;
     return true;
}

int main()
{
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d %d", &x[i], &y[i], &r[i]);
    for (int cury = y1; cury <= y2; cury++)
        res += Need(x1, cury) + Need(x2, cury);
    for (int curx = x1 + 1; curx < x2; curx++)
        res += Need(curx, y1) + Need(curx, y2);
    printf("%d\n", res);
    return 0;
}