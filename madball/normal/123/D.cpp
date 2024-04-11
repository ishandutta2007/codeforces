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

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")

typedef long long lint;
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

const int MAXN = 100500;
const int MAX_LVL = 18;

int cls[MAX_LVL][MAXN];
char s[MAXN];
int suf[MAXN];
int isuf[MAXN];
int lcp[MAXN];

void suff_arr(int n)
{
    static pair<pair<int, int>, int> order[MAXN];
    For(lvl, MAX_LVL)
    {
        For(i, n)
        {
            if (lvl == 0)
                order[i] = { make_pair(s[i], -1), i };
            else
                order[i] = { make_pair(cls[lvl - 1][i], cls[lvl - 1][(i + (1 << (lvl - 1))) % n]), i };
        }
        stable_sort(order, order + n);
        auto prev = order[0].first;
        int q = 0;
        For(i, n)
        {
            q += order[i].first != prev;
            cls[lvl][order[i].second] = q;
            prev = order[i].first;
        }
    }
    For(i, n)
        suf[cls[MAX_LVL - 1][i]] = i;
}

void kasai(int n)
{
    For(i, n)
        isuf[suf[i]] = i;
    int k = 0;
    For(i, n)
    {
        if (k > 0)
            --k;
        if (isuf[i] == n - 1)
        {
            lcp[n - 1] = 0;
            k = 0;
        }
        else
        {
            int j = suf[isuf[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k])
                ++k;
            lcp[isuf[i]] = k;
        }
    }
}

void solve()
{
    scanf("%s", s);
    int n = strlen(s);
    s[n] = '$';
    ++n;
    suff_arr(n);
    kasai(n);
    vector<pair<int, int>> stck;
    lint res = 0;
    For(i, n)
    {
        res += n - suf[i] - 1;
        if ((stck.empty() && lcp[i]) || (!stck.empty() && lcp[i] > stck.back().first))
            stck.emplace_back(lcp[i], i);
        while (!stck.empty() && stck.back().first > lcp[i])
        {
            res += (lint)(i - stck.back().second) * (i - stck.back().second + 1) / 2;
            --stck.back().first;
            if (stck.back().first == 0 || (sz(stck) >= 2 && stck.back().first == stck[sz(stck) - 2].first))
                stck.pop_back();
        }
    }
    cout << res << '\n';
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