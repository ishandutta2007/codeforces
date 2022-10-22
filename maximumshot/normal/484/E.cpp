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

int n, m;
LL sz;
vec<LL> h;
vec< vec<LL> > pos;
LL *tmp;
set<LL> s;

struct Node
{
    LL preff, suff, len, tl, tr;
    Node *l, *r;

    Node()
    {
        preff = suff = len = tl = tr = 0;
        l = r = NULL;
    }

    Node(Node *v)
    {
        preff = v->preff;
        suff = v->suff;
        len = v->len;
        tl = v->tl;
        tr = v->tr;
        l = v->l;
        r = v->r;
    }

    Node(Node *L, Node *R)
    {
        l = L;
        r = R;
        tl = l->tl;
        tr = r->tr;
        len = max(l->len, r->len);
        len = max(len, l->suff + r->preff);
        if(l->preff == l->tr - l->tl + 1) preff = l->preff + r->preff;
        else preff = l->preff;
        if(r->suff == r->tr - r->tl + 1) suff = r->suff + l->suff;
        else suff = r->suff;
    }

    Node(LL L, LL R)
    {
        preff = suff = len = 0;
        l = r = NULL;
        tl = L;
        tr = R;
    }

    void build()
    {
        if(tl == tr) return;
        else
        {
            LL tm = (tl + tr) >> 1;
            l = new Node(tl, tm);
            r = new Node(tm + 1, tr);
            l->build();
            r->build();
        }
    }

    Node *insert(LL pos)
    {
        if(pos < tl || tr < pos) return this;

        LL tm = (tl + tr) >> 1; 
        Node *T = new Node(this);

        if(tl == tr)
        {
            T->preff = T->suff = T->len = 1;
            return T;
        }

        T->l = l->insert(pos);
        T->r = r->insert(pos);

        Node *ans = new Node(T->l, T->r);

        return ans;
    }

    pair< pair<LL, LL>, pair<pair<LL, LL>, LL> > get(LL L, LL R)
    {
        if(tl > R || tr < L) return mp(mp(0, 0), mp(mp(0, 0), 0));
        if(L <= tl && tr <= R) return mp(mp(preff, suff), mp(mp(tl, tr), len));
        else
        {
            LL tm = (tl + tr) >> 1;
            pair< pair<LL, LL>, pair<pair<LL, LL>, LL> > ql, qr, ans;
            ql = qr = ans = mp(mp(0, 0), mp(mp(0, 0), 0));

            if(L <= tm && R > tm)
            {
                ql = l->get(L, R);
                qr = r->get(L, R);

                ans.second.second = max(max(ql.second.second, qr.second.second), ql.first.second + qr.first.first);
                ans.first.first = ql.first.first;
                ans.first.second = qr.first.second;
                if(ql.first.first == ql.second.first.second - ql.second.first.first + 1) ans.first.first += qr.first.first;
                if(qr.first.second == qr.second.first.second - qr.second.first.first + 1) ans.first.second += ql.first.second;

                return ans;
            }else if(L <= tm) return l->get(L, R);
            else return r->get(L, R);
        }
    }
};

vec<Node*> root;

bool solve()
{
    scanf("%d", &n);

    h.resize(n + 1);

    for(int i(1);i <= n;i++) scanf("%I64d", &h[i]), s.insert(h[i]);

    sz = (int)s.size();

    tmp = new LL[sz + 10];
    pos.resize(sz + 1);
    root.resize(sz + 2);

    root[sz + 1] = new Node(1, n);
    root[sz + 1]->build();
    
    int C = 1;

    for(set<LL>::iterator i = s.begin();i != s.end();i++) tmp[C++] = *i;

    for(int i(1);i <= n;i++)
    {
        int val = lower_bound(tmp + 1, tmp + sz + 1, h[i]) - tmp; // [1 .. sz + 1)
        pos[val].push_back(i);
    }

    for(int i(sz);i >= 1;i--)
    {
        root[i] = root[i + 1];
        for(int j(0);j < (int)pos[i].size();j++) root[i] = root[i]->insert(pos[i][j]);
    }

    scanf("%d", &m);

    LL le, ri, w, l, r, mid, q;

    while(m--)
    {
        scanf("%I64d %I64d %I64d", &le, &ri, &w);
        l = 1, r = sz;

        while(l < r)
        {
            mid = (l + r + 1) >> 1;

            q = root[mid]->get(le, ri).second.second;
            
            if(q >= w) l = mid;
            else r = mid - 1;
        }

        printf("%I64d\n", tmp[l]);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}