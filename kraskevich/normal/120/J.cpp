#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int sqr(int a)
{
    return a * a;
}

int ABS(int a)
{
    return max(a, -a);
}

class point
{
    public:
        int x, y, id;
        point () {}
        point(int _x, int _y): x(_x), y(_y) {}
        
        int dist(point p)
        {
            return sqr(x - p.x) + sqr(y - p.y);
        }
        
        void scan(int _id)
        {
            id = _id;
            scanf("%d%d", &x, &y);
        }
        
        point operator - (point p)
        {
            return point(x - p.x, y - p.y);
        }
        
        int dist()
        {
            return sqr(x) + sqr(y);
        }
};

bool cmpx(point a, point b)
{
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cmpy(point a, point b)
{
    return a.y < b.y || a.y == b.y && a.x < b.x;
}

point inp[100000];
point p[100000];
point t[100000];
int res = (int)1e9;
point ra, rb;

void upd(point a, point b)
{
    point c = a - b;
    int cur = c.dist();
    if (cur < res)
    {
        res = cur;
        ra = a;
        rb = b;
    }
}

void solve(int l, int r)
{
    if (r - l <= 4)
    {
        for (int i = l; i < r; ++i)
            for (int j = i + 1; j <= r; ++j)
                upd(p[i], p[j]);
        sort(p + l, p + r + 1, cmpy);
        return;
    }
    
    int m = (l + r) >> 1;
    int x = p[m].x;
    
    solve(l, m);
    solve(m + 1, r);
    merge(p + l, p + m + 1, p + m + 1, p + r + 1, t, cmpy);
    copy(t, t + r - l + 1, p + l);
    
    int h = ceil(sqrt(res));
    int sz = 0;
    
    for (int i = l; i <= r; ++i)
    {
        if (ABS(p[i].x - x) > h)
            continue;
        
        t[sz++] = p[i];
        for (int j = sz - 2; j >= 0 && t[sz - 1].y - t[j].y <= h; --j)
            upd(t[sz - 1], t[j]);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    scanf("%d", &n);
        
    for (int i = 0; i < n; ++i)
        inp[i].scan(i);
    
    for (int i = 0; i < n; ++i)
    {
        p[i].x = ABS(inp[i].x);
        p[i].y = ABS(inp[i].y);
    }
    
    sort(p, p + n, cmpx);
    solve(0, n - 1);
        
    int res1, res2, k1, k2;
    
    for (int i = 0; i < n; ++i)
        if (ABS(inp[i].x) == ra.x && ABS(inp[i].y) == ra.y)
        {
            res1 = i;
            k1 = 0;
            if (inp[i].x < 0)
                ++k1;
            if (inp[i].y < 0)
                k1 += 2;
            break;
        }
    for (int i = 0; i < n; ++i)
        if (i != res1 && ABS(inp[i].x) == rb.x && ABS(inp[i].y) == rb.y)
        {
            res2 = i;
            k2 = 0;
            if (inp[i].x > 0)
                ++k2;
            if (inp[i].y > 0)
                k2 += 2;
            break;
        }
            
    printf("%d %d %d %d", res1 + 1, k1 + 1, res2 + 1, k2 + 1);
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}