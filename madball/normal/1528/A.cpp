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

vector<int> graph[100001];
pair<int, int> ar[100001];

pair<lint, lint> dfs(int v, int from = -1)
{
    pair<lint, lint> p(0, 0);
    for (auto e : graph[v])
        if (e != from)
        {
            auto q = dfs(e, v);
            p.first += max(q.first + abs(ar[v].first - ar[e].first), q.second + abs(ar[v].first - ar[e].second));
            p.second += max(q.first + abs(ar[v].second - ar[e].first), q.second + abs(ar[v].second - ar[e].second));
        }
    return p;
}

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
    {
        scanf("%d %d", &ar[i].first, &ar[i].second);
        graph[i].clear();
    }
    For(i, n - 1)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    auto ans = dfs(0);
    printf("%lld\n", max(ans.first, ans.second));
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