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

const int INF = (int) 1e9;
const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct TreeMinAdd
{
    int mn[SZ], _add[SZ];

    TreeMinAdd() : mn(), _add() {}

    void push(int v, int x)
    {
        mn[v] += x;
        _add[v] += x;
    }

    void push(int v)
    {
        if (v >= LEVEL) return;
        push(2 * v, _add[v] );
        push(2 * v + 1, _add[v] );
        _add[v] = 0;
    }

    void update(int v)
    {
        if (v >= LEVEL) return;
        mn[v] = min(mn[2 * v], mn[2 * v + 1] );
    }

    void add(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r)
        {
            push(v, x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        add(2 * v, tl, tm, l, r, x);
        add(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }

    void add(int l, int r, int x)
    {
        if (l > r) return;
        eprintf("add %d, %d : %d\n", l, r, x);
        add(1, 0, LEVEL - 1, l, r, x);
    }

    void ppush(int v)
    {
        if (v != 1) ppush(v / 2);
        push(v);
    }

    int getLeft(int pos)
    {
        int v = pos + LEVEL;
        ppush(v);
        
        if (mn[v] <= 0)
            return pos;


        while (v > 1)
        {
            if (v & 1)
            {
                v--;
                if (mn[v] <= 0) break;
            }
            else
            {
                v /= 2;
            }
        }
        if (v == 1) return 0;

        while (v < LEVEL)
        {
            push(v);
            v = 2 * v + 1;;
            if (mn[v] > 0)
                v--;
        }
        return (v + 1) - LEVEL;
    }

    int getMin(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l) return INF;
        if (l <= tl && tr <= r)
            return mn[v];
        push(v);
        int tm = (tl + tr) / 2;
        int ans = min(
                getMin(2 * v, tl, tm, l, r),
                getMin(2 * v + 1, tm + 1, tr, l, r)
                );
        update(v);
        return ans;
    }

    int getMin(int l, int r)
    {
        return getMin(1, 0, LEVEL - 1, l, r);
    }
} treeMinAdd;


struct Tree
{
    pair <int, int> mn[SZ], mx[SZ];

    Tree() : mn(), mx() {}


    void update(int v)
    {
        if (v >= LEVEL) return;
        mn[v] = min(mn[2 * v], mn[2 * v + 1] );
        mx[v] = max(mx[2 * v], mx[2 * v + 1] );
    }

    void setNo(int pos)
    {
        pos += LEVEL;
        mn[pos] = make_pair(INF, pos - LEVEL);
        mx[pos] = make_pair(-INF, pos - LEVEL);
        while (pos > 1)
        {
            pos /= 2;
            update(pos);
        }
    }

    void set(int pos, int x)
    {
        pos += LEVEL;
        mn[pos] = make_pair(x, pos - LEVEL);
        mx[pos] = make_pair(x, pos - LEVEL);
        while (pos > 1)
        {
            pos /= 2;
            update(pos);
        }
    }

    pair <int, int> getMin(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l) return make_pair(INF, -1);
        if (l <= tl && tr <= r)
            return mn[v];
        int tm = (tl + tr) / 2;
        pair <int, int> ans = min(
                getMin(2 * v, tl, tm, l, r),
                getMin(2 * v + 1, tm + 1, tr, l, r)
                );
        update(v);
        return ans;
    }

    pair <int, int> getMin(int l, int r)
    {
        return getMin(1, 0, LEVEL - 1, l, r);
    }
    
    pair <int, int> getMax(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l) return make_pair(-INF, -1);
        if (l <= tl && tr <= r)
            return mx[v];
        int tm = (tl + tr) / 2;
        pair <int, int> ans = max(
                getMax(2 * v, tl, tm, l, r),
                getMax(2 * v + 1, tm + 1, tr, l, r)
                );
        update(v);
        return ans;
    }

    pair <int, int> getMax(int l, int r)
    {
        return getMax(1, 0, LEVEL - 1, l, r);
    }
} tree;


const int N = (int) 3e5 + 100;
int a[N];



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i] );
        tree.set(i, a[i] );
    }

    long long ans = 0;
    
    while (true)
    {
        eprintf("\n");
        pair <int, int> mn = tree.getMin(0, n - 1);
        if (mn.first == INF) break;
        tree.setNo(mn.second);

#ifdef LOCAL
//        for (int i = 0; i < n; i++)
//            eprintf("%d ", treeMinAdd.getMin(i, i) );
//        eprintf("\n");
#endif

        
        int pos = treeMinAdd.getLeft(mn.second);
//        eprintf("(%d, %d)\n", mn.first, mn.second);
//        eprintf("mn.second = %d, pos = %d\n", mn.second, pos);
        pair <int, int> mx = tree.getMax(pos, n - 1);
        if (mx.first == -INF) continue;
        ans += mx.first - mn.first;
        tree.setNo(mx.second);

        eprintf("%d .. %d :  %d, %d\n", mn.second, mx.second, mn.first, mx.first);
        if (mn.second <= mx.second)
            treeMinAdd.add(mn.second, mx.second - 1, 1);
        else
            treeMinAdd.add(mx.second, mn.second - 1, -1);
    }

    printf("%lld\n", ans);

	return 0;
}