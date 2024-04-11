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

const int MAXN = (int)2e5 + 5;
char inp[MAXN];
char ar[MAXN];

#ifdef LOCAL
#define STRESS_GEN
mt19937 rng(42);
#endif

int c = 0;

void solve()
{
    int n;
#ifdef STRESS_GEN
    n = rng() % 3 + 3;
#else
    scanf("%d", &n);
#endif
    For(i, n)
    {
        int a;
#ifdef STRESS_GEN
        a = rng() % 2;
#else
        scanf("%d", &a);
#endif
        ar[i + 1] = a;
    }
    copy(ar + 1, ar + n + 1, inp);
    For(i, n)
        ar[i + 1] ^= ar[i];
    if (ar[n] != 0)
    {
#ifndef STRESS_GEN
        printf("NO\n");
#endif
        return;
    }
    vector<int> ans;
    for (int i = 2; i + 2 <= n; i += 2)
        if (ar[i + 1] != 0 && ar[i - 1] == 0)
        {
            ans.emplace_back(i);
            ar[i + 1] = ar[i - 1];
            ar[i] = ar[i + 2];
        }
    for (int i = 1; i + 2 <= n; i += 2)
        if (ar[i + 1] != 0 && ar[i - 1] == 0)
        {
            ans.emplace_back(i);
            ar[i + 1] = ar[i - 1];
            ar[i] = ar[i + 2];
        }
    for (int i = n - 3; i >= 1; i -= 2)
        if (ar[i] != 0 && ar[i + 2] == 0)
        {
            ans.emplace_back(i);
            ar[i + 1] = ar[i - 1];
            ar[i] = ar[i + 2];
        }
    for (int i = n - 2; i >= 1; i -= 2)
        if (ar[i] != 0 && ar[i + 2] == 0)
        {
            ans.emplace_back(i);
            ar[i + 1] = ar[i - 1];
            ar[i] = ar[i + 2];
        }


    For(i, n + 1)
        if (ar[i])
        {
#ifndef STRESS_GEN
            printf("NO\n");
#endif
            return;
        }
    ++c;
#ifndef STRESS_GEN
    printf("YES\n%d\n", sz(ans));
    if (!ans.empty())
        For(i, sz(ans))
            printf("%d%c", ans[i], (i + 1 == sz(ans) ? '\n' : ' '));
#endif
#ifdef LOCAL
    copy(inp, inp + n, ar);
    for (auto e : ans)
    {
        char x = ar[e - 1] ^ ar[e] ^ ar[e + 1];
        ar[e - 1] = ar[e] = ar[e + 1] = x;
    }
    bool succ = sz(ans) <= n;
    For(i, n)
        succ &= !ar[i];
    if (!succ)
    {
        printf("FUCK\n%d\n", n);
        For(i, n)
            printf("%d%c", ar[i], (i + 1 == n ? '\n' : ' '));
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
    int t;
    scanf("%d", &t);
    For(i, t)
        solve();
#ifdef LOCAL
    printf("%d\n", c);
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}