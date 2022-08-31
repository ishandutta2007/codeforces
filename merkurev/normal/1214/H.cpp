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


const int N = (int) 2e5 + 100;
vector <int> g[N];
int d[N];
int par[N];
int col[N];
int maxd[N];

void dfs(int v, int p, int dist)
{
    d[v] = dist;
    maxd[v] = d[v];
    par[v] = p;
    for (int to : g[v])
    {
        if (to == p) continue;
        dfs(to, v, dist + 1);
        maxd[v] = max(maxd[v], maxd[to]);
    }
}

void dfs2(int v, int x)
{
    col[v] = x;
    for (int to : g[v])
        if (col[to] == 0)
            dfs2(to, x ^ 3);
}

int n, k;
void dfsX(int v, int p, int ccol, int delta)
{
    col[v] = ccol;
    vector <pair <int, int>> ch;
    for (auto to : g[v])
    {
        if (to == p) continue;
        ch.emplace_back(maxd[to] - d[v], to);
    }
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
    if (ch.size() >= 2 && ch[0].first + ch[1].first + 1 >= k)
    {
        //eprintf("?? v = %d   %d %d    %d + %d\n", v, ch[0].second, ch[1].second, ch[0].first, ch[1].first);
        printf("No\n");
        exit(0);
    }
    for (auto top : ch)
        dfsX(top.second, v, ccol + delta, delta);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if (k == 2)
    {
        printf("Yes\n");
        dfs2(0, 1);
        for (int i = 0; i < n; i++)
            printf("%d ", col[i]);
        printf("\n");
        return 0;
    }

    dfs(0, 0, 0);
    int v1 = 0;
    for (int i = 0; i < n; i++)
        if (d[i] > d[v1])
            v1 = i;
    dfs(v1, v1, 0);
    int v2 = 0;
    for (int i = 0; i < n; i++)
        if (d[i] > d[v2])
            v2 = i;
    int x = d[v2] / 2;
    for (int i = 0; i < x; i++)
        v2 = par[v2];
    dfs(v2, v2, 0);
    eprintf("v2 = %d\n", v2);

    vector <pair <int, int>> ch;
    for (int to : g[v2])
        ch.emplace_back(maxd[to], to);
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
    if (ch.size() >= 3 && ch[2].first + ch[1].first + 1 >= k)
    {
        printf("No\n");
        return 0;
    }
    if (ch.size() == 1 || (ch.size() == 2 && ch[0].first + ch[1].first + 1 < k))
    {
        printf("Yes\n");
        for (int i = 0; i < n; i++)
            printf("%d ", 1);
        printf("\n");
        return 0;
    }
    dfsX(ch[0].second, v2, -1, -1);
    for (int i = 1; i < (int) ch.size(); i++)
        dfsX(ch[i].second, v2, 1, 1);

    printf("Yes\n");
    for (int i = 0; i < n; i++)
        printf("%d ", ((col[i] % k) + k) % k + 1);
    printf("\n");


    return 0;
}