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

const int MAXN = 200500;
int ar[MAXN];
int lef[MAXN];
int righ[MAXN];
bool dwarf[MAXN];
bool uncovered[MAXN];

void solve()
{
    int n;
    scanf("%d", &n);
    memset(lef, 63, sizeof(lef));
    For(i, n)
    {
        scanf("%d", &ar[i]);
        --ar[i];
        lef[ar[i]] = min(lef[ar[i]], i);
        righ[ar[i]] = i;
    }
    vector<pair<int, int>> segments0;
    fill(dwarf, dwarf + n, true);
    For(i, n)
        if (lef[i] < righ[i])
            segments0.emplace_back(lef[i], righ[i] + 1);
    sort(all(segments0));
    vector<pair<int, int>> segments;
    int mx = 0;
    for (auto e : segments0)
        if (e.second > mx)
        {
            segments.push_back(e);
            mx = e.second;
        }
    if (!segments.empty())
    {
        For(i, segments.front().first)
            uncovered[i] = true;
        For(i, sz(segments) - 1)
            for (int j = segments[i].second; j < segments[i + 1].first; ++j)
                uncovered[j] = true;
        for (int i = segments.back().second; i < n; ++i)
            uncovered[i] = true;
    }
    else For(i, n)
        uncovered[i] = true;
    set<pair<int, int>> uhhhh(all(segments));
    for (auto it = uhhhh.begin(); it != uhhhh.end(); ++it)
    {
        pair<int, int> e = *it;
        while (it != uhhhh.begin() && prev(it) != uhhhh.begin() && e.first < prev(prev(it))->second)
        {
            uhhhh.erase(prev(it));
            it = uhhhh.lower_bound(e);
        }
    }
    /*for (auto it = uhhhh.begin(); it != uhhhh.end(); )
    {
        pair<int, int> e = *it;
        if (it != uhhhh.begin() && next(it) != uhhhh.end() && prev(it)->second > e.first && next(it)->first < e.second)
        {
            uhhhh.erase(it);
            it = uhhhh.lower_bound(e);
        }
        else
            ++it;
    }*/
    pair<int, int> prv{ -1, -1 };
    int res = 0;
    for (auto e : uhhhh)
    {
        dwarf[e.first] = dwarf[e.second - 1] = false;
        if (e.first < prv.second)
            ++res;
        prv = e;
    }
    For(i, n)
        res += dwarf[i] && !uncovered[i];
    printf("%d\n", res);



#ifdef LOCAL
    static bool dp[1 << 20];
    dp[0] = true;
    For(mask, (1 << n) - 1)
        if (dp[mask])
            For(k, n)
                if (!(mask & (1 << k)))
                    For(i, k)
                        if (!(mask & (1 << i)))
                            if (ar[i] == ar[k])
                                for (int j = i + 1; j < k; ++j)
                                    dp[mask | (1 << j)] = true;
    int res2 = 0;
    For(i, 1 << n)
        if (dp[i])
            res2 = max(res2, (int)__popcnt(i));
    printf("%d\n", res2);
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
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}