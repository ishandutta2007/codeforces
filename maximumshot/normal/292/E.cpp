// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

int n, m;

struct tree
{
    int ql, qr;
    LL x;

    tree()
    {
        ql = qr = -1;
        x = 0;
    }
};

vec<LL> a, b;
vec<tree> t;

void build(LL v, LL tl, LL tr)
{
    if(tl == tr) t[v].x = b[tl];
    else
    {
        LL tm = (tl + tr) >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
    }
}

void push(LL v, LL tl, LL tr)
{
    if(t[v].ql != -1)
    {
        LL tm = (tl + tr) >> 1;

        t[v << 1].ql = t[v].ql;
        t[v << 1 | 1].qr = t[v].qr;
        t[v << 1].qr = t[v << 1].ql + tm - tl;
        t[v << 1 | 1].ql = t[v << 1 | 1].qr - tr + tm + 1;

        t[v].ql = t[v].qr = -1;
    }
}

void update(LL v, LL tl, LL tr, LL l, LL r, LL ql, LL qr)
{
    if(l <= tl && tr <= r)
    {
        int fl, fr;

        fl = tl - l + ql;
        fr = tr - l + ql;

        t[v].ql = fl;
        t[v].qr = fr;
    }else
    {
        LL tm = (tl + tr) >> 1;

        push(v, tl, tr);

        if(l <= tm) update(v << 1, tl, tm, l, r, ql, qr);
        if(r > tm) update(v << 1 | 1, tm + 1, tr, l, r, ql, qr);
    }
}

LL get(LL v, LL tl, LL tr, LL pos)
{
    if(tl == tr)
    {
        if(t[v].ql != -1) t[v].x = a[t[v].ql], t[v].ql = t[v].qr = -1;
        return t[v].x;
    }else
    {
        LL tm = (tl + tr) >> 1;

        push(v, tl, tr);

        if(pos <= tm) return get(v << 1, tl, tm, pos);
        else return get(v << 1 | 1, tm + 1, tr, pos);
    }
}

bool solve()
{
    scanf("%d %d", &n, &m);

    a.resize(n + 1);
    b.resize(n + 1);

    for(int i(1);i <= n;i++) scanf("%I64d", &a[i]);
    for(int i(1);i <= n;i++) scanf("%I64d", &b[i]);

    t.resize(4 * (n + 1), tree());

    build(1, 1, n);

    int type, x, y, k;

    for(int i(0);i < m;i++)
    {
        scanf("%d", &type);

        if(type == 1)
        {
            scanf("%d %d %d", &x, &y, &k);
            update(1, 1, n, y, y + k - 1, x, x + k - 1);
        }else
        {
            scanf("%d", &x);
            printf("%I64d\n", get(1, 1, n, x));
        }
    }

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}