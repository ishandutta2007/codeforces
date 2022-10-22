#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

vec<LL> ans;

struct question
{
    int l, r;
    int id;

    question()
    {
        l = r = 0;
        id = 0;
    }

    question(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}

    bool operator < (const question & b)
    {
        return (r < b.r);
    }

    const question & operator = (const question & b)
    {
        l = b.l;
        r = b.r;
        id = b.id;

        return *this;
    }
};

struct Node
{
    LL y, ans;
    question x;
    Node *l, *r;

    Node()
    {
        x = question();
        l = r = 0;
        y = rand() % inf;
        ans = inf64;
    }

    Node(question & b)
    {
        y = rand() % inf;
        x = b;
        l = r = 0;
        ans = inf64;
    }

    ~Node()
    {
        if(l) delete l;
        if(r) delete r;
    }

    void show()
    {
        if(l) l->show();
        cout << "{ " << " [" << x.l << ";" << x.r << "] : " << ans << " }\n";
        if(r) r->show();
    }
};

void clear(Node *& v)
{
    ans[v->x.id] = min(ans[v->x.id], v->ans);
    v->ans = inf64;
}

void pushdown(Node *& v)
{
    if(v->l) v->l->ans = min(v->l->ans, v->ans);
    if(v->r) v->r->ans = min(v->r->ans, v->ans);
    clear(v);
}

void merge(Node *& v, Node * l, Node * r)
{
    if(!l || !r)
    {
        v = (l?l : r);
        return;
    }

    pushdown(l);
    pushdown(r);

    if(l->y >= r->y)
    {
        merge(l->r, l->r, r);
        v = l;
    }else
    {
        merge(r->l, l, r->l);
        v = r;
    }
}

void split(Node * v, Node *& l, Node *& r, LL x)
{
    if(!v)
    {
        l = r = 0;
        return;
    }

    pushdown(v);

    if(v->x.r < x)
    {
        split(v->r, v->r, r, x);
        l = v;
    }else
    {
        split(v->l, l, v->l, x);
        r = v;
    }
}

void make(Node *& v)
{
    if(!v) return;
    pushdown(v);
    make(v->l);
    make(v->r);
}

bool solve()
{
    int n, m;

    scanf("%d %d", &n, &m);

    ans.assign(m + 1, inf64);
    vec< LL > a(n + 1), to(n + 1, -1);
    map<LL, int> last;

    for(int i(1);i <= n;i++) scanf("%I64d", &a[i]);
    
    for(int i(n);i >= 1;i--)
    {
        if(last[a[i]] != 0) to[i] = last[a[i]];
        last[a[i]] = i;
    }

    vec< vec< question > > q(n + 1);

    for(int i(0);i < m;i++)
    {
        question a;
        scanf("%d %d", &a.l, &a.r);
        a.id = i + 1;
        q[a.l].push_back(a);
    }

    //cout << "\n\n";

    Node *t, *nl, *nm, *nr;
    t = 0;

    for(int i(1);i <= n;i++)
    {
        for(int j(0);j < (int)q[i].size();j++)
        {
            nl = nm = nr = 0;

            split(t, nl, nr, q[i][j].r);
            merge(nl, nl, new Node(q[i][j]));
            merge(t, nl, nr);
        }

        if(to[i] == -1) continue;

        nl = nm = nr = 0;

        split(t, nl, nr, to[i]);

        if(nr) nr->ans = min(nr->ans, to[i] - i);

        merge(t, nl, nr);

        //cout << "\n---\n";
        //t->show();
        //cout << "\n---\n";
    }

    //cout << "\n\n";

    make(t);

    for(int i(1);i <= m;i++) printf("%I64d\n", (ans[i] == inf64?-1ll : ans[i]));

    return true;
}   

int main()
{
    //while(solve());
    solve();

    return 0;
}