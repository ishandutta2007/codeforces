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

vector<int> graph[(int)1e5 + 10];

int dfs1(int v, int b, int from = -1, int dist = 0)
{
    if (v == b)
        return dist;
    for (auto e : graph[v])
        if (e != from)
        {
            int kek = dfs1(e, b, v, dist + 1);
            if (kek != -1)
                return kek;
        }
    return -1;
}

pair<int, int> dfs(int v, int from = -1, int dist = 0)
{
    pair<int, int> res(dist, v);
    for (auto e : graph[v])
        if (e != from)
            res = max(res, dfs(e, v, dist + 1));
    return res;
}

void solve()
{
    int n, a, b, da, db;
    scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
    For(i, n)
        graph[i].clear();
    For(i, n - 1)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int v = 0;
    int u = dfs(v).second;
    if (dfs(u).first <= da * 2 || dfs1(a - 1, b - 1) <= da)
        printf("Alice\n");
    else if (db > da * 2)
        printf("Bob\n");
    else
        printf("Alice\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}