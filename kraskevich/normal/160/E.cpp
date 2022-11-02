#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

const int inf = 1000 * 1000 * 1000 + 1;
const pii INF = pii(inf, 0);

class segm_tree
{
    vector<set<pii> > t;
    int n;
    
    pii getMin(int i, int l, int r, int tl, int tr, int x)
    {
        if (l == tl && r == tr)
        {
            set<pii>::iterator ii = t[i].lower_bound(pii(x, 0));
            if (ii == t[i].end())
                return INF;
            else
                return *ii;
        }
        
        int ll = 2 * i + 1, rr = 2 * i + 2, m = (tl + tr) >> 1;
        pii ml = INF, mr = INF;
        
        if (l <= m)
            ml = getMin(ll, l, min(r, m), tl, m, x);
        if (r > m) 
            mr = getMin(rr, max(m + 1, l), r, m + 1, tr, x);
        
        return min(ml, mr);
    }
    
    void upd(int i, int l, int r, int tl, int tr, pii val)
    {
        t[i].insert(val);
        if  (tl != l || tr != r)
        {    
            int ll = 2 * i + 1, rr = 2 * i + 2, m = (tl + tr) >> 1;
            
            if (l <= m)
                upd(ll, l, min(r, m), tl, m, val);
            if (r > m) 
                upd(rr, max(m + 1, l), r, m + 1, tr, val);
        }
    }
    
    public:
        void init(int _n)
        {
            n = _n;
            t.resize(4 * n + 1);
        }
        
        int getMin(int r, int time)
        {
            pii cur = getMin(0, r, n - 1, 0, n - 1, time);
            if (cur.F == inf)
                return -1;
            else
                return cur.S;
        }
        
        void upd(int r, pii val)
        {
            upd(0, r, r, 0, n - 1, val);
        }
};

struct event
{
    int l, r, time, id, type;
    event() {}
    void scan(int _id, int _type)
    {
        scanf("%d%d%d", &l, &r, &time);
        id = _id;
        type = _type;
    }
};

bool cmp(event a, event b)
{
    return a.l < b.l || a.l == b.l && a.type < b.type;
}

const int N = 100 * 1000 + 1;
int ans[N];
set<int> ur;
map<int, int> getr;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<event> e(n + m);
    
    for (int i = 0; i < n; ++i)
    {
        e[i].scan(i + 1, 0);
        ur.insert(e[i].r);
    }
    for (int i = 0; i < m; ++i)
    {
        e[i + n].scan(i, 1);
        ur.insert(e[i+n].r);
    }
    
    sort(e.begin(), e.end(), cmp);
    
    int cnt = 0;
    for (set<int>::iterator i = ur.begin(); i != ur.end(); ++i, ++cnt)
        getr.insert(MP(*i, cnt));
    
    segm_tree tree;
    tree.init(cnt);
    
    for (int i = 0; i < e.size(); ++i)
        if (e[i].type == 0)
            tree.upd(getr[e[i].r], pii(e[i].time, e[i].id));
        else
            ans[e[i].id] = tree.getMin(getr[e[i].r], e[i].time);
    
    for (int i = 0; i < m; ++i)
        printf("%d ", ans[i]);

    return 0;
}