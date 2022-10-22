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

int read()
{
    int mul = 1;
    char c;
    while (true)
    {
        c = getchar();
        if (c == '-')
            mul = -1;
        if ('0' <= c && c <= '9')
            break;
    }
    int res = c - '0';
    while (true)
    {
        c = getchar();
        if (!('0' <= c && c <= '9'))
            return res * mul;
        res = res * 10 + c - '0';
    }
}

int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int ar[1000000];

void solve()
{
    int n = read();
    int m = read();
    For(i, n)
        ar[i] = read();
    int g = 0;
    For(i, m)
    {
        g = gcd(g, read());
    }
    lint res1 = 0, res2 = 0;
    For(i, g)
    {
        int cnt = 0;
        int mn = (int)1e9;
        lint s = 0;
        for (int j = i; j < n; j += g)
        {
            cnt += ar[j] < 0;
            mn = min(mn, abs(ar[j]));
            s += abs(ar[j]);
        }
        if (cnt % 2 && g > 1)
            s -= mn * 2ll;
        res1 += s;
    }
    For(i, g)
        ar[i] = -ar[i];
    For(i, g)
    {
        int cnt = 0;
        int mn = (int)1e9;
        lint s = 0;
        for (int j = i; j < n; j += g)
        {
            cnt += ar[j] < 0;
            mn = min(mn, abs(ar[j]));
            s += abs(ar[j]);
        }
        if (cnt % 2 && g > 1)
            s -= mn * 2ll;
        res2 += s;
    }
    printf("%lld\n", max(res1, res2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = read();
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}