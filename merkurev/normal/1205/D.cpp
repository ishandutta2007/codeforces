#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int N = 1005;
vector <int> g[N];

int val[N];
int sz[N];

void dfsQu(int v, int par, vector <pair <int, int>> &qu)
{
    qu.emplace_back(v, par);
    for (int to : g[v])
    {
        if (to == par) continue;
        dfsQu(to, v, qu);
    }
}

void dfsSz(int v, int par)
{
    sz[v] = 1;
    for (int to : g[v])
    {
        if (to == par)
            continue;
        dfsSz(to, v);
        sz[v] += sz[to];
    }
}

int getRoot(int v, int par, int n)
{
    for (int to : g[v])
    {
        if (to == par)
            continue;
        if (sz[to] * 2 < n) continue;
        return getRoot(to, v, n);
    }
    return v;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfsSz(0, 0);

    int root = getRoot(0, 0, n);

    dfsSz(root, root);
    vector <pair <int, int>> ch;
    for (int v : g[root])
        ch.emplace_back(sz[v], v);
    
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());

    int szA = 0;
    vector <int> a;
    int szB = 0;
    vector <int> b;
    for (auto p : ch)
        if (szA < szB)
        {
            szA += p.first;
            a.push_back(p.second);
        }
        else
        {
            szB += p.first;
            b.push_back(p.second);
        }
    vector <pair <int, int>> quA, quB;
    for (int x : a)
        dfsQu(x, root, quA);
    for (int x : b)
        dfsQu(x, root, quB);

    int BL = (int) quA.size() + 1;
    for (int i = 0; i < (int) quA.size(); i++)
    {
        auto p = quA[i];
        int x = i + 1;
        val[p.first] = x;
        printf("%d %d %d\n", p.first + 1, p.second + 1, val[p.first] - val[p.second]);
    }
    for (int i = 0; i < (int) quB.size(); i++)
    {
        auto p = quB[i];
        int x = i + 1;
        val[p.first] = x;
        printf("%d %d %d\n", p.first + 1, p.second + 1, (val[p.first] - val[p.second]) * BL);
    }


    return 0;
}