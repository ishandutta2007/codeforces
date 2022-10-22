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

const int MAXN = (int)1e5 + 5;
const lint INF = (lint)1e18 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;
    int i0 = -1, j0 = -1, val = -1000000007;
    For(i, n) For(j, m)
    {
        int a;
        cin >> a;
        if (a > val)
        {
            val = a;
            i0 = i;
            j0 = j;
        }
    }
    int w = max(i0 + 1, n - i0);
    int h = max(j0 + 1, m - j0);
#ifdef LOCAL
    cout << w << ' ' << h << ' ';
#endif
    cout << w * h << '\n';
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