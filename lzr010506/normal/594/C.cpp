#include <bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
struct Point
{
	double x, y;
	int index;
}cx[N], cy[N];
int n, k;
ll mins;
int vis[N];
bool cmpx (Point a, Point b)
{
    return a.x < b.x;
}
bool cmpy(Point a, Point b)
{
    return a.y < b.y;
}

void dfs(int k, int lx, int rx, int ly, int ry)
{
	while (vis[cx[lx].index])
        lx ++;
    while (vis[cx[rx].index])
        rx --;
    while (vis[cy[ly].index])
        ly ++;
    while (vis[cy[ry].index])
        ry --;
    if (k == 0)
    {
        ll s = max(1ll,(ll)(cx[rx].x - cx[lx].x)) * max(1ll,(ll)(cy[ry].y - cy[ly].y));
        if (s < mins) mins = s;
        return;
    }
    vis[cx[lx].index] = 1;
    dfs(k - 1, lx + 1, rx, ly, ry);
    vis[cx[lx].index] = 0;
        
    vis[cx[rx].index] = 1;
    dfs(k - 1, lx, rx - 1, ly, ry);
    vis[cx[rx].index] = 0;

    vis[cy[ly].index] = 1;
    dfs(k - 1, lx, rx, ly + 1, ry);
    vis[cy[ly].index] = 0;

    vis[cy[ry].index] = 1;
    dfs(k - 1, lx, rx, ly, ry - 1);
    vis[cy[ry].index] = 0;
}

int main()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++)
	{
		int xx, yy, xx1, yy1;
		scanf("%d%d%d%d",&xx,&yy,&xx1,&yy1);
		cx[i].index = i;
        cx[i].x = (xx + xx1) / 2.0;
        cx[i].y = (yy + yy1) / 2.0;
        cy[i].index = i;
        cy[i].x = cx[i].x;
        cy[i].y = cx[i].y;
	}
	sort(cx, cx + n, cmpx);
	sort(cy, cy + n, cmpy);
	mins = max(1ll, (ll)(cx[n - 1].x - cx[0].x)) * max(1ll, (ll)(cy[n - 1].y - cy[0].y));
    dfs(k, 0, n - 1, 0, n - 1);
    if (mins == 0) printf("1\n");
    else printf("%I64d\n", mins);
	return 0;
}