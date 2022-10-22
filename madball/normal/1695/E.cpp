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

const int MAXN = (int)6e5 + 5;
const lint INF = (lint)1e18 + 5;

struct Edge
{
    int to;
    bool enabled;
    Edge() {}
    explicit Edge(int to): to(to), enabled(false) {}
} edges[MAXN * 2];
int edgel = 0;

vector<int> graph[MAXN];
bool been[MAXN];

void doit(int v, vector<int>& ans)
{
    been[v] = true;
    while (!graph[v].empty())
    {
        int i = graph[v].back();
        graph[v].pop_back();
        if (!edges[i].enabled)
        {
            edges[i].enabled = true;
            edges[i ^ 1].enabled = true;
            doit(edges[i].to, ans);
            ans.push_back(i);
        }
    }
}

vector<int> ans[2];
string ans2[2];
string ans3[2];

void solve()
{
    int n;
    scanf("%d", &n);
    For(i, n)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        graph[a].push_back(edgel);
        edges[edgel++] = Edge(b);
        graph[b].push_back(edgel);
        edges[edgel++] = Edge(a);
        graph[a].push_back(edgel);
        edges[edgel++] = Edge(b);
        graph[b].push_back(edgel);
        edges[edgel++] = Edge(a);
    }
    static vector<vector<int>> loops;
    For(i, n * 2)
        if (!been[i] && !graph[i].empty())
        {
            loops.emplace_back();
            doit(i, loops.back());
            if (sz(loops.back()) % 2 == 1)
                throw;
            if (sz(loops.back()) == 2)
            {
                printf("-1\n");
                return;
            }
        }
    for (const auto& e : loops)
    {
        int s = sz(e) / 2;
        For(i, s)
        {
            ans[0].push_back(edges[e[i]].to + 1);
            ans[1].push_back(edges[e[s + i]].to + 1);
        }
        reverse(ans[1].end() - s, ans[1].end());
        ans3[0].push_back('U');
        ans3[1].push_back('D');
        For(i, s / 2)
        {
            ans2[0].push_back('L');
            ans2[0].push_back('R');
            ans2[1].push_back('L');
            ans2[1].push_back('R');
            if (i + 1 != s / 2 || s % 2 == 1)
            {
                ans3[0].push_back('L');
                ans3[0].push_back('R');
                ans3[1].push_back('L');
                ans3[1].push_back('R');
            }
        }
        if (s % 2 == 1)
        {
            ans2[0].push_back('U');
            ans2[1].push_back('D');
        }
        else
        {
            ans3[0].push_back('U');
            ans3[1].push_back('D');
        }
    }
    printf("%d %d\n", 2, n);
    For(i, n)
        printf("%d ", ans[0][i]);
    printf("\n");
    For(i, n)
        printf("%d ", ans[1][i]);
    printf("\n");
    printf("%s\n", ans2[0].c_str());
    printf("%s\n", ans2[1].c_str());
    printf("%s\n", ans3[0].c_str());
    printf("%s\n", ans3[1].c_str());
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