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
#include <intrin.h>
using namespace std;

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MOD = 998244353;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b)
{
    return add(a, MOD - b);
}

int mul(int a, int b)
{
    return ((lint)a * b) % MOD;
}

const int MAXN = 200500;
int p2[MAXN];

const lint INF = 1 << 30;
const lint INF2 = 1ll << 60;
vector<int> graph[MAXN];
vector<int> igraph[MAXN];
pair<int, int> dist[MAXN * 2];

void solve()
{
    p2[0] = 1;
    For(i, MAXN - 1)
        p2[i + 1] = add(p2[i], p2[i]);
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        graph[a].push_back(b);
        igraph[b].push_back(a);
    }

    For(i, n * 2)
        dist[i] = { (int)1e9, (int)1e9 };
    dist[(n - 1) * 2] = dist[(n - 1) * 2 + 1] = make_pair(0, 0);
    queue<int> q1;
    queue<int> q2;
    q1.push((n - 1) * 2);
    q1.push((n - 1) * 2 + 1);
    while (!(q1.empty() && q2.empty()))
    {
        if (q1.empty())
            swap(q1, q2);
        int cur = q1.front();
        q1.pop();
        if (cur % 2 == 0)
        {
            pair<int, int> nxt_dist = { dist[cur].first, dist[cur].second + 1};
            for (auto e : igraph[cur / 2])
                if (dist[e * 2] > nxt_dist)
                {
                    dist[e * 2] = nxt_dist;
                    q1.push(e * 2);
                }
            nxt_dist = { dist[cur].first + 1, dist[cur].second + 1};
            for (auto e : graph[cur / 2])
                if (dist[e * 2 + 1] > nxt_dist)
                {
                    dist[e * 2 + 1] = nxt_dist;
                    q2.push(e * 2 + 1);
                }
        }
        else
        {
            pair<int, int> nxt_dist = { dist[cur].first, dist[cur].second + 1 };
            for (auto e : graph[cur / 2])
                if (dist[e * 2 + 1] > nxt_dist)
                {
                    dist[e * 2 + 1] = nxt_dist;
                    q1.push(e * 2 + 1);
                }
            nxt_dist = { dist[cur].first + 1, dist[cur].second + 1 };
            for (auto e : igraph[cur / 2])
                if (dist[e * 2] > nxt_dist)
                {
                    dist[e * 2] = nxt_dist;
                    q2.push(e * 2);
                }
        }
    }
    For(i, n * 2)
        if (dist[i].first == (int)1e9)
            dist[i] = { dist[i ^ 1].first + 1, dist[i ^ 1].second };

#ifdef LOCAL
    printf("%d %d\n", dist[0].first, dist[0].second);
#endif



    priority_queue<pair<lint, lint>> pq;
    pq.emplace(0ll, 0ll);
    lint res = 1ll << 60;
    static lint dist2[20][MAXN];
    static bool been[20][MAXN];
    memset(dist2, 63, sizeof(dist2));
    dist2[0][0] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        lint d = -cur.first;
        int v = cur.second / INF;
        int t = cur.second % INF;
        if (been[t][v])
            continue;
        been[t][v] = true;
        if (v == n - 1)
            res = min(res, d);
        if (t > 18)
            continue;
        if (t % 2 == 0)
        {
            for (auto e : graph[v])
            {
                lint nxt = e * INF + t;
                if (dist2[t][e] > d + 1)
                {
                    dist2[t][e] = d + 1;
                    pq.emplace(-(d + 1), nxt);
                }
            }
            for (auto e : igraph[v])
            {
                lint nxt = e * INF + t + 1;
                if (dist2[t + 1][e] > d + (1ll << t) + 1)
                {
                    dist2[t + 1][e] = d + (1ll << t) + 1;
                    pq.emplace(-(d + (1ll << t) + 1), nxt);
                }
            }
        }
        else
        {
            for (auto e : igraph[v])
            {
                lint nxt = e * INF + t;
                if (dist2[t][e] > d + 1)
                {
                    dist2[t][e] = d + 1;
                    pq.emplace(-(d + 1), nxt);
                }
            }
            for (auto e : graph[v])
            {
                lint nxt = e * INF + t + 1;
                if (dist2[t + 1][e] > d + (1ll << t) + 1)
                {
                    dist2[t + 1][e] = d + (1ll << t) + 1;
                    pq.emplace(-(d + (1ll << t) + 1), nxt);
                }
            }
        }
    }
    if (res < (1ll << 30))
        printf("%lld\n", res);
    else
        printf("%d\n", add(dist[0].second, sub(p2[dist[0].first], 1)));
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