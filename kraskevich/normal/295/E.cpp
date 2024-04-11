#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair

const long long INF = (long long)2e9 + 10;

struct func
{
    long long s;
    long long minx, maxx;
    long long pref;
    long long suff;

    func(long long a = 0, long long b = INF, long long c = -INF, long long d = 0, long long e = 0): s(a), minx(b), maxx(c), pref(d), suff(e) {}
};

struct treap
{
    struct node
    {
        node *l, *r;
        long long key;
        int cnt, prior;
        func f;//paste a function here
        node() {}
        node(long long _key): key(_key), cnt(1), prior(rand()), l(NULL), r(NULL), f(0, _key, _key, 0, 0) {}
    };

    int get_cnt(node *t)
    {
        if (t)
            return t->cnt;
        else
            return 0;
    }

    func get_func(node *t) //a function
    {
        if (t == NULL)
            return func(0, INF, -INF, 0, 0);
        else
            return t->f;
    }

    void update(node *t)
    {
        if (t == NULL)
            return;
        t->cnt = get_cnt(t->l) + get_cnt(t->r) + 1;
        func fl = get_func(t->l);
        func fr = get_func(t->r);
        func ff;
        ff.minx = min(fl.minx, t->key);
        ff.maxx = max(fr.maxx, t->key);
        long long lo = fl.maxx;
        long long hi = fr.minx;
        long long mi = t->key;
        ff.pref = fl.pref + fr.pref + (fr.minx - (get_cnt(t->l) ? fl.minx : mi)) * get_cnt(t->r) + mi - (get_cnt(t->l) == 0 ? mi : fl.minx);
        ff.suff = fr.suff + fl.suff + ((get_cnt(t->r) ? fr.maxx : mi) - fl.maxx) * get_cnt(t->l) + (get_cnt(t->r) == 0 ? mi : fr.maxx) - mi;
        ff.s = fl.s + fr.s + fl.suff * get_cnt(t->r) + fr.pref * get_cnt(t->l) + (hi - lo) * get_cnt(t->l) * get_cnt(t->r);
        ff.s += fl.suff + get_cnt(t->l) * (mi - lo);
        ff.s += fr.pref + get_cnt(t->r) * (hi - mi);
        t->f = ff;
    }


    void print(node *t)
    {
        if (!t)
            return;
        print(t->l);
        cout << t->key << " ";
        print(t->r);
    }

    node *root;

    treap(node *_root = NULL): root(_root) {}



    void split_by_key(node *t, node *&l, node *&r, int key) //left subtree - less, right - greater or equal
    {
        if (t == NULL)
        {
            l = NULL;
            r = NULL;
            update(t);
            return;
        }
        if (t->key >= key)
        {
            split_by_key(t->l, l, t->l, key);
            r = t;
        }
        else
        {
            split_by_key(t->r, t->r, r, key);
            l = t;
        }
        update(t);
    }

    void split_by_pos(node *t, node *&l, node *&r, int pos, int add)
    {
        if (t == NULL)
        {
            l = NULL;
            r = NULL;
            update(t);
            return;
        }
        int cur = get_cnt(t->l) + add;
        if (cur >= pos)
        {
            split_by_pos(t->l, l,  t->l, pos, add);
            r = t;
        }
        else
        {
            split_by_pos(t->r, t->r, r, pos, cur + 1);
            l = t;
        }
        update(t);
    }

    void merge(node *&t, node *l, node *r)
    {
        if (l == NULL || r == NULL)
        {
            t = (l == NULL ? r : l);
            update(t);
            return;
        }
        if (l->prior > r->prior)
        {
            merge(l->r, l->r, r);
            t = l;
        }
        else
        {
            merge(r->l, l, r->l);
            t = r;
        }
        update(t);
    }

    void insert(int key)
    {
        node *nnode = new node(key);
        node *l, *r;
        split_by_key(root, l, r, key);
        merge(root, l, nnode);
        merge(root, root, r);
    }

    long long erase(long long key)
    {
        node *l, *r, *mid;
        split_by_key(root, l, r, key + 1);
        split_by_key(l, l, mid, key);
        long long ret = mid->key;
        merge(root, l, r);
        return ret;
    }

    long long getAns(long long L, long long R)
    {
        node *l, *r, *mid;
        split_by_key(root, l, r, L);
        split_by_key(r, mid, r, R + 1);
        long long ret = get_func(mid).s;
        merge(root, l, mid);
        merge(root, root, r);
        return ret;
    }

    void print_tree()
    {
        cout << endl;
        print(root);
        cout << endl;
    }
};


treap tree;
map<int, int> gx;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        tree.insert(x);
        gx[i] = x;
    }


    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            --y;
            long long xx = gx[y];
            tree.erase(xx);
            xx += z;
            gx[y] = xx;
            tree.insert(xx);
        }
        else
        {
            cout << tree.getAns(y, z) << "\n";
        }
        //tree.print_tree();
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}