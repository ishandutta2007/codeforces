#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

int n, k;

struct Node
{
    int ind;
    LL mn, delt;

    Node()
    {
        ind = -1;
        mn = delt = 0;
    }

    const Node & operator = (const Node & b)
    {
        ind = b.ind;
        mn = b.mn;
        delt = b.delt;

        return *this;
    }
};

vec<Node> t;

Node pushup(Node l, Node r)
{
    Node ans = Node();

    ans.delt = 0;
    ans.mn = min(l.mn, r.mn);
    ans.ind = (l.mn <= r.mn?l.ind : r.ind);

    return ans;
}

void up(int v, int tl, int tr, int pos, LL val)
{
    if(tl == tr)
    {
        t[v].delt = 0;
        t[v].mn = val;
    }else
    {
        int tm = (tl + tr) >> 1;
        if(pos <= tm) up(v << 1, tl, tm, pos, val);
        else up(v << 1 | 1, tm + 1, tr, pos, val);
        t[v] = pushup(t[v << 1], t[v << 1 | 1]);
    }
}

void build(int v, int tl, int tr)
{
    if(tl == tr) t[v].mn = 0, t[v].ind = tl;
    else
    {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = pushup(t[v << 1], t[v << 1 | 1]);
    }
}

bool solve()
{
    scanf("%d %d", &n, &k);

    t.resize(4 * (k + 1), Node());

    build(1, 1, k);

    for(int i(0);i < n;i++)
    {
        LL m, s;
        scanf("%I64d %I64d", &s, &m);
        printf("%I64d\n", max(s, t[1].mn) + m);
        up(1, 1, k, t[1].ind, max(s, t[1].mn) + m);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}