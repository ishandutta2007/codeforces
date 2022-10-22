#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <random>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

#ifdef LOCAL
const int MAXN = 8;
#else
const int MAXN = 262144;
#endif

struct Dsu
{
    int par[MAXN];
    int rank[MAXN];
    int lef[MAXN];
    int rig[MAXN];
    bool cured[MAXN];
    Dsu()
    {
        For(i, MAXN)
        {
            par[i] = i;
            rank[i] = 0;
            lef[i] = i;
            rig[i] = i;
            cured[i] = false;
        }
    }
    int get_par(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get_par(par[x]);
    }
    bool merge(int a, int b)
    {
        a = get_par(a);
        b = get_par(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        if (rank[a] == rank[b])
            ++rank[a];
        par[b] = a;
        lef[a] = min(lef[a], lef[b]);
        rig[a] = max(rig[a], rig[b]);
        cured[a] = true;
        return true;
    }
} dsu;

struct Fenvick
{
    vector<int> ar;
    Fenvick() {}
    void add(int i, int val)
    {
        for (; i < sz(ar); i += (i + 1) & -(i + 1))
            ar[i] += val;
    }
    int get(int i)
    {
        int res = 0;
        for (; i >= 0; i -= (i + 1) & -(i + 1))
            res += ar[i];
        return res;
    }
    int get(int l, int r)
    {
        return get(min(r, sz(ar)) - 1) - get(l - 1);
    }
};

struct Tree
{
    vector<int> compress[MAXN * 2];
    Fenvick fenvick[MAXN * 2];
    void pre_add(int i, int j)
    {
        for (i += MAXN; i > 0; i >>= 1)
            compress[i].push_back(j);
    }
    void init()
    {
        for (int i = 1; i < MAXN * 2; ++i)
        {
            sort(all(compress[i]));
            compress[i].resize(unique(all(compress[i])) - compress[i].begin());
            fenvick[i].ar.resize(compress[i].size(), 0);
        }
    }
    void add(int i, int j)
    {
        for (i += MAXN; i > 0; i >>= 1)
            fenvick[i].add(lower_bound(all(compress[i]), j) - compress[i].begin(), 1);
    }
    bool get(int l, int r, int l2, int r2)
    {
        for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                if (fenvick[l].get(lower_bound(all(compress[l]), l2) - compress[l].begin(), lower_bound(all(compress[l]), r2) - compress[l].begin()))
                    return true;
                ++l;
            }
            if (r & 1)
            {
                --r;
                if (fenvick[r].get(lower_bound(all(compress[r]), l2) - compress[r].begin(), lower_bound(all(compress[r]), r2) - compress[r].begin()))
                    return true;
            }
        }
        return false;
    }
} tree;

char ans[MAXN];

int read()
{
    char c;
    while (true)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
            break;
    }
    int res = c - '0';
    while (true)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
            return res;
        res = res * 10 + c - '0';
    }
}

struct Query
{
    int l, r;
    Query() {}
    Query(int l, int r) : l(l), r(r) {}
} queries[MAXN];

void solve()
{
    int n = read();
    int q = read();
    int ptr = 0;
    For(i, q)
    {
        int typ = read();
        if (typ == 0)
        {
            int l = read() - 1;
            int r = read();
            typ = read();
            queries[i] = Query(l, r * 2 + typ);
            if (typ)
            {
                tree.pre_add(l, r);
            }
        }
        else
            queries[i] = Query(read() - 1, -1);
    }
    tree.init();
    For(i, q)
    {
        if (queries[i].r >= 0)
        {
            int l = queries[i].l;
            int r = queries[i].r / 2;
            int typ = queries[i].r % 2;
            if (typ == 0)
            {
                int pos = l;
                pos = dsu.get_par(pos);
                dsu.cured[pos] = true;
                pos = dsu.rig[pos];
                while (pos + 1 < r)
                {
                    dsu.merge(pos, pos + 1);
                    pos = dsu.rig[dsu.get_par(pos)];
                }
            }
            else
                tree.add(l, r);
        }
        else
        {
            int x = queries[i].l;
            int pos = dsu.get_par(x);
            if (dsu.cured[pos])
                ans[ptr] = 1;
            else
            {
                int l = dsu.lef[pos], r = dsu.rig[pos];
                bool start = true;
                while (l != 0)
                {
                    int tmp = dsu.get_par(l - 1);
                    if (!dsu.cured[tmp])
                        break;
                    l = dsu.lef[tmp];
                    if (!start)
                        dsu.merge(dsu.rig[tmp], dsu.rig[tmp] + 1);
                    start = false;
                }
                start = true;
                while (r + 1 != n)
                {
                    int tmp = dsu.get_par(r + 1);
                    if (!dsu.cured[tmp])
                        break;
                    r = dsu.rig[tmp];
                    if (!start)
                        dsu.merge(dsu.lef[tmp], dsu.lef[tmp] - 1);
                    start = false;
                }
                if (tree.get(l, x + 1, x + 1, r + 2))
                    ans[ptr] = 2;
                else
                    ans[ptr] = 3;
            }
            ++ptr;
        }
    }
    For(i, ptr)
        if (ans[i] == 1)
            printf("NO\n");
        else if (ans[i] == 2)
            printf("YES\n");
        else if (ans[i] == 3)
            printf("N/A\n");
        else
            throw;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}