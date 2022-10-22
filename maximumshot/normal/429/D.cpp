#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
//
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}
int sign(LD x) {return (x >= 0?1 : -1);}

using namespace std;

struct point
{
    LL x, y;

    point(LL _x, LL _y) : x(_x), y(_y) {}

    bool operator < (point & b)
    {
        return (x < b.x || (x == b.x && y < b.y));
    }

    const point & operator = (const point & b)
    {
        x = b.x;
        y = b.y;
        return *this;
    }
};

int n;
vec<point> p;

LL ans(int l, int r)
{
    if(l == r) return inf64;

    vec<point> tmp;

    int tl, tr, tm;
    tm = (l + r) >> 1;

    LL midX = p[tm].x;

    // [l .. tm] [tm + 1 .. r]

    LL h1, h2, h;

    h1 = ans(l, tm);
    h2 = ans(tm + 1, r);
    h = min(h1, h2);
    
    tl = l;
    tr = tm + 1;

    while(tl <= tm && tr <= r)
    {
        if(p[tl].y <= p[tr].y) tmp.push_back(p[tl++]);
        else tmp.push_back(p[tr++]);
    }

    while(tl <= tm) tmp.push_back(p[tl++]);
    while(tr <= r) tmp.push_back(p[tr++]);

    for(int i(l);i <= r;i++) p[i] = tmp[i - l];

    tmp.clear();

    for(int i(l);i <= r;i++)
        if((p[i].x - midX) * (p[i].x - midX) <= h) 
            tmp.push_back(p[i]);

    LL th = h;

    for(int i(0);i < (int)tmp.size();i++)
    {
        for(int j(i - 1);j >= 0 && (tmp[j].y - tmp[i].y) * (tmp[j].y - tmp[i].y) <= th;j--)
        {
            LL X, Y, dist;
            X = (tmp[i].x - tmp[j].x);
            Y = (tmp[i].y - tmp[j].y);
            dist = X * X + Y * Y;
            h = min(h, dist);
        }
    }

    return h;
}

bool solve()
{
    cin >> n;

    vec<LL> a(n + 1);
    p.push_back(point(-inf64, -inf64));

    LL sum = 0; 
    for(int i(1);i <= n;i++) cin >> a[i], sum += a[i], p.push_back(point(i, sum));
    
    sort(ALL(p));

    cout << ans(1, n) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();
    
    return 0;
}