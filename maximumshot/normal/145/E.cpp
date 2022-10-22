#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

int n, m;
string a;

struct tree
{
    bool flag;
    int f, s, fs, sf;
    tree()
    {
        f = s = fs = sf = flag = 0;
    }
};
vec<tree> t;

void pushup(LL v)
{
    t[v].f = t[v << 1].f + t[v << 1 | 1].f;
    t[v].s = t[v << 1].s + t[v << 1 | 1].s;
    t[v].fs = max(max(t[v << 1].fs, t[v << 1 | 1].fs), max(t[v << 1].f + t[v << 1 | 1].fs, t[v << 1].fs + t[v << 1 | 1].s));
    t[v].sf = max(max(t[v << 1].sf, t[v << 1 | 1].sf), max(t[v << 1].sf + t[v << 1 | 1].f, t[v << 1].s + t[v << 1 | 1].sf));
}

void pushdown(LL v)
{
    if(t[v].flag)
    {
        t[v << 1].flag ^= 1;
        t[v << 1 | 1].flag ^= 1;
        swap(t[v << 1].s, t[v << 1].f),
        swap(t[v << 1].fs, t[v << 1].sf);
        swap(t[v << 1 | 1].s, t[v << 1 | 1].f),
        swap(t[v << 1 | 1].fs, t[v << 1 | 1].sf);
        t[v].flag = 0;
    }
}

void build(LL v, LL tl, LL tr)
{
    if(tl == tr)
    {
        t[v].sf = t[v].fs = 1;
        if(a[tl] == '4') t[v].f = 1;
        else t[v].s = 1;
    }else
    {
        LL tm = (tl + tr) >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        pushup(v);
    }
}

void up(LL v, LL tl, LL tr, LL l, LL r)
{
    if(l <= tl && tr <= r) 
    {
        t[v].flag ^= 1;
        swap(t[v].f, t[v].s),
        swap(t[v].sf, t[v].fs);
    }else
    {
        LL tm = (tl + tr) >> 1;
        pushdown(v);

        if(l <= tm) up(v << 1, tl, tm, l, r);
        if(r > tm) up(v << 1 | 1, tm + 1, tr, l, r);

        pushup(v);
    }
}

bool solve()
{
    scanf("%d %d", &n, &m);
    cin >> a;

    a = ' ' + a;

    t.resize(4 * (n + 1));

    build(1, 1, n);

    string q;
    int l, r;

    for(int i(0);i < m;i++)
    {
        cin >> q;

        if(q == "count") pushdown(1), printf("%d\n", t[1].fs);
        else
        {
            scanf("%d %d", &l, &r); 
            up(1, 1, n, l, r);
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