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

const int MAXN = 400;
const int MOD = 998244353;
int dist[MAXN][MAXN];
int res[MAXN][MAXN];
vector<int> graph[MAXN];

void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dist, 63, sizeof(dist));
    For(i, n)
    {
        dist[i][i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto e : graph[cur])
            {
                if (dist[i][e] > 10000)
                {
                    dist[i][e] = dist[i][cur] + 1;
                    q.push(e);
                }
            }
        }
    }
    For(i, n)
    {
        lint cur = 1;
        For(j, n)
            if (i != j)
            {
                int mul = 0;
                for (auto e : graph[j])
                    if (dist[i][j] > dist[i][e])
                        ++mul;
                cur *= mul;
                cur %= MOD;
            }
        res[i][i] = cur;
    }
    For(i, n) For(j, i)
    {
#ifdef LOCAL
        if (i == 6 && j == 5)
            i = 6;
#endif
        lint cur = 1;
        int dij = dist[i][j];
        int on_path = -2 - dij;
        for (int k = 0; k < n && cur; ++k)
        {
            int dik = dist[i][k];
            int djk = dist[j][k];
            int mul = 0;
            if (dik + djk == dij)
            {
                mul += (bool)(++on_path);
            }
            else
            {
                for (auto e : graph[k])
                    mul += dist[i][e] < dik && dist[j][e] < djk;
            }
            cur *= mul;
            cur %= MOD;
        }
        res[i][j] = res[j][i] = cur;
    }
    For(i, n)
    {
        For(j, n)
            printf("%d ", res[i][j]);
        printf("\n");
    }
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