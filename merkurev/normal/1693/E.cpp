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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct State
{
    int a[2][2];

    State() : a() {
        a[0][1] = a[1][0] = 1;
    }

    State(pair <int, int> p) : a()
    {
        a[0][1] = a[1][0] = 1;
        a[0][0] = (p.first > 0);
        a[1][1] = (p.second > 0);
    }

    State operator + (const State &A) const
    {
        State ans = State();
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans.a[i][j] = SZ;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int h = 0; h < 2; h++)
                    ans.a[i][j] = min(ans.a[i][j],
                            a[i][h] + A.a[h][j]);
        return ans;
    }
};

struct Tree
{
    State vadd[SZ];

    Tree() : vadd() {}

    void set(int pos, pair <int, int> val)
    {
        eprintf("set %d: %d %d\n", pos, val.first, val.second);
        pos += LEVEL;
        vadd[pos] = State(val);
        while (pos > 1)
        {
            pos /= 2;
            vadd[pos] = vadd[2 * pos + 1] + vadd[2 * pos];
        }
    }

    State get(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return State();
        if (l <= tl && tr <= r)
            return vadd[v];
        int tm = (tl + tr) / 2;
        auto ans = get(2 * v + 1, tm + 1, tr, l, r) + 
                get(2 * v, tl, tm, l, r);
        return ans;
    }

    int get(int pos)
    {
        State S = get(1, 0, LEVEL - 1, 0, pos - 1);
        int ans = SZ;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans = min(ans, S.a[i][j]);
        return ans;
    }
} tree;

int cntl[SZ], cntr[SZ];
int a[SZ];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);


    for (int i = 0; i <= n + 1; i++)
    {
        cntr[a[i]]++;
    }
    for (int i = 0; i <= n; i++)
        tree.set(i, {cntl[i] > 0, cntr[i] > 0});
    eprintf("---------\n");

    long long ans = 0;
    for (int i = 0; i <= n + 1; i++)
    {
        cntr[a[i]]--;
        tree.set(a[i], {cntl[a[i]] > 0, cntr[a[i]] > 0});

        if (1 <= i && i <= n)
        {
            auto cur = tree.get(a[i]);
            ans += cur;
        }

        cntl[a[i]]++;
        tree.set(a[i], {cntl[a[i]] > 0, cntr[a[i]] > 0});
    }
    printf("%lld\n", ans);

	return 0;
}