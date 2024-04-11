#include <bits/stdc++.h>

using namespace std;

const int N = (int)6e6;
const int A = (int)3e6;

struct point
{
    int x, y;
    point() {}
    point(int _x, int _y): x(_x), y(_y) {}
};

vector<point> blue[N];
vector<point> red[N];

bool cmp(point a, point b)
{
    return a.x < b.x;
}

struct segm
{
    int xl, xr;
    int d;

    segm() {}
    segm(int _xl, int _xr, int _d): xl(_xl), xr(_xr), d(_d) {}
};

bool inter(segm b, segm r)
{
    assert((b.d - r.d) % 2 == 0);
    int xx = (b.d - r.d) / 2;
    if (b.xl <= xx && xx <= b.xr && r.xl <= xx && xx <= r.xr)
        return true;
    else
        return false;
}


const int M = 2222;
int u[M][M];

bool good(int t)
{
    t *= 2;
    vector<segm> bs;
    vector<segm> rs;
    for (int i = 0; i < N; i++)
    {
        if (!blue[i].size())
            continue;
        int d = blue[i].back().x + blue[i].back().y;
        int l = blue[i][0].x - t;
        int r = blue[i][0].x + t;
        for (int j = 1; j < blue[i].size(); j++)
        {
            point c = blue[i][j];
            assert(c.x + c.y == d);
            int ll = c.x - t;
            assert(l < ll);
            if (ll > r)
            {
                bs.push_back(segm(l, r, d));
                l = ll;
            }
            r = c.x + t;
        }
        bs.push_back(segm(l, r, d));
    }
    for (int i = 0; i < N; i++)
    {
        if (!red[i].size())
            continue;
        int d = red[i].back().y - red[i].back().x;
        int l = red[i][0].x - t;
        int r = red[i][0].x + t;
        for (int j = 1; j < red[i].size(); j++)
        {
            point c = red[i][j];
            int ll = c.x - t;
            if (ll > r)
            {
                rs.push_back(segm(l, r, d));
                l = ll;
            }
            r = c.x + t;
        }
        rs.push_back(segm(l, r, d));
    }
    int n = bs.size();
    int m = rs.size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            u[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> f;
        for (int j = 0; j < m; j++)
            if(inter(bs[i], rs[j]))
                f.push_back(j);
        for (int x : f)
            for (int y : f)
            {
                if (x == y)
                    continue;
                ++u[x][y];
                if (u[x][y] >= 2)
                    return true;
            }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        blue[x + y + A].push_back(point(2 * x, 2 * y));
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        red[y - x + A].push_back(point(2 * x, 2 * y));
    }
    for (int i = 0; i < N; i++)
    {
        sort(blue[i].begin(), blue[i].end(), cmp);
        sort(red[i].begin(), red[i].end(), cmp);
    }
    int l = 1;
    int r = N;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (good(l))
        cout << l;
    else
    {
        cout << "Poor Sereja!";
    }

    return 0;
}