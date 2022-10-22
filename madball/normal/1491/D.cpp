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

bool slow(unsigned int a, unsigned int b, int c = 29, int d = 29)
{
    if (a == b)
        return true;
    if (a > b)
        return false;
    if (c >= 0 && slow(a, b, c - 1, c - 1))
        return true;
    if ((a & (1u << d)) && slow(a + (1u << d), b, c, d + 1))
        return true;
    return false;
}

bool fast(unsigned int a, unsigned int b)
{
    if (a > b)
        return false;
    unsigned int mask = 0;
    for (int i = 29; i >= 0; --i)
    {
        mask |= 1u << i;
        unsigned int mask2 = mask;
        for (int j = i; j <= 29; ++j)
        {
            if ((a & (1u << j)) && (a & mask2) != (b & mask2) && a + (1u << j) <= b)
                a += 1u << j;
            mask2 ^= 1u << j;
        }
    }
    return a == b;
}

void solve()
{
    unsigned int a, b;
    cin >> a >> b;
    bool res = fast(a, b);
#ifdef LOCAL
    bool s_res = slow(a, b);
    if (s_res)
        cout << "YES ";
    else
        cout << "NO ";
    if (res != s_res)
        throw;
#endif
    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    For(i, q)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}