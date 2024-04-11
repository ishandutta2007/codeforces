#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int MOD = 998244353;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
void smul(int &a, int b)
{
    a = mul(a, b);
}
int mul2(int a)
{
    sadd(a, a);
    return a;
}
int fpow(int x, int n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}
int rev(int x)
{
    return fpow(x, MOD - 2);
}
int rev2;


const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SIZE = (LEVEL << 1);

struct Tree
{
    int val[SIZE], _mul[SIZE], _add[SIZE];
    Tree() 
    {
        for (int i = 0; i < SIZE; i++)
            _mul[i] = 1;
    }
    
    void push(int v, int len, int ml, int ad)
    {
        if (ml != 1)
        {
            smul(_mul[v], ml);
            smul(_add[v], ml);
            smul(val[v], ml);
        }
        
        if (ad != 0)
        {
            sadd(_add[v], ad);
            sadd(val[v], mul(ad, len) );
        }
    }
    void push(int v, int len)
    {
        if (len > 1)
        {
            push(2 * v, len / 2, _mul[v], _add[v] );
            push(2 * v + 1, len / 2, _mul[v], _add[v] );
        }
        _mul[v] = 1;
        _add[v] = 0;
    }
    void update(int v)
    {
        val[v] = add(val[2 * v], val[2 * v + 1] );
    }

    void treeAdd(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r)
        {
            push(v, tr - tl + 1, 1, x);
            return;
        }
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        treeAdd(2 * v, tl, tm, l, r, x);
        treeAdd(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }
    void treeAdd(int l, int r, int x)
    {
        treeAdd(1, 0, LEVEL - 1, l, r, x);
    }

    void treeMul(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || l > tr) return;
        if (l <= tl && tr <= r)
        {
            push(v, tr - tl + 1, x, 0);
            return;
        }
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        treeMul(2 * v, tl, tm, l, r, x);
        treeMul(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }
    void treeMul(int l, int r, int x)
    {
        treeMul(1, 0, LEVEL - 1, l, r, x);
    }

    int getSum(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || l > tr) return 0;
        if (l <= tl && tr <= r)
        {
            return val[v];
        }
        push(v, tr - tl + 1);
        int tm = (tl + tr) / 2;
        int ans = add(
                getSum(2 * v, tl, tm, l, r),
                getSum(2 * v + 1, tm + 1, tr, l, r) );
        return ans;
    }
    int getSum(int l, int r)
    {
        return getSum(1, 0, LEVEL - 1, l, r);
    }
};
Tree tree;

struct Qu
{
    int t, l, r, x, id;
    Qu() : t(), l(), r(), x(), id() {}

    void read(int _id)
    {
        id = _id;
        scanf("%d%d%d", &t, &l, &r);
        l--;
        r--;
        if (t == 1)
            scanf("%d", &x);
    }
};


struct Event
{
    int type, x, val;

    Event(int _type, int _x, int _val) : type(_type), x(_x), val(_val) {}

    bool operator < (const Event &A) const
    {
        return x < A.x;
    }
};

vector <Qu> qu;
const int N = (int) 2e5 + 100;
vector <Qu> qs[N];
vector <pair <int, int> > ops[N];

void addOp(int l, int r, int t)
{
    ops[t].emplace_back(l, r);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    rev2 = rev(2);

    int n, qr;
    scanf("%d%d", &n, &qr);
    for (int it = 0; it < qr; it++)
    {
        Qu q;
        q.read(it);
        qu.push_back(q);
        if (q.t == 1)
            qs[q.x].push_back(q);
    }

    for (int it = 0; it < N; it++)
    {
        if (qs[it].empty()) continue;
        vector <Event> ev;
        for (Qu q : qs[it] )
        {
            ev.emplace_back(0, q.l, q.id);
            ev.emplace_back(1, q.r + 1, q.id);
        }
        sort(ev.begin(), ev.end() );
        multiset <int> ids;
        for (int i = 0; i < (int) ev.size(); i++)
        {
            if (ev[i].type == 0)
                ids.insert(ev[i].val);
            else
                ids.erase(ids.find(ev[i].val) );
            if (i + 1 < (int) ev.size() && ev[i + 1].x != ev[i].x && !ids.empty() )
            {
                addOp(ev[i].x, ev[i + 1].x - 1, *ids.begin() );
            }
        }
    }

    for (int it = 0; it < qr; it++)
    {
        Qu q = qu[it];
        if (q.t == 2)
        {
            int ans = tree.getSum(q.l, q.r);
            printf("%d\n", ans);
        }
        else
        {
            tree.treeMul(q.l, q.r, 2);
            for (auto op : ops[it] )
            {
                tree.treeMul(op.first, op.second, rev2);
                tree.treeAdd(op.first, op.second, 1);
            }
        }
    }


	return 0;
}