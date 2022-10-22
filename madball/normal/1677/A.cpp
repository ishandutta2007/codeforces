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

const int MAXN = 5005;
struct Fenvick
{
    int ar[MAXN];
    void add(int i)
    {
        for (; i < MAXN; i += (i + 1) & -(i + 1))
            ++ar[i];
    }
    int get(int i)
    {
        int res = 0;
        for (; i >= 0; i -= (i + 1) & -(i + 1))
            res += ar[i];
        return res;
    }
    void clear()
    {
        memset(ar, 0, sizeof(ar));
    }
} tree1, tree2;

int ar[MAXN];
void solve()
{
    int n;
    cin >> n;
    For(i, n)
    {
        cin >> ar[i];
        --ar[i];
    }
    tree1.clear();
    lint res = 0;
    for (int i = 1; i < n; ++i)
    {
        tree1.add(ar[i - 1]);
        tree2.clear();
        for (int j = n - 2; j > i; --j)
        {
            tree2.add(ar[j + 1]);
            res += (lint)tree1.get(ar[j]) * tree2.get(ar[i]);
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
    int t;
    cin >> t;
    For(i, t)
        solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}