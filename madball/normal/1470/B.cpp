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

const lint MOD = (lint)1e15 + 159;
const lint PRIME = (lint)1e6 + 3;

lint add(lint a, lint b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

lint mul(lint a, lint b)
{
#ifdef LOCAL
    return (a * b) % MOD;
#else
    return ((__int128)a * (__int128)b) % MOD;
#endif
}

lint doit(int x)
{
    lint res = 0;
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            x /= i;
            int cnt = 1;
            while (x % i == 0)
            {
                x /= i;
                ++cnt;
            }
            if (cnt % 2)
                res = add(mul(res, PRIME), i);
        }
    }
    if (x > 1)
        res = add(mul(res, PRIME), x);
    return res;
}

unordered_map<lint, int> cnt;

void solve()
{
    int n;
    scanf("%d", &n);
    cnt.clear();
    cnt[0] = 0;
    For(i, n)
    {
        int a;
        scanf("%d", &a);
        lint b = doit(a);
        auto it = cnt.find(b);
        if (it == cnt.end())
            cnt[b] = 1;
        else
            ++it->second;
    }
    int res0 = 0, res1 = 0, add0 = 0;
    for (auto e : cnt)
    {
        res0 = max(res0, e.second);
        if (e.first && e.second % 2 == 0)
            add0 += e.second;
    }
    cnt[0] += add0;
    res1 = cnt[0];
    for (auto e : cnt)
        if (e.second % 2)
            res1 = max(res1, e.second);
    int q;
    scanf("%d", &q);
    For(i, q)
    {
        int a;
        scanf("%d", &a);
        if (a == 0)
            printf("%d\n", res0);
        else
            printf("%d\n", res1);
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
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}