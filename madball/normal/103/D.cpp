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

const int MAXN = (int)3e5 + 10;
int ar[MAXN];
lint ans[MAXN];

struct Query
{
    int a, b, id;
    Query() {}
    bool operator < (const Query& other) const
    {
        if (b != other.b)
            return b < other.b;
        if ((a % b) != (other.a % other.b))
            return (a % b) < (other.a % other.b);
        return a < other.a;
    }
    bool eq(const Query& other) const
    {
        return b == other.b && (a % b) == (other.a % other.b);
    }
} queries[MAXN];

int read()
{
    char c;
    while (true)
    {
        c = getchar();
        if ('0' <= c && c <= '9')
            break;
    }
    int res = c - '0';
    while (true)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
            return res;
        res = res * 10 + (c - '0');
    }
}


void solve()
{
    int n = read();
    For(i, n)
        ar[i] = read();
    reverse(ar, ar + n);
    int q = read();
    For(i, q)
    {
        queries[i].a = n - read();
        queries[i].b = read();
        queries[i].id = i;
#ifdef LOCAL
        lint cur = 0;
        for (int j = queries[i].a; j >= 0; j -= queries[i].b)
            cur += ar[j];
        printf("%lld%c", cur, (i + 1 == q ? '\n' : ' '));
#endif
    }
    sort(queries, queries + q);
    for (int l = 0, r = 1; l < q; l = r++)
    {
        while (r < q && queries[l].eq(queries[r]))
            ++r;
        int ptr = l;
        lint cur = 0;
        for (int i = queries[l].a % queries[l].b; i < n; i += queries[l].b)
        {
            cur += ar[i];
            while (ptr < r && queries[ptr].a == i)
            {
                ans[queries[ptr].id] = cur;
                ++ptr;
            }
        }
    }
#ifdef LOCAL
    For(i, q)
        printf("%lld ", ans[i]);
#else
    For(i, q)
        printf("%lld\n", ans[i]);
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