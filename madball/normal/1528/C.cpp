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
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = 300003;
vector<int> graph1[MAXN];
vector<int> graph2[MAXN];
int par1[MAXN];
int par2[MAXN];
int sz2[MAXN];
int tin[MAXN];
int tout[MAXN];
int nxt[MAXN];
set<pair<int, int>> st[MAXN];
bool marked[MAXN];

inline int f(int x)
{
    return x & (-x);
}

struct Fenvick
{
    int ar[MAXN * 2];
    Fenvick() {}
    void add(int i, int val)
    {
        for (; i < MAXN * 2; i += f(i + 1))
            ar[i] += val;
    }
    int get(int i)
    {
        int res = 0;
        for (; i >= 0; i -= f(i + 1))
            res += ar[i];
        return res;
    }
} fenvick;

int dfs1(int v)
{
    sz2[v] = 1;
    for (auto& e : graph2[v])
    {
    sz2[v] += dfs1(e);
    if (sz2[e] > sz2[graph2[v][0]])
        swap(e, graph2[v][0]);
    }
    return sz2[v];
}

int t = 0;
void dfs2(int v)
{
    tin[v] = t++;
    for (auto e : graph2[v])
    {
        nxt[e] = (e == graph2[v][0] ? nxt[v] : e);
        dfs2(e);
    }
    tout[v] = t++;
}

int ans = 0;
int get_par(int v)
{
    int at_least_this_much = sz2[v] + 1;
    int cur = v;
    while (true)
    {
        cur = nxt[cur];
        if (!st[cur].empty() && st[cur].rbegin()->first >= at_least_this_much)
        {
            auto it = st[cur].lower_bound(make_pair(at_least_this_much, 0));
            if (it != st[cur].end())
                return it->second;
        }
        if (cur == 0)
            return -1;
        at_least_this_much = sz2[par2[cur]];
        cur = par2[cur];
    }
}

void mark(int v)
{
    if (fenvick.get(tout[v]) != fenvick.get(tin[v]))
        return;
    int u = get_par(v);
    if (u != -1 && marked[u])
    {
        marked[u] = false;
        --ans;
    }
    marked[v] = true;
    ++ans;
}

void add(int v)
{
    st[nxt[v]].emplace(sz2[v], v);
    fenvick.add(tin[v], 1);
    mark(v);
}

void remov(int v)
{
    st[nxt[v]].erase(make_pair(sz2[v], v));
    fenvick.add(tin[v], -1);
    if (fenvick.get(tout[v]) != fenvick.get(tin[v]))
        return;
    if (marked[v])
    {
        marked[v] = false;
        --ans;
    }
    int u = get_par(v);
    if (u != -1)
        mark(u);
}

int dfs3(int v)
{
    add(v);
    int res = ans;
    for (auto e : graph1[v])
    {
        res = max(res, dfs3(e));
    }
    remov(v);
    return res;
}

#ifdef LOCAL
#define STRESS
#define STRESS_GEN
mt19937 rng(42);

bool s_in[MAXN];
bool s_marked[MAXN];

void s_dfs1(int v, vector<int>& stck)
{
    if (s_in[v])
    {
        if (!stck.empty())
            s_marked[stck.back()] = false;
        s_marked[v] = true;
        stck.push_back(v);
    }
    for (auto e : graph2[v])
        s_dfs1(e, stck);
    if (s_in[v])
        stck.pop_back();
}

int s_dfs2(int v, int n)
{
    s_in[v] = true;
    vector<int> stck;
    memset(s_marked, 0, n);
    s_dfs1(0, stck);
    int res = 0;
    For(i, n)
        res += s_marked[i];
    for (auto e : graph1[v])
        res = max(res, s_dfs2(e, n));
    s_in[v] = false;
    return res;
}
#endif

void solve()
{
    t = 0;
    ans = 0;
    int n;
#ifdef STRESS_GEN
    n = 20;
#else
    scanf("%d", &n);
#endif
    For(i, n)
    {
        graph1[i].clear();
        graph2[i].clear();
    }
    for (int i = 1; i < n; ++i)
    {
        int j;
#ifdef STRESS_GEN
        j = rng() % i;
#else
        scanf("%d", &j);
        --j;
#endif
        graph1[j].push_back(i);
        par1[i] = j;
    }
    for (int i = 1; i < n; ++i)
    {
        int j;
#ifdef STRESS_GEN
        j = rng() % i;
#else
        scanf("%d", &j);
        --j;
#endif
        graph2[j].push_back(i);
        par2[i] = j;
    }
    dfs1(0);
    dfs2(0);
    int res = dfs3(0);
#ifdef STRESS
    int s_res = s_dfs2(0, n);
#ifdef STRESS_GEN
    if (s_res == res)
        return;
    printf("%d %d\n", s_res, res);
    printf("%d\n", n);
    for (int i = 1; i < n; ++i)
        printf("%d%c", par1[i] + 1, (i + 1 == n ? '\n' : ' '));
    for (int i = 1; i < n; ++i)
        printf("%d%c", par2[i] + 1, (i + 1 == n ? '\n' : ' '));
    exit(0);
#else
    printf("%d ", s_res);
#endif
#endif
#ifndef STRESS_GEN
    printf("%d\n", res);
#endif
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}