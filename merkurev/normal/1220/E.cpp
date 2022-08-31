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
long long w[N];
vector <int> g[N], ch[N];
bool used[N];
bool good[N];

void dfs(int v, int par)
{
    used[v] = true;
    for (int to : g[v])
    {
        if (to == par) continue;
        if (!used[to])
        {
            ch[v].push_back(to);
            dfs(to, v);
        }
        else
        {
            good[v] = good[to] = true;
        }
    }
}

bool dfsGood(int v)
{
    for (int to : ch[v])
       good[v] |= dfsGood(to);
    return good[v];
}

long long dfsMx(int v)
{
    long long ans = 0;
    for (int to : ch[v])
        ans = max(ans, dfsMx(to));
    if (!good[v])
        ans += w[v];
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &w[i]);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    scanf("%d", &s);
    s--;
    dfs(s, s);
    dfsGood(s);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (good[i])
            ans += w[i];
    long long add = dfsMx(s);
    ans += add;
    printf("%lld\n", ans);

    return 0;
}