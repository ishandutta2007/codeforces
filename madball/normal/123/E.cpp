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


const int MAXN = 100500;
int inpx[MAXN];
int inpy[MAXN];

double prob1[MAXN];
double prob2[MAXN];
double sum1[MAXN];
double sum2[MAXN];
int siz[MAXN];
int par[MAXN];
vector<int> graph[MAXN];

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
        res = res * 10 + (c - '0');
    }
}

void dfs(int v, int from = -1)
{
    siz[v] = 1;
    sum1[v] = prob1[v];
    sum2[v] = prob2[v];
    for (auto e : graph[v])
        if (e != from)
        {
            dfs(e, v);
            par[e] = v;
            siz[v] += siz[e];
            sum1[v] += sum1[e];
            sum2[v] += sum2[e];
        }
}

int siz_edge(int u, int v, int n)
{
    if (par[v] == u)
        return siz[v];
    else
        return n - siz[u];
}

double prob1_edge(int u, int v)
{
    if (par[v] == u)
        return sum1[v];
    else
        return 1 - sum1[u];
}

double prob2_edge(int u, int v)
{
    if (par[v] == u)
        return sum2[v];
    else
        return 1 - sum2[u];
}

void solve()
{
    int n = read();
    For(i, n)
        par[i] = -1;
    For(i, n - 1)
    {
        int a = read() - 1;
        int b = read() - 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int sumx = 0, sumy = 0;
    For(i, n)
    {
        inpx[i] = read();
        sumx += inpx[i];
        inpy[i] = read();
        sumy += inpy[i];
    }
    For(i, n)
    {
        prob1[i] = (double)inpx[i] / sumx;
        prob2[i] = (double)inpy[i] / sumy;
    }
    dfs(0);

    double resa = 0, resb = 0, resc = 0;
    For(u, n) for (auto v : graph[u])
    {
        resa += prob1_edge(v, u) * prob2_edge(u, v);
        resb += prob1[u] * (1 - prob2[u] - prob2_edge(u, v)) * siz_edge(u, v, n);
    }
    For(u, n)
    {
        double cur1 = 0, cur2 = 0, kek = 0;
        for (auto v : graph[u])
        {
            cur1 += prob1_edge(u, v);
            cur2 += prob2_edge(u, v);
            kek += prob1_edge(u, v) * prob2_edge(u, v);
        }
        for (auto v : graph[u])
        {
            double tmp = (cur1 - prob1_edge(u, v)) * (cur2 - prob2_edge(u, v)) - kek + prob1_edge(u, v) * prob2_edge(u, v);
            resc += tmp * siz_edge(u, v, n);
        }
    }
    printf("%.12lf\n", resa + resb + resc);
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