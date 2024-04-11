#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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

const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);
const int BASE = LEVEL / 2;

struct Tree
{
    int fix[SZ], mul[SZ];

    Tree() : fix(), mul()
    {
        for (int i = 0; i < SZ; i++)
            mul[i] = 1;
    }

    void pushFix(int v, int f)
    {
        mul[v] = 1;
        fix[v] = f;
    }

    void pushMul(int v, int m)
    {
        mul[v] *= m;
    }

    void push(int v)
    {
        if (fix[v] != 0)
        {
            pushFix(2 * v, fix[v]);
            pushFix(2 * v + 1, fix[v]);
            fix[v] = 0;
        }
        if (mul[v] != 1)
        {
            pushMul(2 * v, mul[v]);
            pushMul(2 * v + 1, mul[v]);
            mul[v] = 1;
        }
    }

    void mulSeg(int v, int tl, int tr, int l, int r, int val)
    {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r)
        {
            pushMul(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        mulSeg(2 * v, tl, tm, l, r, val);
        mulSeg(2 * v + 1, tm + 1, tr, l, r, val);
    }

    void mulSeg(int l, int r, int val)
    {
        if (l > r) return;
        eprintf("mul seg [%d, %d] : %d\n", l, r, val);
        mulSeg(1, 0, LEVEL - 1, l + BASE, r + BASE, val);
    }
    
    void fixSeg(int v, int tl, int tr, int l, int r, int val)
    {
        if (r < tl || tr < l) return;
        if (l <= tl && tr <= r)
        {
            //eprintf("pushFix : %d : %d %d : %d\n", v, tl - BASE, tr - BASE, val);
            pushFix(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        fixSeg(2 * v, tl, tm, l, r, val);
        fixSeg(2 * v + 1, tm + 1, tr, l, r, val);
    }

    void fixSeg(int l, int r, int val)
    {
        if (l > r) return;
        eprintf("fix seg [%d, %d] : %d\n", l, r, val);
        fixSeg(1, 0, LEVEL - 1, l + BASE, r + BASE, val);
    }

    int getVal(int v, int tl, int tr, int pos)
    {
        if (tl == tr && tl == pos)
        {
            int val = 1;
            if (fix[v] != 0)
                val = fix[v];
            val *= mul[v];
            return val;
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm) return getVal(2 * v, tl, tm, pos);
        return getVal(2 * v + 1, tm + 1, tr, pos);
    }

    int getVal(int pos)
    {
        return getVal(1, 0, LEVEL - 1, pos + BASE);
    }
} tree;


const int N = (int) 1e5 + 100;
const int X = (int) 1e5 + 100;
int a[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < q; i++)
    {
        char ch[2];
        int val;
        scanf("%s%d", ch, &val);
        if (ch[0] == '<')
        {
            if (val < 0)
            {
                tree.fixSeg(-X, val - 1, -1);
                tree.fixSeg(-val + 1, X, 1);
            }
            else
            {
                tree.fixSeg(-X, -val, -1);
                tree.mulSeg(-val + 1, val - 1, -1);
                tree.fixSeg(val, X, 1);
            }
        }
        else if (ch[0] == '>')
        {
            if (val > 0)
            {
                tree.fixSeg(val + 1, X, -1);
                tree.fixSeg(-X, -val - 1, 1);
            }
            else
            {
                tree.fixSeg(-X, val, 1);
                tree.mulSeg(val + 1, -val - 1, -1);
                tree.fixSeg(-val, X, -1);
            }
        }
        else throw;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = tree.getVal(a[i]) * a[i];
        printf("%d ", a[i]);
    }
    printf("\n");

	return 0;
}