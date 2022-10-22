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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

const LL N = 100100;

LL n, m;

struct tree
{
    LL and, or, delt;

    tree()
    {
        and = -1;
        or = delt = 0;
    }
};

vec<tree> t;
vec< pair< pair<LL, LL>, LL> > z;

void up(LL v, LL tl, LL tr, LL l, LL r, LL q)
{
    if(l <= tl && tr <= r) t[v].or |= q, t[v].delt |= q;
    else
    {
        LL tm = (tl + tr) >> 1;
            
        if(t[v].delt)
        {
            t[v << 1].delt |= t[v].delt;
            t[v << 1 | 1].delt |= t[v].delt;
            t[v << 1].or |= t[v].delt;
            t[v << 1 | 1].or |= t[v].delt;
            t[v].delt = 0;
        }

        if(l <= tm) up(v << 1, tl, tm, l, r, q);
        if(r > tm) up(v << 1 | 1, tm + 1, tr, l, r, q);

        t[v].or = (t[v << 1].or | t[v << 1 | 1].or);
    }
}

LL get(LL v, LL tl, LL tr, LL pos)
{
    if(tl == tr) return t[v].or;
    else
    {
        LL tm = (tl + tr) >> 1;

        if(t[v].delt)
        {
            t[v << 1].delt |= t[v].delt;
            t[v << 1 | 1].delt |= t[v].delt;
            t[v << 1].or |= t[v].delt;
            t[v << 1 | 1].or |= t[v].delt;
            t[v].delt = 0;
        }

        if(pos <= tm) return get(v << 1, tl, tm, pos);
        else return get(v << 1 | 1, tm + 1, tr, pos);
    }
}

void build(LL v, LL tl, LL tr)
{
    if(tl == tr) t[v].and = get(1, 1, n, tl);
    else
    {
        LL tm = (tl + tr) >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v].and = (t[v << 1].and & t[v << 1 | 1].and);
    }
}

LL getbit(LL v, LL tl, LL tr, LL l, LL r)
{
    if(l <= tl && tr <= r) return t[v].and;
    else
    {
        LL tm = (tl + tr) >> 1;
        LL L, R;
        L = R = -1;

        if(l <= tm) L = getbit(v << 1, tl, tm, l, r);
        if(r > tm) R = getbit(v << 1 | 1, tm + 1, tr, l, r);

        return (L & R);
    }
}

bool solve()
{
    scanf("%I64d %I64d", &n, &m);

    t.resize(4 * (n + 1), tree());

    for(LL l, r, q, i(0);i < m;i++)
    {
        scanf("%I64d %I64d %I64d", &l, &r, &q);
        up(1, 1, n, l, r, q);
        z.push_back(mp(mp(l, r), q));
    }

    build(1, 1, n);

    for(int i(0);i < m;i++)
    {
        if(getbit(1, 1, n, z[i].first.first, z[i].first.second) != z[i].second)
        {
            puts("NO");
            return true;
        }
    }

    puts("YES");

    for(int i(1);i <= n;i++) printf("%I64d ", get(1, 1, n, i));

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}