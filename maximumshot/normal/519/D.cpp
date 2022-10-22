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

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

struct Node
{
    int cnt;
    LL x, y;
    Node *l, *r;

    Node()
    {
        cnt = 0;
        x = y = 0;
        l = r = 0;
    }

    Node(LL _x) : x(_x), y(rand() % inf), cnt(1), l(0), r(0) {}

    ~Node()
    {
        if(l) delete l;
        if(r) delete r;
    }
};

void update(Node *& v)
{
    int c = 1;

    if(v->l) c += v->l->cnt;
    if(v->r) c += v->r->cnt;

    v->cnt = c;
}

void merge(Node *& v, Node *l, Node *r)
{
    if(!l || !r)
    {
        v = (l?l : r);
        return;
    }

    if(l->y >= r->y)
    {
        merge(l->r, l->r, r);
        v = l;
    }else
    {
        merge(r->l, l, r->l);
        v = r;
    }

    if(v) update(v);
}

void split(Node *v, Node *& l, Node *& r, LL x)
{
    if(!v)
    {
        l = r = 0;
        return;
    }

    if(v->x <= x)
    {
        split(v->r, v->r, r, x);
        l = v;
    }else
    {
        split(v->l, l, v->l, x);
        r = v;
    }

    if(l) update(l);
    if(r) update(r);
}

bool solve()
{
    vec<LL> val(26);

    for(int i(0);i < 26;i++) cin >> val[i];

    string a;
    cin >> a;

    int n = (int)a.size();
    LL s = 0;

    vec< vec<LL> > sum(26);

    for(int i(0);i < n;i++)
    {
        s += val[a[i] - 'a'];
        sum[a[i] - 'a'].push_back(s);
    }

    Node *t, *nl, *nm, *nr;

    LL ans = 0;

    for(int i(0);i < 26;i++)
    {
        t = 0;

        for(int j(0);j < (int)sum[i].size();j++)
        {
            nl = nm = nr = 0;

            if(!j)
            {
                merge(t, t, new Node(sum[i][j]));
                continue;
            }

            split(t, nl, nr, sum[i][j] - val[i]);
            split(nl, nl, nm, sum[i][j] - val[i] - 1);

            LL tmp = (nm?nm->cnt : 0);

            ans += tmp;

            merge(nl, nl, nm);
            merge(t, nl, nr);

            nl = nm = nr = 0;

            split(t, nl, nr, sum[i][j]);

            merge(nl, nl, new Node(sum[i][j]));
            merge(t, nl, nr);
        }
    }

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}