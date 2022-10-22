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

const int MAXN = (int)1e5 + 10;

struct City
{
    int beauty, cost, id;
    City() {}
    bool operator < (const City& other) const
    {
        if (beauty != other.beauty)
            return beauty < other.beauty;
        return id < other.id;
    }
} ar[MAXN];
lint dp[MAXN];

#ifdef LOCAL
#define STRESS
#define STRESS_GEN
mt19937 rng(42);
#endif

void solve()
{
    int n;
#ifdef STRESS_GEN
    n = 2;
#else
    scanf("%d", &n);
#endif
    For(i, n)
    {
#ifdef STRESS_GEN
        ar[i].beauty = rng() % 10;
        ar[i].cost = rng() % 10;
#else
        scanf("%d %d", &ar[i].beauty, &ar[i].cost);
#endif
        ar[i].id = i;
    }
    set<pair<lint, int>> events;
    set<pair<lint, int>> unevented;
    lint evented = (lint)1e18;
#ifdef STRESS
    sort(ar + 1, ar + n);
    lint s_res = (lint)1e18;
    do
    {
        lint cur = max(ar[n - 1].cost, ar[0].beauty - ar[n - 1].beauty);
        For(i, n - 1)
            cur += max(ar[i].cost, ar[i + 1].beauty - ar[i].beauty);
        s_res = min(s_res, cur);
    } while (next_permutation(ar + 1, ar + n));
    printf("%lld ", s_res);
#endif
    sort(ar, ar + n);
    dp[0] = 0;
    events.emplace(ar[0].beauty + ar[0].cost, 0);
    unevented.emplace(dp[0], 0);
    for (int j = 1; j < n; ++j)
    {
        while (!events.empty() && events.begin()->first <= ar[j].beauty)
        {
            int i = events.begin()->second;
            events.erase(events.begin());
            unevented.erase(make_pair(dp[i], i));
            evented = min(evented, dp[i] - ar[i].beauty - ar[i].cost);
        }
        /*dp[j] = (lint)1e18;
        For(i, j)
            dp[j] = min(dp[j], dp[i] + max(0, ar[j].beauty - ar[i].beauty - ar[i].cost));*/
        dp[j] = min(evented + ar[j].beauty, (lint)1e18);
        if (!unevented.empty())
            dp[j] = min(dp[j], unevented.begin()->first);
        events.emplace(ar[j].beauty + ar[j].cost, j);
        unevented.emplace(dp[j], j);
    }
    lint res = dp[n - 1];
    For(i, n)
        res += ar[i].cost;
    printf("%lld\n", res);
#ifdef STRESS_GEN
    if (res != s_res)
    {
        printf("FUCK\n%d\n", n);
        For(i, n)
            printf("%d %d\n", ar[i].beauty, ar[i].cost);
        exit(0);
    }
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
#ifdef STRESS_GEN
    For(i, 100000)
#endif
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}