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
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx,tune=native")

typedef long long lint;
#ifdef LOCAL
typedef long long verylint;
#else
typedef __int128 verylint;
#endif
#define For(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())

vector<lint> happy;
lint ml = (lint)2e18;
pair<lint, lint> ar[100500];
pair<lint, lint> br[524288];
verylint kek[524288];
int coefl[524288];
int coefr[524288];

verylint check(int n, int m)
{
    int n2 = 0;
    For(i, sz(happy) - m + 1)
        if (happy[i + m - 1] - happy[i] <= ml)
            br[n2++] = make_pair(happy[i], happy[i + m - 1]);
    if (n2 == 0)
        return (lint)2e18;
    fill(kek, kek + n2, 0);
    fill(coefl, coefl + n2, 0);
    fill(coefr, coefr + n2, 0);
    For(i, n)
    {
        int l = -1;
        int r = n2;
        while (l + 1 < r)
        {
            int mm = (l + r) / 2;
            if (br[mm].second < ar[i].second)
                l = mm;
            else
                r = mm;
        }
        kek[r] -= ar[i].second;
        kek[n2] += ar[i].second;
        ++coefr[r];
        --coefr[n2];

        l = -1;
        r = n2;
        while (l + 1 < r)
        {
            int mm = (l + r) / 2;
            if (br[mm].first > ar[i].first)
                r = mm;
            else
                l = mm;
        }
        kek[0] += ar[i].first;
        kek[r] -= ar[i].first;
        --coefl[0];
        ++coefl[r];
    }
    For(i, n2 - 1)
    {
        kek[i + 1] += kek[i];
        coefl[i + 1] += coefl[i];
        coefr[i + 1] += coefr[i];
    }
    verylint res = (lint)2e18;
    For(i, n2)
        res = min(res, kek[i] + (verylint)coefl[i] * br[i].first + (verylint)coefr[i] * br[i].second);
    return res;
}

void solve()
{
    for (int len = 1; len <= 18; ++len)
    {
        For(i, 1 << len)
        {
            lint cur = 0;
            For(j, len)
                cur = cur * 10 + (4 + ((i >> (len - 1 - j)) % 2) * 3);
            happy.push_back(cur);
        }
    }
    int n;
    lint k;
    scanf("%d %lld", &n, &k);
    For(i, n)
    {
        scanf("%lld %lld", &ar[i].first, &ar[i].second);
        ml = min(ml, ar[i].second - ar[i].first);
    }
    int l = 0, r = sz(happy) + 1;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (check(n, m) <= k)
            l = m;
        else
            r = m;
    }
    printf("%d\n", l);
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